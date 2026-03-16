/*Implement Heap Sort using a Max Heap to sort an array in ascending order. 
First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.
*/
#include <stdio.h>

// Swap two numbers
void swap(int *a,int *b) 
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

// Max-heapify: make sure subtree rooted at i is a max heap
void maxHeapify(int arr[],int n,int i) 
{
    int largest=i;
    int l=2*i+1; // left child
    int r=2*i+2; // right child

    if (l<n && arr[l]>arr[largest])
        largest=l;
    if (r<n && arr[r]>arr[largest])
        largest=r;

    if (largest!=i) 
    {
        swap(&arr[i],&arr[largest]);
        maxHeapify(arr,n,largest);
    }
}

// Build max heap from array
void buildMaxHeap(int arr[],int n)
{
    for (int i=n/2-1;i>=0;i--)
    {
        maxHeapify(arr, n, i);
    }
}

// Heap sort
void heapSort(int arr[], int n) 
{

    // Step 1: Build max heap
    buildMaxHeap(arr,n);

    // Step 2: Extract max one by one
    for (int i=n-1;i>=1;i--) 
    {
        // Move current root to end
        swap(&arr[0],&arr[i]);
        // Heapify reduced heap
        maxHeapify(arr, i, 0);
    }
}

// Print array
void printArray(int arr[],int n) 
{
    for (int i=0;i<n;i++) 
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

// Driver code
int main() 
{
    int arr[]={12, 11, 13, 5, 6, 7};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr,n);

    heapSort(arr,n);

    printf("Sorted array: ");
    printArray(arr,n);

    return 0;
}