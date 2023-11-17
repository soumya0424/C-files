/*4.1 Write a program to create a single linked list of n nodes and perform the following menu based operations on it using function:
i. Insert a node at specific position
ii. Deletion of an element from specific position
iii. Count nodes
iv. Traverse the linked list*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertNode(struct Node **head, int element, int position) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Node inserted\n");
        return;
    }

    struct Node *temp = *head;
    for (int i = 0; i < position - 2; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted\n");
}

void deleteNode(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;

    if (position == 1) {
        *head = temp->next;
        free(temp);
        printf("Node deleted\n");
        return;
    }

    for (int i = 0; temp != NULL && i < position - 2; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
    printf("Node deleted\n");
}

int countNodes(struct Node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void traverseList(struct Node *head) {
    printf("The list is: ");
    while (head != NULL) {
        printf("%d-> ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int nodes, choice, element, position;

    printf("Enter number of nodes: ");
    scanf("%d", &nodes);
    printf("Enter the elements: ");
    for (int i = 0; i < nodes; i++) {
        scanf("%d", &element);
        insertNode(&head, element, i + 1);
    }

    do {
        printf("MENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Count\n");
        printf("4. Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                printf("Enter position: ");
                scanf("%d", &position);
                insertNode(&head, element, position);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteNode(&head, position);
                break;
            case 3:
                printf("The total number of nodes: %d\n", countNodes(head));
                break;
            case 4:
                traverseList(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}

/*4.2 In addition to 4.1, perform following operations using function on the single linked list:
i. search an element in the list
ii. sort the list in ascending order
iii. reverse the list*/
int searchElement(struct Node *head, int element) {
    int position = 1;
    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->data == element) {
            return position;
        }
        position++;
        temp = temp->next;
    }
    return -1;
}
void sortList(struct Node *head) {
    struct Node *current = head;
    struct Node *index = NULL;
    int temp;

    if (head == NULL) {
        return;
    } else {
        while (current != NULL) {
            index = current->next;

            while (index != NULL) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}
void reverseList(struct Node **head) {
    struct Node *temp = NULL;
    struct Node *current = *head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}
//4.3 Write a program to represent the polynomial equation of single variable using single linked list and perform the addition of two polynomial equations.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int power;
    struct Node *next;
};

void displayPolynomial(struct Node *head) {
    while (head != NULL) {
        printf("%dx^%d ", head->coefficient, head->power);
        head = head->next;
        if (head != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    int degree, coeff, pwr;
    struct Node *head = NULL;
    struct Node *temp = NULL;

    printf("Enter the Maximum power of x: ");
    scanf("%d", &degree);

    for (int i = degree; i >= 0; i--) {
        printf("Enter coefficient of degree %d: ", i);
        scanf("%d", &coeff);

        if (coeff != 0) {
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->coefficient = coeff;
            newNode->power = i;
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
                temp = head;
            } else {
                temp->next = newNode;
                temp = newNode;
            }
        }
    }

    displayPolynomial(head);

    return 0;
}

