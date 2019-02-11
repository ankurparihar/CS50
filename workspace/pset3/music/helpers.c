// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int x = fraction[0] - '0';
    int y = fraction[2] - '0';
    return (8 * x) / y;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int distance;
    // char ch = note[0];
    int k;
    // int flag=0;
    if (note[1] == '#')
    {
        // printf("# is there\n");
        // flag=1;
        switch (note[0])
        {
            case 'C':
                distance = -8;
                break;
            case 'D':
                distance = -6;
                break;
            case 'F':
                distance = -3;
                break;
            case 'G':
                distance = -1;
                break;
            case 'A':
                distance = 1;
                // break;
                // case 'B'
                //     distance = -8;
                //     break;
        }
        k = note[2] - '0';
        // printf("first_dist k: %d %d\n",distance,k);
    }
    else if (note[1] == 'b')
    {
        // printf("# is there\n");
        // flag=1;
        switch (note[0])
        {
            case 'D':
                distance = -8;
                break;
            case 'E':
                distance = -6;
                break;
            case 'G':
                distance = -3;
                break;
            case 'A':
                distance = -1;
                break;
            case 'B':
                distance = 1;
                // break;
                // case 'B'
                //     distance = -8;
                //     break;
        }
        k = note[2] - '0';
        // printf("first_dist k: %d %d\n",distance,k);
    }
    else
    {
        switch (note[0])
        {
            case 'C':
                distance = -9;
                break;
            case 'D':
                distance = -7;
                break;
            case 'E':
                distance = -5;
                break;
            case 'F':
                distance = -4;
                break;
            case 'G':
                distance = -2;
                break;
            case 'A':
                distance = 0;
                break;
            case 'B':
                distance = 2;
                // break;
        }
        k = note[1] - '0';
        // printf("first_dist k: %d %d\n",distance,k);
    }
    distance += (k - 4) * 12;
    // printf("distance: %d\n",distance);
    return round(pow(2, ((double)distance / 12)) * 440);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    return false;
}