#include <stdio.h>
#include <string.h>

#define TRUE 0
#define FALSE 1

int count[256];

int checkForPerm(char *str1, char *str2)
{
    int strlen1 = 0, strlen2 = 0;
    int c, i;

    strlen1 = strlen(str1);
    strlen2 = strlen(str2);

    if (strlen1 != strlen2)
        return FALSE;

    for (i = 0; i < strlen1; i++)
    {
        c = (int) str1[i];
        count[c]++;
    }

    for (i = 0; i < strlen1; i++)
    {
        c = (int) str2[i];
        if (--count[c] < 0)
            return FALSE;
    }

    return TRUE;
}

int main(int argc, char *argv[])
{
    char str1[20], str2[20];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    if(!checkForPerm(str1, str2))
        printf("Yes they are anagrams\n");
    else
        printf("No they are not anagrams\n");

    return 0;
}