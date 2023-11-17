//3.1 WAP to perform transpose of a given sparse matrix in 3-tuple format.
#include <stdio.h>

void displayTranspose(int sparseMatrix[][3], int rows) {
    printf("Transpose of sparse matrix:\nR  C  Element\n");
    for (int i = 0; i < rows; i++) {
        printf("%d  %d  %d\n", sparseMatrix[i][1], sparseMatrix[i][0], sparseMatrix[i][2]);
    }
}

int main() {
    int rows;
    printf("Enter the number of non-zero elements in the sparse matrix: ");
    scanf("%d", &rows);

    int sparseMatrix[100][3]; // Adjust the size accordingly

    printf("Enter sparse matrix in 3-tuple format:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &sparseMatrix[i][j]);
        }
    }

    displayTranspose(sparseMatrix, rows);

    return 0;
}

//3.2 WAP to perform addition of two given sparse matrix in 3–tuple format.
#include <stdio.h>

void displaySparseMatrix(int sparseMatrix[][3], int rows) {
    printf("Resultant Matrix in 3-tuple format:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", sparseMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, rows2;
    printf("Enter the number of non-zero elements in sparse matrix-1: ");
    scanf("%d", &rows1);

    int sparseMatrix1[100][3]; // Adjust the size accordingly

    printf("Enter sparse matrix-1 in 3-tuple format:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &sparseMatrix1[i][j]);
        }
    }

    printf("Enter the number of non-zero elements in sparse matrix-2: ");
    scanf("%d", &rows2);

    int sparseMatrix2[100][3]; // Adjust the size accordingly

    printf("Enter sparse matrix-2 in 3-tuple format:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &sparseMatrix2[i][j]);
        }
    }

    int resultMatrix[100][3]; // Adjust the size accordingly

    // Perform addition of the two matrices here

    displaySparseMatrix(resultMatrix, rows1 + rows2);

    return 0;
}

//3.3 WAP to represent the polynomial of single variable using 1-D array and perform the addition of two polynomial equations.
#include <stdio.h>

void displayPolynomial(int *polynomial, int degree) {
    printf("Resultant Polynomial: ");
    for (int i = degree; i >= 0; i--) {
        if (polynomial[i] != 0) {
            if (i > 0) {
                printf("%dx^%d", polynomial[i], i);
                if (i != 1) {
                    printf("+");
                }
            } else {
                printf("%d", polynomial[i]);
            }
        }
    }
    printf("\n");
}

int main() {
    int degree;
    printf("Enter maximum degree of x: ");
    scanf("%d", &degree);

    int poly1[10] = {0}; // Adjust the array size accordingly
    int poly2[10] = {0}; // Adjust the array size accordingly
    int sum[10] = {0};   // Adjust the array size accordingly

    printf("Enter Polynomial-1 from lowest degree to highest degree: ");
    for (int i = 0; i <= degree; i++) {
        scanf("%d", &poly1[i]);
    }

    printf("Enter Polynomial-2 from lowest degree to highest degree: ");
    for (int i = 0; i <= degree; i++) {
        scanf("%d", &poly2[i]);
    }

    for (int i = 0; i <= degree; i++) {
        sum[i] = poly1[i] + poly2[i];
    }

    displayPolynomial(sum, degree);

    return 0;
}

