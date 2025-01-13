/**********INCLUDES**************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
/***********Defines**************/
typedef struct {
  char name[25];
  unsigned int age;
  unsigned int id;
  float degree;
} student;

void SetStud(student *ptr1, int *num); // Set Specific num of students
void GetStud(student *ptr1, int *num); // Prints Specific num of students
void CopyData(student *oldPtr, int *num,
              student *newPtr);              // Move data to larger pointer
void AddStud(student *oldPtr, int *num);     // Add One Student
void DelData(student *Ptr, int *num);        // Delete One student
void GetStudOneLine(student *Ptr, int *num); // Print students in one line
void ShiftUpData(student *oldPtr, int *num,
                 int n); // Shift Data Up When deleting one student
void EditStudent(student *Ptr, int *num); // Edit One student

student *ptr = NULL;
int main() {
  int n;
  unsigned int state = 1;
  printf("Welcome To the Student DataBase Program :-)\nYou have to store "
         "minimum One student to start\n");
  printf("How many students do you want to store?-> ");
  scanf("%i", &n);
  int *numptr = &n;
  ptr = (student *)malloc(((*numptr) * sizeof(student)));
  if (ptr != NULL) {
    SetStud(ptr, numptr);
    while (state) {
      printf("You have [ %d ] Students Stored right now\n", *numptr);
      for (int i = 0; i < 50; i++) {
        printf(".");
        Sleep(30);
      }
      printf("\n1-Add Student\n2-Edit Student\n3-View Students\n4-Delete "
             "Student\n5-Exit\nEnter Here->");
      unsigned int choice;
      scanf("%d", &choice);
      printf("\nLoading");
      for (int i = 0; i < 40; i++) {
        printf(".");
        Sleep(30);
      }
      printf("\n");
      switch (choice) {
      case 1:
        AddStud(ptr, numptr);
        break;

      case 2:

        if (*numptr > 0) {
          EditStudent(ptr, numptr);
        } else {
          printf("NO STUDENT TO EDIT!!!\n");
        }
        break;

      case 3:
        if (*numptr > 0) {
          GetStudOneLine(ptr, numptr);
        } else {
          printf("NO STUDENT TO VIEW!!!\n");
        }

        break;

      case 4:
        if (*numptr > 0) {
          DelData(ptr, numptr);
        } else {
          printf("NO STUDENT TO DELETE!!!\n");
        }
        break;
      case 5:
        printf("\nGood Bye :-) \n");
        state = 0;
        break;
      default:
        printf("Wronge Input!!!!!!!\n");
        break;
      }
    }
  } else {
    printf("\n ERROR!!!!!\n malloc returned NULL!!!!!!!! \n");
  }
  return 0;
}

void SetStud(student *ptr1, int *num) {
  for (int i = 0; i < (*num); i++) {
    printf("-----------------------------------------------------\n");
    printf("Enter name of student [%i]: ", (i + 1));
    fflush(stdin);
    gets(((ptr1 + i)->name));
    fflush(stdin);
    while (1) {
      printf("Enter age of student [%i]: ", (i + 1));
      scanf("%i", &((ptr1 + i)->age));
      if ((((ptr1 + i)->age) > 50) || (((ptr1 + i)->age) < 1)) {
        printf("Wrong Input!!!! Range(1 - 50)\n");
      } else {
        break;
      }
    }

    while (1) {
      printf("Enter ID of student [%i]: ", (i + 1));
      scanf("%i", &((ptr1 + i)->id));
      if ((((ptr1 + i)->id) < 1)) {
        printf("Wrong Input!!!! Must be more than 0\n");
      } else {
        break;
      }
    }

    // printf("Enter age of student [%i]: ", (i + 1));
    // scanf("%i", &((ptr1 + i)->age));
    // printf("Enter ID of student [%i]: ", (i + 1));
    // scanf("%i", &((ptr1 + i)->id));
    printf("-----------------------------------------------------\n");
  }
}

void GetStud(student *ptr1, int *num) {
  for (int i = 0; i < (*num); i++) {
    printf("-----------------------------------------------------\n");
    printf("name of student [%i] :%s \n", (i + 1), ((ptr1 + i)->name));
    printf("age of student  [%i] :%i \n", (i + 1), ((ptr1 + i)->age));
    printf("ID of student   [%i] :%i \n", (i + 1), ((ptr1 + i)->id));
    printf("-----------------------------------------------------\n");
  }
}

void AddStud(student *oldPtr, int *num) {
  // student *newPtr = (student *)malloc((((*num) + 1) * sizeof(student)));
  // CopyData(oldPtr, num, newPtr);
  *num += 1;
  oldPtr = realloc(oldPtr, ((*num) * sizeof(student)));
  printf("-----------------------------------------------------\n");

  printf("Enter name of student [%i]: ", (*num));
  fflush(stdin);
  gets(((oldPtr + ((*num) - 1))->name));
  fflush(stdin);
  while (1) {
    printf("Enter age of student [%i]: ", (*num));
    scanf("%i", &((oldPtr + ((*num) - 1))->age));
    if ((((oldPtr + ((*num) - 1))->age) > 50) ||
        (((oldPtr + ((*num) - 1))->age) < 1)) {
      printf("Wrong Input!!!! Range(1 - 50)\n");
    } else {
      break;
    }
  }

  while (1) {
    printf("Enter ID of student [%i]: ", (*num));
    scanf("%i", &((oldPtr + ((*num) - 1))->id));
    if ((((oldPtr + ((*num) - 1))->id) < 1)) {
      printf("Wrong Input!!!! Must be more than 0\n");
    } else {
      break;
    }
  }

  // printf("Enter age of student [%i]: ", (*num));
  // scanf("%i", &((oldPtr + ((*num) - 1))->age));
  // printf("Enter ID of student [%i]: ", (*num));
  // scanf("%i", &((oldPtr + ((*num) - 1))->id));
  // printf("-----------------------------------------------------\n");
}

void CopyData(student *oldPtr, int *num, student *newPtr) {
  for (int i = 0; i < (*num); i++) {
    strcpy(((newPtr + i)->name), ((oldPtr + i)->name));
    ((newPtr + i)->id) = ((oldPtr + i)->id);
    ((newPtr + i)->age) = ((oldPtr + i)->age);
  }
  oldPtr = newPtr;
  free(newPtr);
}

void ShiftUpData(student *oldPtr, int *num, int n) {
  for (int i = (n - 1); i < ((*num) - 1); i++) {
    strcpy(((oldPtr + i)->name), ((oldPtr + (i + 1))->name));
    ((oldPtr + i)->id) = ((oldPtr + (i + 1))->id);
    ((oldPtr + i)->age) = ((oldPtr + (i + 1))->age);
  }
}

void DelData(student *Ptr, int *num) {
  GetStudOneLine(Ptr, num);
  unsigned int n;
  while (1) {
    printf("\n Which student to delete? \nNUM: ");
    scanf("%i", &n);
    if ((n > *num) || (n < 1)) {
      printf("Wrong Input!!!! Range(1 - %d)", *num);
    } else {
      ShiftUpData(Ptr, num, n);
      *num -= 1;
      Ptr = realloc(Ptr, ((*num) * sizeof(student)));
      break;
    }
  }
}

void GetStudOneLine(student *Ptr, int *num) {
  printf("\n| NUM | ID | AGE |\t\tNAME\t\t|\n");
  printf("-----------------------------------------------------\n");
  for (int i = 0; i < (*num); i++) {
    // printf("| NUM | ID | AGE |\t\tNAME\t\t| AGE |\n");
    printf("   %i    %i   %i    %s\n", (i + 1), ((Ptr + i)->id),
           ((Ptr + i)->age), ((Ptr + i)->name));
    // printf("-----------------------------------------------------\n");
  }
}

void EditStudent(student *Ptr, int *num) {
  unsigned int n;
  GetStudOneLine(Ptr, num);
  printf("Which Student NUM To Edit? -> ");
  scanf("%i", &n);
  printf("What do you want to edit?\n1-Name\t2-Age\t3-ID\n-> ");
  unsigned int choice;
  scanf("%i", &choice);
  switch (choice) {
  case 1:
    printf("Enter New Name of Student [%i]: ", (n));
    fflush(stdin);
    gets(((Ptr + (n - 1))->name));
    fflush(stdin);
    break;

  case 2:
    while (1) {
      printf("Enter New Age of Student [%i]: ", (n));
      scanf("%i", &((Ptr + (n - 1))->age));
      if ((((Ptr + (n - 1))->age) > 50 || ((Ptr + (n - 1))->age) < 1)) {
        printf("Wrong Input!!!! Range(1 - 50)\n");
      } else {
        break;
      }
    }
    break;

  case 3:
    while (1) {
      printf("Enter New ID of Student [%i]: ", (n));
      scanf("%i", &((Ptr + (n - 1))->id));
      if (((Ptr + (n - 1))->id) < 1) {
        printf("Wrong Input!!!! Must be more than 0 \n");
      } else {
        break;
      }
    }
    break;

  default:
    printf("Wrong Input!!!!!!");
    break;
  }
}
