#include <stdio.h>

struct date
{
   int day;
   int month;
   int year;
};
struct student
{
   char firstName[50];
   int roll;
   float marks;
   struct date birthday;
};

int main()
{
   int student;

   printf("Enter the no. of students:");
   scanf("%d", &student);
   struct student s[student];
   int i, j;
   printf("Enter information of students:\n");

   // storing information
   for (i = 0; i < student; ++i)
   {
      s[i].roll = i + 1;
      printf("\nFor roll number %d,\n", s[i].roll);
      printf("Enter first name: ");
      scanf("%s", s[i].firstName);
      printf("Enter marks: ");
      scanf("%f", &s[i].marks);
      printf("Enter birthday date:");
      scanf("%d", &s[i].birthday.day);
      printf("Enter birthday month: ");
      scanf("%d", &s[i].birthday.month);
      printf("Enter birthday year:");
      scanf("%d", &s[i].birthday.year);
   }
   printf("Displaying Information:\n\n");

   // displaying information
   for (i = 0; i < student; ++i)
   {
      printf("\nRoll number: %d\n", s[i].roll);
      printf("First name: ");
      puts(s[i].firstName);
      printf("Marks: %.1f", s[i].marks);
      printf("\n");
      printf("Date of Birth: %d : %d : %d", s[i].birthday.day, s[i].birthday.month, s[i].birthday.year);
      printf("\n");
   }

   // writing information to file
   char *filename = "test.txt";

   // open the file for writing
   FILE *fp = fopen(filename, "w");

   if (fp == NULL)
   {
      printf("Error opening the file %s", filename);
      return -1;
   }

   // write to the text file
   for (int i = 0; i < student; i++)
      fprintf(fp, "\nRoll number: %d\n First Name: %s\n Marks: %.1f\n Date of Birth: %d : %d : %d \n", s[i].roll, s[i].firstName, s[i].marks, s[i].birthday.day, s[i].birthday.month, s[i].birthday.year);

   // close the file
   fclose(fp);

   // sorting the students based on their Marks
   struct student temp;

   for (int i = 0; i < student; i++)
   {
      for (j = 0; j < student; j++)
      {
         if (s[i].marks > s[j].marks)
         {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
         }
      }
   }

   // displaying information
   for (i = 0; i < student; ++i)
   {
      printf("\nRoll number: %d\n", s[i].roll);
      printf("First name: ");
      puts(s[i].firstName);
      printf("Marks: %.1f", s[i].marks);
      printf("\n");
      printf("Date of Birth: %d : %d : %d", s[i].birthday.day, s[i].birthday.month, s[i].birthday.year);
      printf("\n");
   }

   // writing sorted information to file
   char *filename1 = "marks_sort.txt";

   // open the file for writing
   FILE *fp1 = fopen(filename1, "w");

   if (fp1 == NULL)
   {
      printf("Error opening the file %s", filename1);
      return -1;
   }

   // write to the text file
   for (int i = 0; i < student; i++)
      fprintf(fp1, "\nRoll number: %d\n First Name: %s\n Marks: %.1f\n Date of Birth: %d : %d : %d \n", s[i].roll, s[i].firstName, s[i].marks, s[i].birthday.day, s[i].birthday.month, s[i].birthday.year);

   // close the file
   fclose(fp1);

   return 0;
}
