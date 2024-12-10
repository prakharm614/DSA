#include<stdio.h>

void main()
{
    int m, n, p, q, i, k, j, sum, mul[50][50], a[50][50], b[50][50];

    printf("Enter rows of the first matrix: ");
    scanf("%d", &m);
    printf("Enter columns of the first matrix: ");
    scanf("%d", &n);
    printf("Enter rows of the second matrix: ");
    scanf("%d", &p);
    printf("Enter columns of the second matrix: ");
    scanf("%d", &q);

    if (n != p)
    {
        printf("Multiplication does not exist.\n");
    }
    else
    {
        printf("Enter elements of the first matrix:\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        printf("Enter elements of the second matrix:\n");
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < q; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < q; j++)
            {
                sum = 0; 
                for (k = 0; k < p; k++)
                {
                    sum += a[i][k] * b[k][j];
                }
                mul[i][j] = sum;
            }
        }

        printf("Matrix after multiplication:\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < q; j++)
            {
                printf("%d\t", mul[i][j]);
            }
            printf("\n");
        }
    }
}
