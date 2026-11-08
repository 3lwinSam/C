#include <stdio.h>

void read_poly(int p[][2], int n);
void display_poly(int p[][2], int n);
void add_poly(int a[][2], int b[][2], int m, int n);

int main()
{
    int p1[20][2], p2[20][2];
    int m, n;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &m);

    printf("Enter the coefficient and exponent (in descending order of exponents):\n");
    read_poly(p1, m);

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);

    printf("Enter the coefficient and exponent (in descending order of exponents):\n");
    read_poly(p2, n);

    printf("\nFirst Polynomial:\n");
    display_poly(p1, m);

    printf("\nSecond Polynomial:\n");
    display_poly(p2, n);

    printf("\nResultant Polynomial:\n");
    add_poly(p1, p2, m, n);

    return 0;
}

/* Function to read a polynomial */
void read_poly(int p[][2], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("Term %d\n", i + 1);

        printf("Coefficient : ");
        scanf("%d", &p[i][0]);

        printf("Exponent    : ");
        scanf("%d", &p[i][1]);
    }
}

/* Function to display a polynomial */
void display_poly(int p[][2], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%dx^%d", p[i][0], p[i][1]);

        if(i != n - 1)
            printf(" + ");
    }
    printf("\n");
}

/* Function to add two sparse polynomials */
void add_poly(int a[][2], int b[][2], int m, int n)
{
    int c[40][2];
    int i = 0, j = 0, k = 0;

    while(i < m && j < n)
    {
        if(a[i][1] == b[j][1])
        {
            c[k][0] = a[i][0] + b[j][0];
            c[k][1] = a[i][1];
            i++;
            j++;
            k++;
        }
        else if(a[i][1] > b[j][1])
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            i++;
            k++;
        }
        else
        {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            j++;
            k++;
        }
    }

    while(i < m)
    {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        i++;
        k++;
    }

    while(j < n)
    {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        j++;
        k++;
    }

    display_poly(c, k);
}
