// Array Operations

#include<stdio.h>
#include<conio.h>

//Display the elements:---

void displayArray(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}


//Insert the value at specific  position :-------------

void insertArray(int arr[],int size,int value,int place)
{
  int i;
   if(place<=size)
   {
	 for(i=size; i>=place; i--)
	{
		arr[i+1] = arr[i];
		arr[place-1] = value;
	 }
   }
   else
    {
	printf("Array Overflow \n");
    }
}

//Function Of deletion of Array:------------

void deleteArray(int arr[],int size,int posEle)
{
	int i;
	if(posEle>size)
	{
		printf("deletion is not possible");
	}
	else
	{
		for(i=posEle;i<size;i++)
		{
			arr[i]=arr[i+1];
		}
	}
}

// Searching methods with sorting technique:-----
void linearSearch(int arr[], int size,int findNum)
	{
	       int i;
	       displayArray(arr,size);
		for(i=0;i<size;i++)
		{
		  if(findNum==arr[i])
		  {
			printf("%d is available on index number %d ",findNum ,arr[i] );
		  }
		}

	}
void binarySearch(int arr[], int size,int findNum)
{
       int i =0;
       int mid;
       int low=arr[i];
       int high=arr[size-1];
       for(i=0;i<size-1;i++)
       {
		mid=(low+high)/2;
		if(mid==findNum)
		{
			printf("%d is find in the index of %d .",findNum, mid);
			break;
		}
		if(findNum>mid)
		{
			mid=low;
		}
		else
		{
			findNum =high;
		}
       }


}
//Searching method call here----

void searchArray(int arr[],int size)
{
	int sChoice,findNum;
	printf("Enter the element  you find : ");
	scanf("%d",&findNum);
	printf("\n1: Linear Search sorting ");
	printf("\n2: Binary Search sorting ");
	printf("\n3: Exit");
	while(1)
	{
		printf("\n Enter your choice ");
		scanf("%d",&sChoice);

		switch(sChoice)
		{
		case 1:linearSearch(arr,size,findNum);
			break;
		case 2:binarySearch(arr,size,findNum);
			break;
		case 3:exit(0);
		}
	}

}

// Main function start with switch statement:-----

void main()
{
  int arr[20];
  int size=0;
  int choice;
  int i;
  int value;
  int place;
  int posEle;
  clrscr();

//take the size of temp working array_

  printf("Enter size of array:");
  scanf("%d",&size);

//take the elements to the working array by user_

  for(i=0 ; i<size; i++)
  {
	printf("Enter the elements: ");
	scanf("%d",&arr[i]);
  }
//to display the choices_

   printf("\n1:Display");
   printf("\n2:Insert ");
   printf("\n3:Delete ");
   printf("\n4:Search");
   printf("\n5:exit ");

//while loop for continuation asking of choice

  while(1)
  {

	printf("\n Enter the choice:");
	scanf("%d",&choice);

	switch(choice){
		case 1:displayArray(arr,size);
			 break;

		case 2:
			 printf("Enter the value you want to insert :");
			 scanf("%d",&value);
			 printf("Enter the place:");
			 scanf("%d",&place);
			insertArray(arr,size,value,place);
			 break;
		case 3:
			printf("enter the position of elment , want to delete ");
			scanf("%d",&posEle);
			deleteArray(arr,size,posEle);
			size -= 1;
			break;
		case 4:searchArray(arr,size);
			break;
		case 5:exit(0);
		default:printf("Invalid choice");
	      }
      }
}