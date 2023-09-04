#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "add.h"
#define max_students 100


int main() {

	struct Student * students = (struct Student *)malloc(max_students*sizeof(struct Student));
	if (students == NULL) {
		printf("Memory allocation failed.\n");
		return 1;
	}
	int numStudents = 0;

		printf("Student Management System\n");
		printf("1. Add Student\n");
		printf("2. Delete Student by their roll number\n");
		printf("3. Display Student by their courses\n");
		printf("4. Sort by Name\n");
		printf("5. Sort by Roll Number\n");
		printf("6. Search by Roll Number\n");
		printf("7. calculate average of all students  \n");
		printf("8. display details of all students \n");
		printf("9. exit \n");
		int choice = 0;
      
	while(1) {
		printf("\nEnter your choice ranging from 1 to 9: ");
		scanf("%d", &choice);
				
		switch (choice) {
			case 1:
			  if(numStudents >= max_students){
				printf("no more student can be added");
				return 0;
			  }
			  int rollNumber;
			  char name[50];
			  float cgpa;
			  char courses[100];
			  printf("Enter Roll Number: ");
                	  scanf("%d", &rollNumber);
                	  printf("Enter Name: ");
                	  scanf("%s", name);
                	  printf("Enter CGPA: ");
                	  scanf("%f", &cgpa);
                	  printf("Enter Courses: ");
                	  scanf("%s", courses);
			  numStudents = addStudent(students, numStudents, rollNumber, name, cgpa, courses);
                	  break;
			
			case 2:
			  if(numStudents == 0){
				printf("no students are there\n");
				break;
			   }

			  printf("Enter the roll number you want to remove\n");
			  int roll;
			  scanf("%d",&roll);
			  numStudents = deleteStudent(students, numStudents, roll);
			break;

			case 3:
			  if(numStudents == 0){
				printf("no students are there\n");
				break;
			   }

			  printf("enter the course for which you want to see students ");
			  char ch[100];
			  scanf("%s",ch);
			  if(!(displayStudentsByCourse(students, numStudents , ch)))
			       printf("there is no student with this course\n");
			  break;
			
			case 4:
			  sortByName(students, numStudents);
			  break;

			case 5:
			  sortByRoll(students, numStudents);
			  break;


			case 6:

			  if(numStudents == 0){
				printf("no students are there\n");
				break;
			   }

			  printf("enter the roll number want to search ");
			  int roll2;
			  scanf("%d",&roll2);
			  int searchResult = searchByRoll(students, numStudents, roll2);
			  if(searchResult != -1){
				printf("student found:\n");
				printf("Roll Number: %d\n", students[searchResult].rollNumber);
                    		printf("Name: %s\n", students[searchResult].name);
                    		printf("CGPA: %.2f\n", students[searchResult].cgpa);
                    		printf("Courses: %s\n", students[searchResult].courses);
                		}
 
			  else if(searchResult == -1){
                    		printf("Student not found.\n");
                		}
			  else{
			       printf("no student is there\n");
			       }
                		break;

			case 7:
			  float avgCGPA= calculateAverage(students, numStudents);
			  printf("Average cgpa : %.2f\n", avgCGPA);
			  break;

			case 8:
			  displayAllStudent(students,numStudents);
			  break;

			case 9:
			  printf("program finished successfully\n");
			  return 0;

			default:
			  printf("Invalid choice\n");
			  return 0;
			} 
               }
		return 0;
}
