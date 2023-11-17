/*2.1 WAP to create a 1-D array of n elements and perform the following menu based operations using function.
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array*/
#include <stdio.h>

void insertElement(int arr[], int *size, int element, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position to insert\n");
        return;
    }

    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    (*size)++;
    printf("Element inserted\n");
}

void deleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position to delete\n");
        return;
    }

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("Element deleted\n");
}

int linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

void traverseArray(int arr[], int size) {
    printf("Array Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter size n: ");
    scanf("%d", &n);

    int array[100]; // Adjust the size accordingly

    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int choice, element, position, searchElement, searchIndex;

    do {
        printf("\n***MENU***\n");
        printf("1. Insert\n2. Delete\n3. Linear Search\n4. Traverse\n5. Exit\nEnter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Element to insert: ");
                scanf("%d", &element);
                printf("Enter Position: ");
                scanf("%d", &position);
                insertElement(array, &n, element, position);
                break;
            case 2:
                printf("Enter Position: ");
                scanf("%d", &position);
                deleteElement(array, &n, position);
                break;
            case 3:
                printf("Element to search: ");
                scanf("%d", &searchElement);
                searchIndex = linearSearch(array, n, searchElement);
                if (searchIndex != -1) {
                    printf("Element found at position %d\n", searchIndex);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 4:
                traverseArray(array, n);
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

/*2.2 Write a program to perform the following operations on a given square matrix using functions:
i.   Find the no.of nonzero elements
ii.  Display upper triangular matrix
iii. Display the elements of just above and below the main diagonal*/
#include <stdio.h>

void countNonZero(int matrix[][100], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    printf("Nonzero elements: %d\n", count);
}

void displayUpperTriangular(int matrix[][100], int size) {
    printf("Upper triangular matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i <= j) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void displayDiagonal(int matrix[][100], int size) {
    printf("Elements above and below main diagonal:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == i - 1 || j == i + 1) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter size of the square matrix: ");
    scanf("%d", &size);

    int matrix[100][100]; // Adjust the size accordingly

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    countNonZero(matrix, size);
    displayUpperTriangular(matrix, size);
    displayDiagonal(matrix, size);

    return 0;
}

//2.3 WAP to represent a given sparse matrix in 3-tuple format using 2-D array.
#include <stdio.h>

void displaySparseMatrix(int sparseMatrix[][3], int rows) {
    printf("Sparse matrix in 3-tuple format:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", sparseMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix[100][100]; // Adjust the size accordingly

    printf("Enter elements of sparse matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sparseMatrix[100][3]; // Adjust the size accordingly
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    displaySparseMatrix(sparseMatrix, k);

    return 0;
}

