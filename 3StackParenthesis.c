#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    printf("Enter Expression : ");
    gets(str);
    char stack[100];
    int top=-1,i,len,flag=0;
    len=strlen(str);
    for (i=0;i<len;i++)
    {
        if (str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            top++;
            stack[top]=str[i];
        }
        else if (str[i]==')' || str[i]=='}' || str[i]==']')
        {
            char ch = stack[top];
            if (ch=='[')
                ch=']';
            else if (ch=='{')
                ch='}';
            else
                ch=')';
            if (ch == str[i])
            {
                top--;
            }
            else
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0)
    {
        printf("Balanced");
    }
    else
    {
        printf("Not balanced");
    }
    return 0;
}