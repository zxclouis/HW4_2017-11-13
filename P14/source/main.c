#include <stdio.h>
#include <stdlib.h>
#define students 3
#define exams 4

int minimun(const int grades[][exams], int pupils, int tests);
int maximun(const int grades[][exams], int pupils, int tests);
double average(const int setofgrades[], int tests);
void printarray(const int grades[][exams], int pupils, int tests);

int main(void)
{
	int student;
	const int studentgrades[students][exams]=
	{
		{ 77, 68, 86, 73 },
		{ 96, 87, 89, 78 },
		{ 70, 90, 86, 81 }
	};
	printf("the array is :\n");
	printarray(studentgrades, students, exams);
	printf("\n\nLowest grades: %d\nHighest grades : %d\n", minimun(studentgrades, students, exams), maximun(studentgrades, students, exams));

	for (student = 0; student < students; student++)
	{
		printf("The average grade for student %d is %.2f\n", student, average(studentgrades[student], exams));
	}
	system("pause");
	return 0;
}

void printarray(const int grades[][exams], int pupils, int tests)
{
	int i;
	int j;
	printf("		[0]  [1]  [2]  [3]");
	for (i = 0; i < pupils; i++)
	{
		printf("\nstudentgrades[%d]", i);
		for (j = 0; j < tests; j++)
			printf("%-5d", grades[i][j]);
	}
}
int minimun(const int grades[][exams], int pupils, int tests)
{
	int i;
	int j;
	int lowgrade = 100;
	for (i = 0; i < pupils; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grades[i][j] < lowgrade)
			{
				lowgrade = grades[i][j];
			}
		}
	}
	return lowgrade;
}
int maximun(const int grades[][exams], int pupils, int tests)
{
	int i;
	int j;
	int highgrade = 0;
	for (i = 0; i < pupils; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grades[i][j] > highgrade)
			{
				highgrade = grades[i][j];
			}
		}
	}
	return highgrade;
}
double average(const int setofgrades[], int tests)
{
	int i;
	int total=0;
	for (i = 0; i < tests; i++)
	{
		total= total+setofgrades[i];
	}
	return (double)total / tests;
}