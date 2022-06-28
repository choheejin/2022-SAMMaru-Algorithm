#include <stdio.h>
#define MAX 100000

int arr[MAX];
//해당 수를 pop 했는지 확인하는 배열 pop 했을시 1 아닐시0
int pop_arr[MAX];
char cor_arr[2*MAX+1];
int top=0;

void push()
{
    cor_arr[top] = '+';
    top++;
}

void pop(int key)
{
    pop_arr[key] = 1;
    cor_arr[top] = '-';
    top++;
}

int main(void)
{
    int num;
    scanf("%d",&num);

    int check = 1;

    for(int i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
        pop_arr[i] = 0;
    }

    for(int j=0;j<num;j++)
    {
        if(j==0)
        {
            for(int x=1;x<arr[j]+1;x++)
            {
                push();
            }
            pop(arr[j]-1);
        }

        else
        {
            if(arr[j]>arr[j-1])
            {
                for(int x=arr[j-1];x<arr[j]+1;x++)
                {
                    if(pop_arr[x-1]==0)
                    {
                        push();
                    }
                }

                pop(arr[j]-1);
            }

            //arr[j-1]>arr[j] 인경우
            else
            {
                for(int x=arr[j-1];x>arr[j];x--)
                {
                    if(pop_arr[x-1]==0)
                    {
                        check = 0;
                        break;
                    }
                }

                pop(arr[j]-1);
            }
        }

        if(check==0)
        {
            break;
        }
    }

    if(check==1)
    {
        for(int k=0;k<top;k++)
        {
            printf("%c\n",cor_arr[k]);
        }
    }

    else
    {
        printf("NO\n");
    }

    return 0;
}