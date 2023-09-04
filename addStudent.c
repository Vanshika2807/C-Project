#include <stdio.h>
#include <string.h>
#include "add.h"

int addStudent(struct Student students[], int numStudents, int rollNumber, const char *name, float cgpa, const char *courses) {

    struct Student newStudent;
    newStudent.rollNumber = rollNumber;
    strcpy(newStudent.name, name);
    newStudent.cgpa = cgpa;
    strcpy(newStudent.courses, courses);

    students[numStudents] = newStudent;

    printf("Student added successfully.\n");
    return numStudents+1;
}


// Function to delete a student from the array
int deleteStudent(struct Student students[], int numStudents, int rollNumber) {

    if(numStudents == 0){
		printf("there are no students present\n");
	return numStudents;
    }

    int foundIndex = -1;

    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < numStudents - 1; i++) {
            students[i] = students[i + 1];
        }
        printf("Student deleted successfully.\n");
        return numStudents - 1;
    } else {
        printf("Student not found.\n");
        return numStudents;
    }
}



bool displayStudentsByCourse(struct Student students[], int numStudents, char ch[]){

	bool flag=false;
	for (int i = 0; i < numStudents; i++) {
        	if (strcmp(students[i].courses, ch) == 0) {
                    printf("Roll Number: %d  ", students[i].rollNumber);
                    printf("Name: %s  ", students[i].name);
                    printf("CGPA: %.2f  ", students[i].cgpa);
		    printf("\n");
                    flag = true;
        	}
    	}
    return flag;
}



// Function to display all students in the array
void displayAllStudent(struct Student students[], int numStudents) {
	if(numStudents==0){
        printf("no student to display\n");
        return;
        }
	printf("List of students:\n");
    	for (int i = 0; i < numStudents; i++) {
        printf("Roll Number: %d  ", students[i].rollNumber);
        printf("Name: %s  ", students[i].name);
        printf("CGPA: %.2f  ", students[i].cgpa);
        printf("Courses: %s  ", students[i].courses);
        printf("\n");
    }
}


// Function to sort students based on their roll numbers
void sortByRoll(struct Student students[], int numStudents) {

    if(numStudents == 0){
	printf("no student is there\n");
	return ;
    }

    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].rollNumber > students[j + 1].rollNumber) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by Roll Number.\n");
}


// Function to search student by roll number
int searchByRoll(struct Student students[], int numStudents, int rollNumber) {

    if(numStudents == 0){
	return 0;
    }

    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            return i;
        }
    }
    return -1; // Not found
}


// Function to sort students based on their names
void sortByName(struct Student students[], int numStudents) {
    
    if(numStudents == 0){
	printf("no student is there\n");
	return;
    }

    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by Name.\n");
}

// Function to search student by name
int searchByName(struct Student students[], int numStudents, const char *name) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Not found
}

float calculateAverage(struct Student students[], int n) {
    if (n == 0) {
        return 0.0;
    } else {
        return (students[n - 1].cgpa + (n - 1) * calculateAverage(students, n - 1)) / n;
    }
}


