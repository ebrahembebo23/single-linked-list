	// call libiraries
#include <stdio.h>
#include <stdlib.h>
	// define struct
struct Node
{
   int data;
   struct Node *next;
}
*front = NULL,*rear = NULL;
	// make function to insert items to list
void insert(int value)
{
   struct Node *newNode;
   newNode = (struct Node*) malloc(sizeof(struct Node));
   newNode->data = value;
   newNode -> next = NULL;
   if(front == NULL)
      front = rear = newNode;
   else{
      rear -> next = newNode;
      rear = newNode;
   }
   printf("Insertion is Success!!!\n\n");
}
	// make function to delete first item in the list
void delete_f()
{
   if(front == NULL)
      printf("\nlist already Empty!!!\n\n");
   else{
      struct Node *temp = front;
      front = front -> next;
      printf("\nDeleted element: %d\n\n", temp->data);
      free(temp);
   }
}
	// make function to display items in list
void display()
{
   if(front == NULL)
      printf("\nlist already Empty!!!\n\n");
   else{
      struct Node *temp = front;
      while(temp->next != NULL){
	 printf("%d - ",temp->data);
	 temp = temp -> next;
      }
      printf("%d - NULL\n",temp->data);
   }
}

int main()
{
   int choice, value;
   while(1){
      printf("Please enter your choise from next menu. \n\n");
      printf("1. Insert item\n2. Delete item\n3. Display all items in list\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: 
	 	printf("Enter the value to be insert: ");
		 scanf("%d", &value);
		 insert(value);
		 break;
	 case 2: 
		 delete_f();
	 	break;
	 case 3: 
	 	display(); 
	 	break;
	 case 4:
	 	return 0;
	 default: 
	 	printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
}


