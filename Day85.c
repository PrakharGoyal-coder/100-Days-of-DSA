/*Problem: Implement Merge Sort - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64
*/
#include <stdio.h>

int b[100]; // temporary array

void merge(int a[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;

    while (i <= mid && j <= ub)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    // remaining elements left side
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }

    // remaining elements right side
    while (j <= ub)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    // copy back to original array
    for (int i = lb; i <= ub; i++)
    {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;

        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

int main()
{
    int n, a[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}