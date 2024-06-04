#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char nameOfStudent[30];
    int AgeOfStudent;
    int IDOfStudent;
    int markOfStudent;
    struct student* nextStudent;
}Student;

Student* newInfor(char*,int,int,int);
void pushNewStudent(Student**, char*, int,int,int);
void popLastStudent(Student*);
void addStudentAfterID(Student*, int);
void deleteStudentByID(Student*, int);
void printAllInforOfStudent(Student*);
void printInforEachStudent();


int main(){

    return 0;
}


Student* newInfor(char* name, int age, int IDnumber,int);