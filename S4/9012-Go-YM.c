#include <stdio.h>
#include <string.h>

char stack[51];
int top = 0;

int main(void)
{
    int num;
    scanf("%d",&num);
    char pare[51];
    int check;

    for(int i=0;i<num;i++)
    {
        top = 0;
        check = 1;
        scanf("%s",&pare);

        for(int j=0;j<strlen(pare);j++)
        {
            if(pare[j]=='(')
            {
                stack[top] = '(';
                top++;
            }

            else
            {   
                if(top>0)
                {
                    top--;
                }

                else
                {
                    check = 0;
                    break;
                }
            }
        }

        if((top == 0)&&(check==1))
        {
            printf("YES\n");
        }

        else
        {
            printf("NO\n");
        }
    }

    return 0;
}