#include <stdio.h>
#include <stdlib.h>

#define NAMELENGTH 30
typedef struct student
{
    char nameOfStudent[NAMELENGTH];
    int ageOfStudent;
    int IDOfStudent;
    int markOfStudent;
    struct student* nextStudent;
}Student;

Student* newInfor(char*,int,int,int);
void inputInforOfStudent(char*, int*, int*, int*);
void pushNewStudent(Student**, char*, int,int,int);
void popLastStudent(Student*);
void addStudentAfterID(Student*, int);
void deleteStudentByID(Student*, int);
void printAllInforOfStudent(Student*);
void printInforEachStudent();


int main(){
    Student* studentList = NULL;

    pushNewStudent(&studentList,"danh",14,25,8);
    printInforEachStudent(studentList,25);
    return 0;
}

/*<! creat the new Information of Student !>*/
Student* addInfor(char* name, int age, int IDnumber,int mark){
    Student* newStudent = (Student*)malloc(sizeof(Student));
    /* assign for name of Student */
    for (int i = 0; i < NAMELENGTH; i++)
    {
        if(name[i] == '\0') {
            newStudent->nameOfStudent[i] = '\0';
            break;
        }else{
            newStudent->nameOfStudent[i] = name[i];
        }
    }
    newStudent->ageOfStudent = age;
    newStudent->markOfStudent = mark;
    newStudent->IDOfStudent = IDnumber;   
    newStudent->nextStudent = NULL; 
    return newStudent;
}

/*<!  !>*/
void pushNewStudent(Student** headStudent, char* name, int age, int IDnumber, int mark){
    Student* newStudent = addInfor(name,age,IDnumber,mark);
    Student* current = *headStudent;

    /* check NULL of struct */
    if (*headStudent == NULL){
        *headStudent = newStudent;
        return;
    }

    while (current != NULL){
        current = current->nextStudent;
    }
    current->nextStudent = newStudent;
}

/*<!  !>*/
void printInforEachStudent(Student* studentList, int IDnumber){
    if(studentList != NULL && (studentList->IDOfStudent == IDnumber)){
        printf("\nInformation of student at ID = %d: \n\n",studentList->IDOfStudent);
        printf("\tName of student: %s\n",studentList->nameOfStudent);
        printf("\tAge of student: %d\n",studentList->ageOfStudent);
        printf("\tID of student: %d\n",studentList->IDOfStudent);
        printf("\tMark of student: %d\n",studentList->markOfStudent);
    }else if(studentList == NULL || (studentList != NULL && (studentList->IDOfStudent != IDnumber))){
        printf("Information of student unavailable.\n");
        return;
    }
    studentList = studentList->nextStudent;
}

void printAllInforOfStudent(Student* student){
    printf("\nList of information of student: \n\n");
    while(student != NULL){
        printf("\n\tInformation of student at ID = %d:\n",student->IDOfStudent);
        printf("\t\tName of student:\n",student->nameOfStudent);
        printf("\t\tAge of student:\n",student->ageOfStudent);
        printf("\t\tMark of student:\n",student->markOfStudent);

        student = student->nextStudent;
    }
}