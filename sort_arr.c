#include "push_swap.h"

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n)
{
    int i;
    int j;
    bool swapped;

    while(i < n - 1)
    {
        swapped = false;
        while(j > n - i - 1)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
    }
    if(swapped == false)
        break;
}