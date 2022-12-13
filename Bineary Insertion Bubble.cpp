/*
#include <stdio.h>
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        if (arr[mid] == x)
            return mid;
 
        
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
 
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if(result == -1)
    {
        printf("Element is not present in array");
    }
    else
    {
        printf("Element is present at index %d", result);
    }
     
    return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	int n, list[10], i, j, k, temp;
	
	printf("Enter the size of list: ");
	scanf("%d", &n);
	
	printf("Enter the elements for the list: ");
	for(i=0; i<n; i++)
	{
	   scanf("%d", &list[i]);
    }
    
    for(j=0; j<n-1; j++)
    {
    	for(k=0; k<n-j-1; k++)
    	if(list[k]>list[k+1])
        {
		temp = list[k+1];
		list[k+1] = list[k];
		list[k] = temp;
	    }
	}
	for(i=0; i<n; i++)
	{
		printf("%d \t", list[i]);
	}
	return 0;
}
*/

#include<stdio.h>
void print(){
    int i;
    int a[10]={1,3,5,7,9,2,4,6,8,10};
    for(i=0;i<10;i++){
        printf("%d,",a[i]);

}}
int main(){
  int  a[10]={1,3,5,7,9,2,4,6,8,10};
  int t,n=10,i,j;

  for(i=1;i<n;i++){
    t=a[i];
    for(j=i-1;j>=0;j--){
        if(t>a[j]){
            a[j+1]=a[j];
        }
        else{
            break;
        }
    }
        if(j<0)
        {
            a[0]=t;
        }
        else{
            a[j+1]=t;
        }
    
    }
  print();
    
}
