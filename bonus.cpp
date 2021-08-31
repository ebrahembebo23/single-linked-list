#include <stdio.h>
#include <stdlib.h>
 
 // define struct of queue
struct node {
    int data;
    struct node *next;
} *front, *back;
 
// function Create a queue 
void initialize() {
    front = back = NULL;
}
 
// function Returns queue size 
int getQueueSize() {
    struct node *temp = front;
    int count = 0;
     
    if(front == NULL && back == NULL)
        return 0;
 
    while(temp != back){
        count++;
        temp = temp->next;
    }
    if(temp == back)
        count++;
         
    return count;
}
 
// function Returns Front Element of the Queue
int getFrontElement() {
    return front->data;
}
 
// function Returns the Rear Element of the Queue
int getBackElement() {
    return back->data;
}
 

// Check if Queue is empty or not 
void isEmpty() {
    if (front == NULL && back == NULL)
        printf("Empty Queue\n");
    else
        printf("Queue is not Empty\n");
}
// add element function
void enqueue(int num) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;
     
    if (back == NULL) {
        front = back = temp;
    } else {
        back->next = temp;
        back = temp;
    }
}
 
// ewmove element function
void dequeue() {
    struct node *temp;
    if (front == NULL) {
        printf("\nQueue is Empty \n");
        return;
    } else {
        temp = front;
        front = front->next;
        if(front == NULL){
            back = NULL;
        }
        printf("Removed Element : %d\n", temp->data);
        free(temp);
    }
}
  
	// print function
void printQueue() {
    struct node *temp = front;
  
    if ((front == NULL) && (back == NULL)) {
        printf("Queue is Empty\n");
        return;
    }
 
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
        if(temp != NULL)
            printf("--> ");
            
    }
    printf("--> NULL");
}
 
int main() {
    // Initializing Queue
    initialize();
    // Add elements in Queue
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    // Print Queue
    printQueue();
    // Print size of Queue
    printf("\nSize of Queue : %d\n", getQueueSize());
    // Print front and rear element of Queue
    printf("Front Element : %d\n", getFrontElement());
    printf("Rear Element : %d\n", getBackElement());
    // Remove Elementd from Queue
    dequeue();
    dequeue();
    dequeue();
    dequeue();  
    
		// if deleate all elements print you Queue is empty 
		
    /*dequeue();
    dequeue();*/
     
    return 0;
}
