#include "fun.h"
#include <iostream>
unsigned int faStr1(const char* str)
{
    int i = 0, count = 0, state = 'a';
    bool f = false;
    while (str[i] != '\0' && str[i] != '\n')
    {
        if (state == 'a' && str[i] != ' ')
        {
            state = 'b';
            if (int(str[i]) > 47 && int(str[i]) < 58) f = true;
            else f = false;
        }
        else if (state == 'b' && str[i] != ' ') { if (int(str[i]) > 47 && int(str[i]) < 58) f = true; }
        else if (state == 'b' && str[i] == ' ')
        {
            state = 'a';
            if (!f) count++;
        }
        if (state == 'b' && (str[i + 1] == '\n' || str[i + 1] == '\0')) count++;
        i++;
    }
    return count;
}

unsigned int faStr2(const char* str)
{
    int i = 0, count = 0, state = 'a';
    bool f = false;
    while (str[i] != '\0' && str[i] != '\n')
    {
        if (state == 'a' && str[i] != ' ')
        {
            state = 'b';
            if (int(str[i]) > 64 && int(str[i]) < 91) f = false; else f = true;
        }
        else if (state == 'b' && str[i] != ' ') { if (int(str[i]) < 97 || int(str[i]) > 122) f = true; }
        else if (state == 'b' && str[i] == ' ')
        {
            state = 'a';
            if (!f) count++;
        }
        if (state == 'b' && (str[i + 1] == '\n' || str[i + 1] == '\0')) count++;
        i++;
        i++;
    }
    return count;
}

unsigned int faStr3(const char* str)
{
    int i = 0, state = 'a';
    double  count = 0, countc = 0;
    while (str[i] != '\0' && str[i] != '\n')
    {
        if (state == 'a' && str[i] != ' ')
        {
            state = 'b';
            count++;
            countc++;
        }
        else if (state == 'b' && str[i] != ' ')
        {
            countc++;
        }
        else if (state == 'b' && str[i] == ' ')
        {
            state = 'a';
        }
        i++;
    }
    return round(countc / count);
}
