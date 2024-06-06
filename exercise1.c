#include <stdio.h>

#define LENGTHNAME 50
typedef struct student
{
    char* name[LENGTHNAME];
    int age;
    int class;
    int mark;
}Student;

void enterInforOfStudent(Student* newStudent,int numberOfStudent);
void printfInforOfStudent(Student* newStudent,int numberOfStudent);

int main(){
    Student newStudent[100];

    int numberOfStudent;
    printf("Enter number of student: ");
    scanf("%d",&numberOfStudent);

    /* enter infor of student */
    enterInforOfStudent(newStudent,numberOfStudent);

    printf("\n\n");
    /* print infor of student */
    printfInforOfStudent(newStudent,numberOfStudent);
    

    return 0;
}

void enterInforOfStudent(Student* newStudent,int numberOfStudent){
    for (int i = 0; i < numberOfStudent; i++){
        printf("Enter information of student at index %d:\n",i+1);
        printf("\tStudent's name: ");
        scanf("%s",&(newStudent[i].name));
        printf("\tStudent's age: ");
        scanf("%d",&(newStudent[i].age));
        printf("\tStudent's class: ");
        scanf("%d",&(newStudent[i].class));
        printf("\tStudent's mark: ");
        scanf("%d",&(newStudent[i].mark));
        
        while (newStudent[i].mark < 0 || newStudent[i].mark >10)
        {
            printf("\tMark of student must larger than 0 and smaller than 10: ");
            scanf("%d",&(newStudent[i].mark));  
        }
        
    }
}

void printfInforOfStudent(Student* newStudent,int numberOfStudent){
    for (int i = 0; i < numberOfStudent; i++)
    {
        printf("Information of student at index %d:\n",i+1);
        printf("\tStudent's name: %s\n",newStudent[i].name);
        printf("\tStudent's age: %d\n",newStudent[i].age);
        printf("\tStudent's class: %d\n",newStudent[i].class);
        printf("\tStudent's mark: %d\n\n",newStudent[i].mark);
    }
}