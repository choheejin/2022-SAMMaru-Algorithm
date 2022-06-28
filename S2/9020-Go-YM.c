#include <stdio.h>
#define SIZE 10000

int checkNum(int num)
{
	for(int i=2;i<num;i++)
	{
		if(num%i==0)
		{
			return 0;
		}
	}

	return 1;
}

int main(void)
{
	int num;
	scanf("%d",&num);
	int data[SIZE];
	int a,b=0;

	for(int i=0;i<num;i++)
	{
		scanf("%d",&data[i]);
	}

	//2로나눈다음에 하나씩 증가 감소하며 비교하므로 제일처음 나온값이
	//두수의 차가 제일 작은 값이 됨
	for(int j=0;j<num;j++)
	{
		a=data[j]/2;
		b=data[j]/2;

		while(!(checkNum(a)==1&&checkNum(b)==1))
		{
			a++;
			b--;
		}
		if(a>b)
		{
			int temp=a;
			a = b;
			b = temp;
		}
		printf("%d %d\n",a,b);
	}

	return 0;
}