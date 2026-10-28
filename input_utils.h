#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <stdio.h>

static inline void input_discard_line(void)
{
    int character;
    while ((character = getchar()) != '\n' && character != EOF)
    {
    }
}

#endif
