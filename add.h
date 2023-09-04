

#include <stdbool.h>
#include <stdlib.h>
#define max_students 100

struct Student {
    int rollNumber;
    char name[50];
    float cgpa;
    char courses[100];
};


int addStudent(struct Student students[], int numStudents, int rollNumber, const char *name, float cgpa, const char *courses);

int deleteStudent(struct Student students[], int numStudents, int rollNumber);

bool displayStudentsByCourse(struct Student students[], int numStudents, char ch[]);

void displayAllStudent(struct Student students[], int numStudents);

void sortByRoll(struct Student students[], int numStudents);

int searchByRoll(struct Student students[], int numStudents, int rollNumber);

void sortByName(struct Student students[], int numStudents);

int searchByName(struct Student students[], int numStudents, const char *name);

float calculateAverage(struct Student students[], int n);


