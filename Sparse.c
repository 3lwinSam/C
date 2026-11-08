#include <stdio.h>

int main()
{
    int A[50][3], B[50][3], C[100][3];
    int i, j, k;

    printf("Enter the number of rows, columns and non-zero elements of Matrix A:\n");
    scanf("%d%d%d", &A[0][0], &A[0][1], &A[0][2]);

    printf("Enter the triplet form of Matrix A (row column value):\n");
    for(i = 1; i <= A[0][2]; i++)
    {
        scanf("%d%d%d", &A[i][0], &A[i][1], &A[i][2]);
    }

    printf("Enter the number of rows, columns and non-zero elements of Matrix B:\n");
    scanf("%d%d%d", &B[0][0], &B[0][1], &B[0][2]);

    printf("Enter the triplet form of Matrix B (row column value):\n");
    for(i = 1; i <= B[0][2]; i++)
    {
        scanf("%d%d%d", &B[i][0], &B[i][1], &B[i][2]);
    }

    /* Check matrix order */
    if(A[0][0] != B[0][0] || A[0][1] != B[0][1])
    {
        printf("Matrix addition not possible.\n");
        return 0;
    }

    /* Copy rows and columns */
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    i = j = k = 1;

    while(i <= A[0][2] && j <= B[0][2])
    {
        if(A[i][0] == B[j][0])     // Same row
        {
            if(A[i][1] == B[j][1]) // Same column
            {
                int sum = A[i][2] + B[j][2];

                if(sum != 0)
                {
                    C[k][0] = A[i][0];
                    C[k][1] = A[i][1];
                    C[k][2] = sum;
                    k++;
                }
                i++;
                j++;
            }
            else if(A[i][1] < B[j][1])
            {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = A[i][2];
                i++;
                k++;
            }
            else
            {
                C[k][0] = B[j][0];
                C[k][1] = B[j][1];
                C[k][2] = B[j][2];
                j++;
                k++;
            }
        }
        else if(A[i][0] < B[j][0])
        {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++;
            k++;
        }
        else
        {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++;
            k++;
        }
    }

    /* Copy remaining elements of A */
    while(i <= A[0][2])
    {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++;
        k++;
    }

    /* Copy remaining elements of B */
    while(j <= B[0][2])
    {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++;
        k++;
    }

    C[0][2] = k - 1;

    printf("\nResultant Sparse Matrix (Triplet Form):\n");
    printf("Row\tCol\tValue\n");

    for(i = 0; i <= C[0][2]; i++)
    {
        printf("%d\t%d\t%d\n", C[i][0], C[i][1], C[i][2]);
    }

    return 0;
}
