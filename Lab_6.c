/*6.1 Write a menu driven program to create a stack using array and perform the following operation using function
a. Push
b. Pop
c. check stack is empty or not
d. check stack is full or not
e. display stack elements*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;
void push(int element) 
{
    if (top == MAX_SIZE - 1) 
	{
        printf("Stack Overflow: Cannot push element.\n");
    } else
	 {
        top++;
        stack[top] = element;
        printf("%d pushed into the stack.\n", element);
    }
}

void pop() 
{
    if (top == -1) 
	{
        printf("Stack Underflow: Cannot pop element.\n");
    } else 
	{
        printf("%d deleted from Stack.\n", stack[top]);
        top--;
    }
}

int is_empty() 
{
    return top == -1;
}

int is_full() 
{
    return top == MAX_SIZE - 1;
}

void display() 
{
    if (is_empty()) 
	{
        printf("Stack is empty.\n");
    } else {
        printf("Stack: ");
        for (int i = 0; i <= top; i++) 
		{
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() 
{
    int choice, element;

    while (1) 
	{
        printf("Main Menu\n1. Push\n2. Pop\n3. IsEmpty\n4. IsFull\n5. Traverse\n6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice)
		 {
            case 1:
                printf("Enter element to be pushed into the stack: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Stack empty: %s\n", is_empty() ? "True" : "False");
                break;
            case 4:
                printf("Stack full: %s\n", is_full() ? "True" : "False");
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

/*6.2 Write a menu driven program to create a stack using linked list and perform the following operation using function
a. Push
b. Pop
c. IsEmpty
d. display the stack elements*/
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int element)
 {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = element;
    new_node->next = top;
    top = new_node;
    printf("%d pushed into the stack.\n", element);
}

void pop()
 {
    if (top == NULL) 
	{
        printf("Stack Underflow: Cannot pop element.\n");
    } else 
	{
        struct Node* temp = top;
        printf("%d deleted from Stack.\n", temp->data);
        top = top->next;
        free(temp);
    }
}

int is_empty()
 {
    return top == NULL;
}

void display() 
{
    if (is_empty()) 
	{
        printf("Stack is empty.\n");
    } else {
        printf("Stack: ");
        struct Node* current = top;
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
        printf("Main Menu\n1. Push\n2. Pop\n3. IsEmpty\n4. Traverse\n5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                printf("Enter element to be pushed into the stack: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Stack empty: %s\n", is_empty() ? "True" : "False");
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}


//6.3 Write a program to convert infix expression to postfix operation using stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack 
{
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* create_stack(unsigned capacity) 
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int is_empty(struct Stack* stack) 
{
    return stack->top == -1;
}

void push(struct Stack* stack, char element) 
{
    stack->array[++stack->top] = element;
}

char pop(struct Stack* stack)
 {
    if (!is_empty(stack))
        return stack->array[stack->top--];
    return '$';
}

int is_operand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch) 
{
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infix_to_postfix(char* infix_expression) 
{
    struct Stack* stack = create_stack(strlen(infix_expression));
    int i, j;

    for (i = 0, j = -1; infix_expression[i]; ++i) 
	{
        if (is_operand(infix_expression[i])) 
		{
            infix_expression[++j] = infix_expression[i];
        } else if (infix_expression[i] == '(')
		 {
            push(stack, infix_expression[i]);
        } else if (infix_expression[i] == ')')
		 {
            while (!is_empty(stack) && stack->array[stack->top] != '(')
			 {
                infix_expression[++j] = pop(stack);
            }
            if (!is_empty(stack) && stack->array[stack->top] != '(') 
			{
                printf("Invalid expression.\n");
                return;
            } else 
			{
                pop(stack);
            }
        }
		 else 
		 {
            while (!is_empty(stack) && precedence(infix_expression[i]) <= precedence(stack->array[stack->top])) 
			{
                infix_expression[++j] = pop(stack);
            }
            push(stack, infix_expression[i]);
        }
    }

    while (!is_empty(stack))
	 {
        infix_expression[++j] = pop(stack);
    }

    infix_expression[++j] = '\0';

    printf("Postfix: %s\n", infix_expression);
}

int main()
 {
    char infix_expression[MAX_SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix_expression);
    infix_to_postfix(infix_expression);
    return 0;
}

