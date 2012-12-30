#include <stdio.h>
#include <stdlib.h>

void setZero(int *mat[], int m, int n)
{
    int i = 0, j = 0;
    int row[m];
    int col[n];

    for (i = 0; i < m; i++)
        row[i] = 0;

    for (i = 0; i < n; i++)
        col[i] = 0;

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if(mat[i][j] == 0) 
            {
                row[i] = 1;
                col[j] = 1;
            }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (row[i] || col[j])
                mat[i][j] = 0;
        }
    }

}



int main(int argc, char *argv[])
{
    int m, n, i = 0, j = 0;
    int *mat[10];

    printf("Enter the row size: ");
    scanf("%d", &m);

    printf("Enter the column size: ");
    scanf("%d", &n);

    for (i = 0; i < m; i++)
        mat[i] = (int *)malloc(n * sizeof(int));

    printf("Enter matrix elements: ");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    printf("The matrix entered is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("Setting zeroes in the matrix......\n");

    setZero(mat, m, n);

    printf("The resultant matrix is:\n");

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++)
        free(mat[i]);
}