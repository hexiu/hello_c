#include<stdio.h>

int main()
{
	int a[2][2]={1,2,3,4};
	int b[2][2]={2,1,3,2};
	int c[2][2]={0};
	int i=0,j=0,k=0;
	
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			c[i][j]=0;
			for(k=0;k<2;k++)
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
		}
	}
		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
				printf("--%d --\n",c[i][j]);	
	
		

}
