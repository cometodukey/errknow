#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errknow.h"

#define lengthof(x) (sizeof(x) / sizeof(*(x)))

static void unknown_value(const char *name)
{
    fprintf(stderr, "errknow: Unknown value: %s\n", name);
}

static int get_value_from_name(const char *name, unsigned long *errnum)
{
    for (size_t i = 0; i < lengthof(errno_names); i++)
    {
        if (errno_names[i] == NULL)
        {
            continue;
        }
        if (strcmp(name, errno_names[i]) == 0)
        {
            *errnum = i;
            return 0;
        }
    }

    return -1;
}

static void errknow(const char *string)
{
    const char *name = NULL;
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
        if (get_value_from_name(name, &errnum) == -1)
        {
            unknown_value(string);
            return;
        }
    }
    else
    {
        /* The entire string could be parsed as a number, so index the table to get the name */
        if (errnum >= lengthof(errno_names))
        {
            unknown_value(string);
            return;
        }
        name = errno_names[errnum];
    }

    if (name == NULL)
    {
        unknown_value(string);
        return;
    }

    const char *description = strerror(errnum);

    printf("%d %s %s\n", (int)errnum, name, description);
}

int main(int argc, const char **argv)
{
    /* Skip argv[0] */
    int count = --argc;
    const char **strings = ++argv;

    if (count == 0)
    {
        /* Show everything */
        count = lengthof(errno_names);
        strings = errno_names;
    }

    for (int i = 0; i < count; i++)
    {
        errknow(strings[i]);
    }

    return EXIT_SUCCESS;
}
