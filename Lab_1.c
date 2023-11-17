//1.1 Write a program to read two numbers and compare the numbers using function call by address.
#include <stdio.h>
void compareNumbers(int *num1, int *num2) {
    if (*num1 > *num2) {
        printf("%d is greater than %d\n", *num1, *num2);
    } else if (*num2 > *num1) {
        printf("%d is greater than %d\n", *num2, *num1);
    } else {
        printf("Both numbers are the same\n");
    }
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    compareNumbers(&num1, &num2);

    return 0;
}

//1.2 Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of all the prime elements of the array using function and de-allocate the memory of the array after its use.
#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int sumOfPrimes(int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (isPrime(array[i])) {
            sum += array[i];
        }
    }
    return sum;
}

int main() {
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed");
        return -1;
    }

    printf("Enter array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    int sum = sumOfPrimes(array, size);
    printf("Sum = %d\n", sum);

    free(array);

    return 0;
}

//1.3 Write a program to create a structure to store the information of n number of Employees. Employee’s information includes data members: Emp-id, Name, Designation, basic_salary, hra%, da%. Display the information of employees with gross salary. Use array of structure
#include <stdio.h>

struct Employee {
    int emp_id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra_percentage;
    float da_percentage;
};

void displayEmployeeInfo(struct Employee emp) {
    printf("\nName: %s\n", emp.name);
    printf("Designation: %s\n", emp.designation);
    printf("Basic Salary: %.2f\n", emp.basic_salary);
    printf("HRA %%: %.2f\n", emp.hra_percentage);
    printf("DA %%: %.2f\n", emp.da_percentage);
    float gross_salary = emp.basic_salary + (emp.basic_salary * emp.hra_percentage / 100) + (emp.basic_salary * emp.da_percentage / 100);
    printf("Gross Salary: %.2f\n", gross_salary);
}

int main() {
    int n;
    printf("Enter no. of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    for (int i = 0; i < n; i++) {
        printf("Enter employee %d information:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Designation: ");
        scanf("%s", employees[i].designation);
        printf("Basic Salary: ");
        scanf("%f", &employees[i].basic_salary);
        printf("HRA %%: ");
        scanf("%f", &employees[i].hra_percentage);
        printf("DA %%: ");
        scanf("%f", &employees[i].da_percentage);
    }

    printf("\nEmployee Information:\n");

    for (int i = 0; i < n; i++) {
        displayEmployeeInfo(employees[i]);
    }

    return 0;
}

/*1.4 Write a menu driven program to create a structure to represent complex number and perform the following operation using function :
1. addition of two complex number  (call by value)
2. multiplication of two complex number (call by address)*/
#include <stdio.h>

struct Complex {
    float real;
    float imaginary;
};

void addComplex(struct Complex c1, struct Complex c2) {
    printf("Sum = %.2f + %.2fi\n", c1.real + c2.real, c1.imaginary + c2.imaginary);
}

void multiplyComplex(struct Complex *c1, struct Complex *c2) {
    float real = c1->real * c2->real - c1->imaginary * c2->imaginary;
    float imaginary = c1->real * c2->imaginary + c1->imaginary * c2->real;
    printf("Product = %.2f + %.2fi\n", real, imaginary);
}

int main() {
    struct Complex complex1, complex2;
    printf("Enter complex number 1: ");
    scanf("%f %f", &complex1.real, &complex1.imaginary);
    printf("Enter complex number 2: ");
    scanf("%f %f", &complex2.real, &complex2.imaginary);

    int choice;
    printf("\nMENU\n1. Addition\n2. Multiplication\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addComplex(complex1, complex2);
            break;
        case 2:
            multiplyComplex(&complex1, &complex2);
            break;
        default:
            printf("Invalid choice");
    }

    return 0;
}

