#include<stdio.h>
#include<string.h>

void str_rev(char *str) 
{
    int i = 0, j = 0;
    char c;
    int strLength;

    strLength = strlen(str);

    if (strLength == 0 || strLength == 1)
        return;

    for (i = 0, j = strLength - 1; j > i; i++, j--) 
    {
        c = str[j];
        str[j] = str[i];
        str[i] = c;
    }
}

int main(int argc, char *argv[])
{
    char str[20];

    printf("Enter any string: ");
    scanf("%s", str);

    printf("Given String is %s\n", str);
    str_rev(str);
    printf("Reversed string is %s\n", str);

    return 0;
}