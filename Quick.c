
#include <stdio.h>

int a[50];

void quicksort(int low, int high)
{
    int pivot, i, j, temp;

    if (low < high)
    {
        pivot = a[low];
        i = low + 1;
        j = high;

        while (i <= j)
        {
            while (i <= high && a[i] <= pivot)
                i++;

            while (a[j] > pivot)
                j--;

            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[low];
        a[low] = a[j];
        a[j] = temp;

        quicksort(low, j - 1);
        quicksort(j + 1, high);
    }
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    quicksort(0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
