#include <stdio.h>
#include "Ohce.h"

// function prototypes
void reverseStr (char *str);
int echoCheck (char *str);

int main (int argc, char **argv)
{

    // flag for when there is 'echo'
    int isThereEcho = 0;
    int i;

    for (i = 1; i < argc; i++)
    {
        // check for echo if flag is set to false; sets flag to 1
        if (isThereEcho == 0)
            isThereEcho = echoCheck(argv[i]);

        reverseStr(argv[i]);

        // when the last argument is reached, print a new line, else print a space
        if (i == argc - 1)
            printf("\n");
        else
            printf(" ");
    }

    // if flag was set to 1, print message
    if (isThereEcho)
        printf("Echo, echo, echo!\n");


    return 0;
} // end of main


// recursive function to print string backwards character by character
void reverseStr (char *str)
{
    if (*str != '\0')
    {
        reverseStr(str + 1);
        printf("%c", *str);
    }
} // end of reverseStr


// check if the char array passed in contains the word 'echo' -- case insensitive
int echoCheck (char *str)
{
    int i = 0;
    int j = 0;

    // while loop to check character by character for case variations of 'echo'
    while (str[j] != '\0')
    {
        i = j;

        if (str[i] == 'e' || str[i] == 'E')
        {
            i++;

            if (str[i] == 'c' || str[i] == 'C')
            {
                i++;

                if (str[i] == 'h' || str[i] == 'H')
                {
                    i++;

                    if (str[i] == 'o' || str[i] == 'O')
                    {
                        return 1;
                    }
                }
            }
        }

        j++;
    }

    return 0;
} // end of echoCheck


// output: this function should not print anything to the screen
// return value: a double indicating how difficult you found this assignment on a scale of 1.0
//  (ridiculously easy) through 5.0 (insanely difficult)
double difficultyRating(void)
{
    return 3.5;
}

// output: this function should not print anything to the screen
// return value: A reasonable estimate (greater than zero) of the number of hours you spent
//  on this assignment
double hoursSpent(void)
{
    return 8.0;
}

