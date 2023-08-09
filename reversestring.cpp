#include<stdio.h>
int main()
{
	int n,i,j;
	printf("Enter the value to be reversed : ");
	scanf("%d",&n);
	while(n!=0)
	{
		i=n%10;
		j=j*10+i;
		n=n/10;
	}
	printf("The reversed integer is %d",j);
	return 0;
}