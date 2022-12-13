//multiplication using american way
#include<stdio.h>
using namespace std;
int main()
{
	int a=981;
	int b=1234,temp,count=0;
	temp=b;
	while(temp!=0)
	{
		temp=temp/10;
		count++;
	}
	printf("%d\n",count);
	int c=1,d,i;
	int res=0;
	for(i=0;i<count;i++)
	{
		d=b%10;
		b=b/10;
		res=res+a*d*c;
		c=c*10;
		d=d*10;
	}
	printf("result: %d",res);
}



//multiplication in english way
/*
#include<stdio.h>
#include<math.h>
int main()
{
	int n1=981,n2=1234,temp=n2,d,n,prod=0,count=0;
	while(temp!=0)
	{
		temp=temp/10;
		count++;
	}
	temp=n2;
	n=pow(10,count-1);
	while(temp!=0)
	{
		d=(n2%(n*10)-n2%n)/n;
		prod=prod+(d*n1*n);
		temp=temp/10;
		n=n/10;
	}
	printf("result: %d",prod);	
}
*/
//multiplication by unknown way
/*
#include<stdio.h>
int main()
{
	int n1=981;
	int n2=1234;
	int a,b,res=0,i;
	for(i=0;i<10;i++)
	{
		printf("%d",n1);
		printf("\t%d\n",n2);
		if(n1%2!=0)
		{
			res=res+n2;
		}
		n1=n1>>1;
		n2=n2<<1;
	}
	printf("result:%d",res);
	
}

