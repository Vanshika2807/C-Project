# Student Management System
# Problem Statement
The main aim is to perform various operations on students present in a class . This code is written in linux terminal in C using static libraries

# Various operations that are performed in this code are:
1. add a new student in a class
2. delete a student by its roll number
3. sort the students in class using name and roll number
4. search the students in class by their name and roll number
5. display details of all students enrolled in a particular course
6. display details of all students in class
7. find average cgpa of all students present in class
I have used static libraries . There are total 3 files present .
# Various steps to create static library or link our archive folder with main.c file
1.nano main.c 
2. nano add.h (having declaration of all functions ) 
3.nano addStudent.c (make a file having defination of all functions used in main.c) 
4. gcc addStudent.c -o add_output 
5. ar rcs archive.a add_output 
6. gcc -o main_output main.c -L. archive.a 
now at last execute your main_output file
