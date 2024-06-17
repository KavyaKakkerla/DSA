
#include<stdio.h>
#include<limits.h>

int mcm(int a[],int i,int j)
{
	int val,k;
	if(i==j)
	return 0;
	else
	{
		int min=INT_MAX;
		for( k=i;k<j;k++)
		{
			val=mcm(a,i,k)+mcm(a,k+1,j)+a[i-1]*a[k]*a[j];
			if(min>val)
				min=val;
		}
		return min;
	}
}	
int main()
{
int n;
printf("\nenetr the number of matrices you want to mutlipty");
scanf("%d",&n);
int a[n+1];
printf("\nenetr the degree of the matrices");

for(int i=0;i<=n;i++)
{
	scanf("%d",&a[i]);
}
int min=mcm(a,1,n);
printf("\nThe minimum number of the operations are %d",min);
return 0;
}
