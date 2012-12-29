#include <stdio.h>
#include <string.h>

int checkForUnique(char *str)
{
    int i = 0, j = 0;

    if(strlen(str) == 0 || strlen(str) == 1)
        return 0;

    for (i = 0; i < strlen(str); i++)
    {
        for (j = i + 1; j < strlen(str); j++)
        {
            if(str[i] == str[j])
                return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    int result;
    char str[20];

    printf("Enter any string: ");
    scanf("%s", str);

    result = checkForUnique(str);

    if (result == 1)
    {
        printf("Sorry, string characters are not unique\n");
    }
    else
    {
        printf("Yesss !!! String characters are unique\n");
    }

    return 0;
}