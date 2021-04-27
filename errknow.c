#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errknow.h"

#define lengthof(x) (sizeof(x) / sizeof(*(x)))

static size_t levenshtein_distance(const char* s1, const char* s2,
                                   const size_t m, const size_t n)
{
    if (m == 0)
    {
        return n;
    }
    if (n == 0)
    {
        return m;
    }

    size_t costs[n + 1];

    for (size_t k = 0; k <= n; k++)
    {
        costs[k] = k;
    }

    for (size_t i = 0; s1[i]; i++)
    {
        const char c1 = s1[i];
        costs[0] = i + 1;
        size_t corner = i;
        for (size_t j = 0; s2[j]; j++)
        {
            const char c2 = s2[j];
            size_t upper = costs[j + 1];
            if (c1 == c2)
            {
                costs[j + 1] = corner;
            }
            else
            {
                size_t t = upper < corner ? upper : corner;
                costs[j + 1] = (costs[j] < t ? costs[j] : t) + 1;
            }

            corner = upper;

        }
    }

    return costs[n];
}

static inline size_t min(const size_t a, const size_t b)
{
    return a > b ? b : a;
}

static bool fuzzy_match(const char *str1, const char *str2,
                        const size_t min_len, const size_t max_distance)
{
    if (str1 == NULL || str2 == NULL)
    {
        return false;
    }

    const size_t str1_len = strlen(str1);
    const size_t str2_len = strlen(str2);

    /* The inputs to be matched cannot be less than 4 characters */
    if (str1_len < min_len || str2_len < min_len)
    {
        return false;
    }

    const size_t cmp_limit = min(str1_len, str2_len);

    /* If the starts of the strings are the same, consider it a match.
       Otherwise, compute the distance */
    if (strncmp(str1, str2, cmp_limit) == 0 ||
        levenshtein_distance(str1, str2, str1_len, str2_len) <= max_distance)
    {
        return true;
    }

    return false;
}

static void strtoupper(char *dst)
{
    char *src = dst;
    size_t len = strlen(src);

    for (size_t i = 0; i < len; i++)
    {
        dst[i] = toupper(src[i]);
    }
}

static void match_name(char **input, unsigned long *errnum, const bool fuzzy_match_strings)
{
    for (size_t i = 0; i < lengthof(errno_names); i++)
    {
        if (errno_names[i] == NULL)
        {
            continue;
        }
        if (strcmp(*input, errno_names[i]) == 0)
        {
            *errnum = i;
            return;
        }
    }

    /* No exact matches were found, so perfom fuzzy matching */
    if (fuzzy_match_strings == true)
    {
        fprintf(stderr, "%s was not found.", *input);

        /*  Normalise to uppercase for fuzzy matching.
            To avoid using VLA on user supplied strings, we write back to the input buffer.
            This is safe because:
                - The spec declares `argv` to point to writable strings
                - When no arguments are passed, it should be impossible for this code to be reached,
                  so string literals will not be modified */
        strtoupper(*input);

        /* Ensure that the buffer is large enough to hold all possible matches */
        static const char *matched_strings[lengthof(errno_names)];

        size_t count = 0;

        for (size_t i = 1; i < lengthof(errno_names) - 1; i++)
        {
            if (fuzzy_match(*input, errno_names[i], 4, 2) == true)
            {
                matched_strings[count++] = errno_names[i];
            }
        }

        if (count != 0)
        {
            /* List all matches */
            fprintf(stderr, " Did you mean; ");
            for (size_t i = 0; i < count; i++)
            {
                const char *prefix = "";
                if (i != 0)
                {
                    prefix = ", ";
                    if (i == count - 1)
                    {
                        prefix = " or ";
                    }
                }
                fprintf(stderr, "%s%s", prefix, matched_strings[i]);
            }
            fprintf(stderr, "?\n");
            *input = "";
            return;
        }
    }

    fputc('\n', stderr);

    *input = "";
}

static void errknow(char *string, const bool fuzzy_match_strings)
{
    char *name = NULL;
    char *end = NULL;
    unsigned long errnum = 0;

    if (string == NULL)
    {
        return;
    }

    errnum = strtoul(string, &end, 10);

    /* If we couldn't parse the entire string as a number, treat it as an error name */
    if (end[0] != '\0' || errnum == ULONG_MAX)
    {
        name = string;
        match_name(&name, &errnum, fuzzy_match_strings);
    }
    else
    {
        /* The entire string could be parsed as a number, so index the table to get the name */
        if (errnum >= lengthof(errno_names))
        {
            fprintf(stderr, "%s is out of range.\n", string);
            return;
        }
        name = errno_names[errnum];
    }

    if (name[0] == '\0')
    {
        return;
    }

    const char *description = strerror(errnum);

    printf("%d %s %s\n", (int)errnum, name, description);
}

int main(int argc, char **argv)
{
    /* Skip argv[0] */
    int count = --argc;
    char **strings = ++argv;
    bool fuzzy_match_strings = true;

    if (count == 0)
    {
        /* Show everything */
        count = lengthof(errno_names);
        strings = errno_names;
        fuzzy_match_strings = false;
    }

    for (int i = 0; i < count; i++)
    {
        errknow(strings[i], fuzzy_match_strings);
    }

    return EXIT_SUCCESS;
}
