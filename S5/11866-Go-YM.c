#include <stdio.h>
#define MAX 1000001

int queue[MAX];
int front=0;
int rear=0;

int pop()
{
	return queue[front++];
}

void push(int key)
{
	queue[rear++] = key;
}

int main(void)
{
	int num;
	int count;
	scanf("%d%d",&num,&count);

	for(int i=0;i<num;i++)
	{
		queue[i] = i+1;
		rear++;
	}

	printf("<");

	for(int j=0;j<num-1;j++)
	{
		for(int k=0;k<num;k++)
		{
			if(k+1==count)
			{
				printf("%d, ",pop());
				break;
			}

			else
			{
				push(pop());
			}
		}
	}

	printf("%d>",pop());

	return 0;
}