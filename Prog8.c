#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int isSubstring(char *str1, char *str2)
{
    int length1 = 0, length2 = 0, i = 0, j = 0, count = 0;
    char *temp = NULL;
    int dummy = 0;

    length1 = strlen(str1);
    length2 = strlen(str2);

    if(length1 != length2)
        return FALSE;

    temp = (char *)malloc(length1 * 2 * sizeof(char));
    strcpy(temp, str1);
    strcat(temp, str1);

    for (i = 0; i < length1 + 1; i++) {
        i = dummy;
        count = 0;
        for (j = 0; j < length1; j++) {
            if (temp[i++] == str2[j]) {
                count++;
                if (count == length1) {
                    free(temp);
                    return TRUE;
                }
            } else
                break;
        }
        dummy++;
    }
    return FALSE;
}

int main(int argc, char *argv[])
{
    char str1[20], str2[20];
    int result = 0;

    printf("Enter the main string:");
    scanf("%s", str1);

    printf("Enter the substring:");
    scanf("%s", str2);

    result = isSubstring(str1, str2);

    if(result)
        printf("Yesss!! they are substrings with rotation\n");
    else
        printf("Nope.. they are not substrings with rotation\n");

    return 0;
}