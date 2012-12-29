#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * insert(char * str, int length)
{
    int i = 0, j = 0, spaceCount = 0;

    if (length == 0)
        return str;

    for (i = 0; i < length; i++)
    {
        if (str[i] == ' ')
            spaceCount++;
    }

    if (spaceCount == 0)
        return str;

    int newLength = length + spaceCount * 3;

    char *newStr = (char *)malloc(newLength);

    for (i = 0, j = 0; i < length && j < newLength; i++)
    {
        if (str[i] == ' ')
        {
            newStr[j++] = '%';
            newStr[j++] = '2';
            newStr[j++] = '0';
        } else {
            newStr[j++] = str[i];
        }
    }
    newStr[j] = '\0';

    return newStr;
}

int main(int argc, char *argv[])
{
    char str[20];
    char *resultString;
    int length = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    length = strlen(str);

    resultString = insert(str, length);

    printf("Resultant string is %s", resultString);

    if(!(length == strlen(resultString)))
        free(resultString);

    return 0;
}