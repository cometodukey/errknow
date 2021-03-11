#define _GNU_SOURCE

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "errno_names.h"

#define LEN(x) ((sizeof(x)) / (sizeof(*x)))

void unknown_value(const char *name)
{
    fprintf(stderr, "errno: Unknown value: %s\n", name);
}

int get_value_from_name(const char *name, long *errnum)
{
    for (size_t i = 0; i < LEN(errno_names); i++)
    {
        if (strcasecmp(name, errno_names[i]) == 0)
        {
            *errnum = i;
            return 0;
        }
    }

    return -1;
}

void get_errno_info(const char *string)
{
    const char *name = NULL;
    const char *description = NULL;
    char *end = NULL;
    long errnum = 0;

    errnum = strtol(string, &end, 10);
    if (end != (string + strlen(string)) ||
        errnum == LONG_MIN ||
        errnum == LONG_MAX)
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
        name = strerrorname_np(errnum);
    }

    if (name == NULL)
    {
        unknown_value(string);
        return;
    }

    description = strerror(errnum);

    printf("%d %s %s\n", (int)errnum, name, description);
}

int main(int argc, const char **argv)
{
    int count = --argc;
    const char **strings = ++argv;

    if (count == 0)
    {
        /* Show everything */
        count = LEN(errno_names);
        strings = errno_names;
    }

    for (int i = 0; i < count; i++)
    {
        get_errno_info(strings[i]);
    }
    fflush(stdout);

    return 0;
}