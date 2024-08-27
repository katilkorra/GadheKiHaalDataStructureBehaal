//2. Stack operations :--------


#include<stdio.h>
int max =10;
int stack[10];
int top = -1;

void push(int ele)
{
	if(top == max-1)
	{
		printf("\n Stack is full, Cannot Pushed");
		return ;
	}
	stack[++top] = ele;
}

int pop()
{
	if(top == -1)
	{
		printf("Stack is empty");
		return -1;
	}
	return stack[top --];
}

void display()
{
	int i;
	for(i=0;i<=top ;i++)
	{
		printf("%d ",stack[i]);
	}
	printf("\n");
}



void main()
{
 int choice, ele,place;
 clrscr();
 while(1)
 {
	printf("\n1: Push ");
	printf("\n2: Pop ");
	printf("\n3: Display");
	printf("\n4: Exit");

	printf("\nEnter Your Choice: ");
	scanf("%d",&choice);

	switch(choice)
	{
	case 1:
		printf("\n Enter the Push element: ");
		scanf("%d",&ele);
		push(ele);
		break;
	case 2:
		ele = pop();
		if(ele != -1)
		{
			printf(" %d Popped \n ",ele);
		}
		break;
	case 3:
		display();
		break;
	case 4:
		exit();
	default:
		printf("Invalid Choice ");
	}
 }
}