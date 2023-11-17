//7.1 Write a menu driven program to create a linear queue using array and perform Enqueue, Dequeue, Traverse, IsEmpty, IsFull operations
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int element) 
{
    if (rear == MAX_SIZE - 1) 
	{
        printf("Queue Overflow: Cannot enqueue element.\n");
    }
	 else 
	{
        if (front == -1) 
		{
            front = 0;
        }
        rear++;
        queue[rear] = element;
        printf("%d enqueued into the queue.\n", element);
    }
}

void dequeue() 
{
    if (front == -1) 
	{
        printf("Queue Underflow: Cannot dequeue element.\n");
    } 
	else
	 {
        printf("Element deleted.\n");
        if (front == rear) 
		{
            front = rear = -1;
        } 
		else 
		{
            front++;
        }
    }
}

int is_empty() 
{
    return front == -1;
}

int is_full() 
{
    return rear == MAX_SIZE - 1;
}

void traverse() 
{
    if (is_empty())
	 {
        printf("Queue is empty.\n");
    } 
	else 
	{
        printf("Queue: ");
        for (int i = front; i <= rear; i++) 
		{
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() 
{
    int choice, element;

    while (1)
	 {
        printf("Main Menu\n1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. IsFull\n5. Traverse\n6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Queue empty: %s\n", is_empty() ? "True" : "False");
                break;
            case 4:
                printf("Queue full: %s\n", is_full() ? "True" : "False");
                break;
            case 5:
                traverse();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

//7.2 Write a menu driven program to implement linear queue operations such as Enqueue, Dequeue,  IsEmpty, Traverse using single linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
 {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int element) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = element;
    new_node->next = NULL;

    if (rear == NULL) 
	{
        front = rear = new_node;
    } else
	 {
        rear->next = new_node;
        rear = new_node;
    }

    printf("%d enqueued into the queue.\n", element);
}

void dequeue() 
{
    if (front == NULL) 
	{
        printf("Queue Underflow: Cannot dequeue element.\n");
    } else 
	{
        struct Node* temp = front;
        printf("Element deleted.\n");
        front = front->next;
        free(temp);

        if (front == NULL)
		 {
            rear = NULL;
        }
    }
}

int is_empty() 
{
    return front == NULL;
}

void traverse()
 {
    if (is_empty()) 
	{
        printf("Queue is empty.\n");
    } 
	else 
	{
        printf("Queue: ");
        struct Node* current = front;
        while (current != NULL) 
		{
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() 
{
    int choice, element;

    while (1) 
	{
        printf("Main Menu\n1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. Traverse\n5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice)
		 {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Queue empty: %s\n", is_empty() ? "True" : "False");
                break;
            case 4:
                traverse();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

//7.3 Write a menu driven program to implement circular queue operations such as Enqueue, Dequeue, Traverse, IsEmpty, IsFull using array
#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int element)
 {
    if ((rear + 1) % MAX_SIZE == front)
	 {
        printf("Queue Overflow: Cannot enqueue element.\n");
    }
	 else 
	 {
        if (front == -1) 
		{
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = element;
        printf("%d enqueued into the queue.\n", element);
    }
}

void dequeue()
 {
    if (front == -1) 
	{
        printf("Queue Underflow: Cannot dequeue element.\n");
    } 
	else
	 {
        printf("Element deleted.\n");
        if (front == rear)
		 {
            front = rear = -1;
        } 
		else 
		{
            front = (front + 1) % MAX_SIZE;
        }
    }
}

int is_empty()
 {
    return front == -1;
}

int is_full() 
{
    return (rear + 1) % MAX_SIZE == front;
}

void traverse()
 {
    if (is_empty()) 
	{
        printf("CQueue is empty.\n");
    } 
	else 
	{
        printf("CQueue: ");
        if (front <= rear)
		 {
            for (int i = front; i <= rear; i++)
			 {
                printf("%d ", queue[i]);
            }
        } 
		else 
		{
            for (int i = front; i < MAX_SIZE; i++)
			 {
                printf("%d ", queue[i]);
            }
            for (int i = 0; i <= rear; i++) 
			{
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    }
}

int main()
 {
    int choice, element;

    while (1)
	 {
        printf("Main Menu\n1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. IsFull\n5. Traverse\n6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice)
		 {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("CQueue empty: %s\n", is_empty() ? "True" : "False");
                break;
            case 4:
                printf("CQueue full: %s\n", is_full() ? "True" : "False");
                break
            case 5:
                traverse();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

