//comb sort(2 sided sort)
#include <stdio.h>
#include <stdlib.h>
void SelectionSort(int* arr, int n)
{
    for (int i = 0, j = n - 1; i < j; i++, j--) 
    {
        int min = arr[i], max = arr[i];
        int min2 = i, max2 = i;
        for (int k = i; k <= j; k++) 
        {
            if (arr[k] > max) 
            {
                max = arr[k];
                max2 = k;
            } else if (arr[k] < min) {
                min = arr[k];
                min2 = k;
            }
        }
        int t1=arr[i];
        arr[i]=arr[min2];
        arr[min2]=t1;
 
        if (arr[min2] == max)
        {
            int t2=arr[j];
            arr[j]=arr[min2];
            arr[min2]=t2;
        }
        else
        {
            int t3=arr[j];
            arr[j]=arr[max2];
            arr[max2]=t3;
        }
    }
}
int main()
{
    int arr[] = { 23, 78, 45, 8, 32, 56, 1 ,100,99,44};
    int n = sizeof(arr) / sizeof(arr[0]);
    SelectionSort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
