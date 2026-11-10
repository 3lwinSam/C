
#include <stdio.h>

int a[50], temp[50];

void merge(int low, int mid, int high)
{
    int i, j, k;

    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    while(i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }

    while(j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }

    for(i = low; i <= high; i++)
    {
        a[i] = temp[i];
    }
}

void merge_sort(int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        merge_sort(low, mid);
        merge_sort(mid + 1, high);

        merge(low, mid, high);
    }
}

int main()
{
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    merge_sort(0, n - 1);

    printf("Sorted array: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
