#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * compress(char *str)
{
    int length = 0, compLength = 0, count = 0, i = 0, j = 0;
    char c;

    length = strlen(str);
    if(length == 0 || length == 1) return str;

    char *newStr = (char *)malloc(length * 2);

    for (i = 0, j = 0; i < length; i++)
    {
        c = str[i++];
        count++;

        while(str[i++] == c)
            count++;

        newStr[j++] = c;
        if(count < 10)
            newStr[j++] = (char)(count + '0');
        else {
            char buf[10];
            sprintf(buf, "%d", count);
            int l = strlen(buf);
            sprintf(&newStr[j], "%d", count);
            j = j + l;
        }


        count = 0;
        i = i - 2;
    }

    newStr[j] = '\0';
    compLength = strlen(newStr);

    if(compLength > length) return str;
    else  return newStr;
}

int main(int argc, char *argv[])
{
    char str[20];

    char *compStr;

    printf("Enter any sorted string : ");
    scanf("%s", str);

    compStr = compress(str);

    printf("Compressed string is %s\n", compStr);

    if (strlen(compStr) < strlen(str))
        free(compStr);

    return 0;
}