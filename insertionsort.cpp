#include<stdio.h>
void insert_sort(int a[],int size)
{
	int key;
	int i,j;
	
	
	for(i=1;i<size;i++) //here indexing startng from 0 here we will start comparisons from second element.
	{
		key=a[i];
		j=i-1;
		while(j>=0&&a[j]>key)
		{
			a[j+1]=a[j]; //j+1=i
			j=j-1;
		}
		a[j+1]=key;
	
	}
	for(i=0;i<size;i++)
	{
		printf("%d\t",a[i]);
	}
}
int main()
{
	int a[5],i;
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	insert_sort(a,5);
	return 0;
}
