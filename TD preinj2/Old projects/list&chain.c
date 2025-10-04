#include "header.h"

void fillArray(int tab[], int size, int seed) {
    srand(time(NULL) + seed);
    for (size_t i = 0; i < size; i++)
    {
        tab[i] = rand()%21;
    }
}
int average(int* tab, int size) {
    int sum = 0;
    for (size_t i = 0; i < size; i++) sum += tab[i];
    return sum/size;
}
void displayArray(int tab[], int size) {
    if (size==1) {
        printf("%d;\n", tab[size-1]);
    }
    else {
        printf("%d; ", tab[size-1]);
        displayArray(tab, size-1);
    }
}

typedef struct {
    char* firstName;
    char* lastName;
    int group;
    int grades[10];
} Student;
Student newStudent(char* firstName, char* lastName, int group) {
    Student student;
    student.firstName = malloc((strlen(firstName)+1) * sizeof(char));
    memcpy(student.firstName, firstName, strlen(firstName)+1);
    student.lastName = malloc((strlen(lastName)+1) * sizeof(char));
    memcpy(student.lastName, lastName, strlen(lastName)+1);
    student.group = group;
    fillArray(student.grades, 10, pow(strlen(firstName), strlen(lastName)));
    return student;
}
typedef struct _studentListEntry
{
    Student student;
    struct _studentListEntry* next;
} StudentListEntry;
StudentListEntry* makeStudentListEntryNode(Student student) {
    StudentListEntry* node = NULL;
    node = malloc(sizeof(StudentListEntry));
    if (node == NULL) exit(1);
    node->next = NULL;
    node->student = student;
    return node;
}
StudentListEntry* pushStudentToList(StudentListEntry* studentList, Student student) {
    StudentListEntry* node = makeStudentListEntryNode(student);
    if (studentList == NULL) return node;
    StudentListEntry* pos = studentList;
    while (pos->next != NULL)
    {
        pos = pos->next;
    }
    pos->next = node;
    return studentList;
}
void displayStudentList(StudentListEntry* studentList, int group) {
    StudentListEntry* pos = studentList;
    while (pos != NULL)
    {
        if (group == 0 || pos->student.group == group) {
            printf("%s average: %d grades:\n", pos->student.firstName, average(pos->student.grades, sizeof(pos->student.grades)/sizeof(int)));
            displayArray(pos->student.grades, sizeof(pos->student.grades)/sizeof(int));
            printf("---------\n");
        }
        pos = pos->next;
    };
    printf("\n");
}
StudentListEntry* findStudentFromList(StudentListEntry* studentList, char* firstName, char* lastName) {
    StudentListEntry* pos = studentList;
    while (pos != NULL)
    {
        if (strcmp(pos->student.firstName, firstName) == 0 && strcmp(pos->student.lastName, lastName) == 0) {
            return pos;
        }
        pos = pos->next;
    };
    printf("Didn't find student with name: %s %s", firstName, lastName);
    return NULL;
}
StudentListEntry* findWorstStudentFromList(StudentListEntry* studentList) {
    StudentListEntry* pos = studentList;
    StudentListEntry* worstStudent = NULL;
    float worstAverage = -1;
    while (pos != NULL)
    {
        float thisAverage = average(pos->student.grades, sizeof(pos->student.grades)/sizeof(int));
        if (worstAverage == -1 || thisAverage < worstAverage) {
            worstAverage = thisAverage;
            worstStudent = pos;
        }
        pos = pos->next;
    };
    return worstStudent;
}
float promotionAverage(StudentListEntry* studentList, int group) {
    StudentListEntry* pos = studentList;
    float total = 0;
    int number = 0;
    while (pos != NULL)
    {
        if (group == 0 || pos->student.group == group) {
            total += average(pos->student.grades, sizeof(pos->student.grades)/sizeof(int));
            number++;
        }
        pos = pos->next;
    };
    return total/number;
}


int main(int argc, char const *argv[])
{
    StudentListEntry* studentList = NULL;
    studentList = pushStudentToList(studentList, newStudent("Tom", "Jedusor", 1));
    studentList = pushStudentToList(studentList, newStudent("Harry", "Potter", 2));
    studentList = pushStudentToList(studentList, newStudent("Ron", "Weasley", 3));
    studentList = pushStudentToList(studentList, newStudent("Hermione", "Granger", 3));
    displayStudentList(studentList, 0);
    StudentListEntry* studentEntry = findStudentFromList(studentList, "Harry", "Potter");
    if (studentEntry != NULL)
    {
        printf("Found: %s\n", studentEntry->student.firstName);
        printf("Average: %d\n", average(studentEntry->student.grades, sizeof(studentEntry->student.grades)/sizeof(int)));
    }
    printf("Promotion average %f\n", promotionAverage(studentList, 3));
    StudentListEntry* worstStudent = findWorstStudentFromList(studentList);
    printf("Worst student: %s\n", worstStudent==NULL?"None":worstStudent->student.firstName);
    return 0;
}
