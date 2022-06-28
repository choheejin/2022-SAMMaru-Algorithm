//Circular Queue사용하면 MAX_SIZE줄일수 있음
#include <stdio.h>

//MAX_SIZE를 500000이아닌 1000001로 해주어야함
#define MAX_SIZE 1000001

//MAX_SIZE 크기가 크기떄문에 지역변수가 아닌 전역변수로 선언 & 매개변수 줄이기
int data[MAX_SIZE];
int front,back = 0;
int size=0;

int pop()
{
	size--;
	return data[front++];
}

void push(int key)
{
	data[back++] = key;
	size++;
}

int main(void)
{
	int num;
	scanf("%d",&num);

	//1부터 num까지 카드 생성
	for(int i=0;i<num;i++)
	{
		push(i+1);
	}

	//queue에 정수가 1개 남을때까지 반복
	while(size!=1)
	{
		pop();
		push(pop());
	}

	printf("%d",data[front]);

	return 0;
}