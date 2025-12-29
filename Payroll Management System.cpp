#include <stdio.h>
#include <string.h>

#define MAX 50   // Maximum number of employees

// Structure to store employee data
struct Employee {
    int id;                 // Employee ID
    char name[30];          // Employee name
    float basic;            // Basic salary
    float allowance;        // Allowance
    float deduction;        // Deduction
    float grossPay;         // Gross pay (Basic + Allowance)
    float netSalary;        // Net salary (Gross - Deduction)
};

struct Employee emp[MAX];   // Array of employees
int count = 0;              // Employee counter

// Function to calculate gross pay
float calculateGrossPay(float basic, float allowance) {
    return basic + allowance;
}

// Function to calculate net salary
float calculateNetSalary(float grossPay, float deduction) {
    return grossPay - deduction;
}

// Function to add employee
void addEmployee() {

    if (count >= MAX) {
        printf("\n\tEmployee limit reached!\n");
        return;
    }

    printf("\n\t\tEnter Employee ID: ");
    scanf("%d", &emp[count].id);

    printf("\t\tEnter Name: ");
    scanf(" %[^\n]", emp[count].name);

    printf("\t\tEnter Basic Salary: ");
    scanf("%f", &emp[count].basic);

    printf("\t\tEnter Allowance: ");
    scanf("%f", &emp[count].allowance);

    printf("\t\tEnter Deduction: ");
    scanf("%f", &emp[count].deduction);

    // Calculate gross pay
    emp[count].grossPay = calculateGrossPay(
        emp[count].basic,
        emp[count].allowance
    );

    // Calculate net salary
    emp[count].netSalary = calculateNetSalary(
        emp[count].grossPay,
        emp[count].deduction
    );

    count++;
    printf("\tEmployee added successfully!\n");
}

// Function to view employees
void viewEmployee() {
    int i;

    if (count == 0) {
        printf("\nNo record found!\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("\n\t----------------------------");
        printf("\n\t\tID: %d", emp[i].id);
        printf("\n\t\tName: %s", emp[i].name);
        printf("\n\t\tBasic Salary: %.2f", emp[i].basic);
        printf("\n\t\tAllowance: %.2f", emp[i].allowance);
        printf("\n\t\tGross Pay: %.2f", emp[i].grossPay);
        printf("\n\t\tDeduction: %.2f", emp[i].deduction);
        printf("\n\t\tNet Salary: %.2f\n", emp[i].netSalary);
    }
}

// Function to update employee
void updateEmployee() {
    int id, i;

    printf("\n\tEnter Employee ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (emp[i].id == id) {

            printf("\t\tEnter New Basic Salary: ");
            scanf("%f", &emp[i].basic);

            printf("\t\tEnter New Allowance: ");
            scanf("%f", &emp[i].allowance);

            printf("\t\tEnter New Deduction: ");
            scanf("%f", &emp[i].deduction);

            // Recalculate gross and net salary
            emp[i].grossPay = calculateGrossPay(
                emp[i].basic,
                emp[i].allowance
            );

            emp[i].netSalary = calculateNetSalary(
                emp[i].grossPay,
                emp[i].deduction
            );

            printf("\tEmployee updated successfully!\n");
            return;
        }
    }

    printf("\tEmployee not found!\n");
}

// Function to delete employee
void deleteEmployee() {
    int id, i, j;

    printf("\n\t\tEnter Employee ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (emp[i].id == id) {

            for (j = i; j < count - 1; j++) {
                emp[j] = emp[j + 1];
            }

            count--;
            printf("\tEmployee deleted successfully!\n");
            return;
        }
    }

    printf("Employee not found!\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n\t--- Payroll Management System ---\n");
        printf("\n\t\t1. Add Employee");
        printf("\n\t\t2. View Employee");
        printf("\n\t\t3. Update Employee");
        printf("\n\t\t4. Delete Employee");
        printf("\n\t\t5. Exit");
        printf("\n\n\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployee(); break;
            case 3: updateEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: printf("\n\tExiting Program...\n"); break;
            default: printf("\n\tInvalid Choice!\n");
        }
    } while (choice != 5);

    return 0;
}

