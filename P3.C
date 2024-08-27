// 3. Double Stack Operations :------

#include <stdio.h>

int max =20;

int stack1[20];
int stack2[20];

int top1 = -1;
int top2 = -1;

void push1(int ele)
{
	if(top1 ==  max -1)
	{
		printf(" Stack1 is Full ");
		return;
	}
	stack1[++top1] = ele;
}
void push2(int ele)
{
	if(top2 == max -1)
	{
		printf(" Stack2  is Full ");
		return;
	}
	stack2[++top2] = ele;
}

int pop1()
{
       if(top1==-1)
       {
		printf("\n Stack1 is empty ");

       }
       return stack1[top1--];
}
int pop2()
{
	if(top2 == -1)
	{
		printf("\n Stack2 is empty ");
	}
	return stack2[top1--];
}
void display1()
{
  int i;
  for(i =0 ; i<=top1 ; i++)
  {
	printf("%d ", stack1[i]);
  }
  printf("\n");
}
void display2()
{
  int i;
  for(i=0; i<=top2 ; i++)
  {
	printf("%d ", stack2[i]);
  }
  printf("\n");
}
void main()
{
   int ele,choice;
   while(1)
   {
	printf("\n1: Push the Element in Stack 1 ");
	printf("\n2: Push the Element in Stack 2 ");
	printf("\n3: Pop the Element From Stack 1 ");
	printf("\n4: Pop the Element From Stack 2 ");
	printf("\n5: Display the Stack 1");
	printf("\n6: Display the Stack 2");
	printf("\n7: Exit ");
	printf("\n Enter the choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\n Enter the element in Stack 1 : ");
			scanf("%d",&ele);
			push1(ele);
			break;
		case 2:
			printf("\n Enter the elemnt in Stack 2 : ");
			scanf("%d",&ele);
			push2(ele);
			break;
		case 3:
		       ele=pop1();
		       if(ele != -1)
		       {
			printf("Popped element : %d \n",ele);
		       }
			break;
		case 4:
			ele=pop2();
			 if(ele != -1)
		       {
			printf("Popped element : %d \n",ele);
		       }
			break;
		case 5:
			display1();
			break;
		case 6:
			display2();
			break;
		case 7:
			exit();
		default:
			printf("\n you enter invalid choice ");
   }

}
}