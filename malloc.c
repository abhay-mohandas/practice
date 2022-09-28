#include <stdio.h>
#include <stdlib.h>



#define NEWLINE printf("\n");

struct Student{
    char name[25];
    int rollNum;
    float marks;
};

int lenght(struct Student* list){
    int count=0;
    while (list[count].marks != -1) {++count;}
    return count;
}

float avgMarks(struct Student* list){
    int count=0,n=lenght(list);
    float avg=0,total=0;
    for(count=0;count<n;count++){
        total += (list[count].marks);
    }
    avg = total/n;
    return avg;
}

void separateWithMarks(struct Student* list){
    int n = lenght(list),i=0;
    float avg = avgMarks(list);
    printf("Name of students who scored above average:\n");
    for(i=0;i<n;i++){
        if (list[i].marks >= avg) {
            printf("%d) %s [Marks: %f]\n",i+1,list[i].name,list[i].marks);
        }
    }
    printf("Name of students who scored below average:\n");
    for(i=0;i<n;i++){
        if (list[i].marks < avg) {
            printf("%d) %s [Marks: %f]\n",i+1,list[i].name,list[i].marks);
        }
    }
}

void sortMarks(struct Student* list){
    int i=0,j=0,len=lenght(list);
    struct Student temp;
    for(i=len-1;i>0;i--){
        for (j=0;j<i;j++ ) {
            if (list[j].marks>list[j+1].marks){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

void sortRoll(struct Student* list){
    int i=0,j=0,len=lenght(list);
    struct Student temp;
    for(i=len-1;i>0;i--){
        for (j=0;j<i;j++ ) {
            if (list[j].rollNum>list[j+1].rollNum){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

struct Student* SearchName(char search[], struct Student* list){
    int i=0,j=0,k=0,condition=0;
    struct Student* returnList = (struct Student *)malloc(sizeof(struct Student));
    while (list[i].marks != -1) {
        condition=1;
        for (j=0; search[j] != '\0'; j++) {
            if(search[j] != list[i].name[j]){
                condition=0;
            }
        }
        if (condition == 1) {
            returnList[k] = list[i];
            ++k;
        }
        ++i;
    }
    returnList[i].marks = -1;
    return returnList;
}

void newStudent(struct Student* list, int i){
    printf("\nEnter details of student %d:\n",i+1);
    printf("Name:");
    scanf("%s",list[i].name);
    printf("Roll Number:");
    scanf("%d",&list[i].rollNum);
    printf("Marks:");
    scanf("%f",&list[i].marks);
    list[i+1].marks = -1;
}

int main(){
    int i=0,n=0,newlen=0;
    char search[25];
    char condition='a';
    printf("Enter the number of total of student:");
    scanf("%d",&n);
    struct Student* student = (struct Student *)malloc((n+1)*sizeof(struct Student));
    for (i=0; i<n ; i++) {
        newStudent(student, i);
    }
    while (1) {    
        NEWLINE
        condition = 1;
        printf("Choose an option number:");
        printf("\n1)Print average marks\n2)Separate students based on average marks\n3)Sort students with respect to marks\n4)Sort students with respect to roll number\n5)Search a student\n6)Add a new student details\n7)Exit program\n:");
        scanf("%s",&condition);
        printf("\n");
        switch (condition) {
            case '1': printf("The average marks of the students is: %f\n",avgMarks(student));
                    break;
            case '2': separateWithMarks(student);
                    break;
            case '3': sortMarks(student);
                    for (i=0; i<n; i++) {
                        printf("%d)Name: %s, Roll Number: %d, Marks: %f\n",i+1,student[i].name,student[i].rollNum,student[i].marks);
                    }
                    break;
            case '4': sortRoll(student);
                    for (i=0; i<n; i++) {
                        printf("%d)Name: %s, Roll Number: %d, Marks: %f\n",i+1,student[i].name,student[i].rollNum,student[i].marks);
                    }
                    break;
            case '5': printf("Enter search characters:");
                    scanf("%s",search);
                    struct Student* newList = (struct Student *)malloc((n+1)*sizeof(struct Student));
                    newList = SearchName(search,student);
                    i=0;
                    while (newList[i].marks != -1){
                        printf("%d) %s\n",i+1,newList[i].name);
                        ++i;
                    }
                    free(newList);
                    break;
            case '6': newStudent(student, n);
                    ++n;
                    break;
            case '7': exit(0);
                    break;
            default:printf("Invalid option! Try again...\n");
                    break;
        }
    }
    
}