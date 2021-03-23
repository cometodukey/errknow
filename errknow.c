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
    const char *description = NULL;
    char *end = NULL;
    unsigned long errnum = 0;

    errnum = strtoul(string, &end, 10);
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

    description = strerror(errnum);

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
        /* NULL pointers exist in the errno_names array so check that we aren't passing any */
        if (strings[i] != NULL)
        {
            errknow(strings[i]);
        }
    }

    return 0;
}
