#include <stdio.h>
#include <stdlib.h>

void rotate(int *mat[], int n)
{
    int layer = 0, first = 0, last = 0, temp = 0, i = 0;

    for (layer = 0; layer < n/2; layer++)
    {
        first = layer;
        last = n - 1 - first;

        for (i = first; i < last; i++)
        {
            temp = mat[first][i];
            mat[first][i] = mat[last - i][first];
            mat[last - i][first] = mat[last][last - i];
            mat[last][last - i] = mat[i][last];
            mat[i][last] = temp;
        }
    }
}

int main(int argc, char *argv[])
{
    int n, i = 0, j = 0;
    int *mat[10];

    printf("Enter the matrix size: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        mat[i] = (int *)malloc(n * sizeof(int));

    printf("Enter matrix elements: ");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    printf("The matrix entered is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("Rotating the matrix by 90deg......\n");

    rotate(mat, n);

    printf("The resultant matrix is:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++)
        free(mat[i]);
}