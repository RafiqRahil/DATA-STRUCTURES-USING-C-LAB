//stack implementation using array
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stack[SIZE];
int top=-1;
int isempty()
{
    return(top==-1)?1:0;
}
int isfull()
{
    return(top == SIZE-1)?1:0;
}
void push()
{
    if (isfull())
    {
        printf("Stack Overflow!!!");
    }
    else
    {
        top++;
        int val;
        printf("Enter Element:  ");
        scanf("%d",&val);
        stack[top]=val;
        printf("Element successfully Added");
    }
}
void show()
{
    if (isempty())
    {
        printf("Stack is Empty !!!");
    }
    else{
        int i;
        printf("Elements in stack are:-\n");
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
void pop()
{
    if (isempty())
    {
        printf("Stack Underflow !!!");
    }
    else{
        int val;
        val=stack[top];
        top--;
        printf("Element %d deleted from stack !!! ",val);
    }
}
int peek(){
    if (isempty())
    {
    return top;
    }
    else
    return stack[top];
    }
int main()
{
    while(1){
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. peek\n");
    printf("4. show\n");
    printf("5. exit\n");
    int choice,res;
    printf("Enter choice:  ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        push();
        break;
        case 2:
        pop();
        break;
        case 3:
        res = peek();
        if (res ==-1)
        printf("Stack is empty...");
        else
        printf("%d is available in the top of stack",res);
        break;
        case 4:
        show();
        break;
        case 5:
        exit(0);
        break;
        default:
        printf("Invalid Input !!!!");
        break;
    }
    printf("\n");
    system("pause");
    }
    return 0;
}