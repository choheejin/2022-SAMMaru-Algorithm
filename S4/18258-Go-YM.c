#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int num;
	scanf("%d",&num);
	char command[11];

	int* queue = (int*)malloc(sizeof(int)*num);
	int size=0;
	int front=0;
	int back=0;

	int temp;

	for(int i=0;i<num;i++)
	{
		scanf("%s", command);

		if(strcmp(command,"push")==0)
		{
			scanf("%d",&temp);
			queue[back] = temp;
			back++;
			size++;
		}

		else if(strcmp(command,"pop")==0)
		{
			if(size==0)
			{
				printf("%d\n",-1);
				continue;
			}
			printf("%d\n",queue[front]);
			front++;
			size--;
		}

		else if(strcmp(command,"front")==0)
		{
			if(size==0)
			{
				printf("%d\n",-1);
				continue;
			}
			printf("%d\n",queue[front]);
		}

		else if(strcmp(command,"back")==0)
		{
			if(size==0)
			{
				printf("%d\n",-1);
				continue;
			}
			printf("%d\n",queue[back-1]);
		}

		else if(strcmp(command,"size")==0)
		{
			printf("%d\n",size);
		}

		else if(strcmp(command,"empty")==0)
		{
			if(size==0)
			{
				printf("%d\n",1);
			}

			else
			{
				printf("%d\n",0);
			}
		}
	}

	free(queue);

	return 0;
}