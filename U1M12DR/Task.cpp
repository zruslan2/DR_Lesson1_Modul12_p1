#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "MyFunc.h"

int nz;

void main()
{
	FILE *file;
	setlocale(LC_ALL, "Ru");
	srand(time(NULL));
	while (true)
	{
		printf("Введите номер задания, 0 - для выхода "); scanf("%d", &nz);
		if (nz == 0)
		{
			break;
			system("exit");
		}
		else if (nz == 1)
		{
			/*1. Имеется файл с числами. Переписать все числа в другой файл. Размер заданного
			файла неизвестен*/
			system("cls");
			int r = 4 + rand() % 50;
			if ((file = fopen("chisla.txt", "w")) == NULL)perror("Ошибка открытия файла: ");
			else
			{
				for (int i = 0; i < r; i++)
				{
					if (i < r - 1) fprintf(file, "%d\n", 1 + rand() % 200);
					else fprintf(file, "%d", 1 + rand() % 200);
				}
			}
			fclose(file);
			int razm = 0;
			int *arr = NULL;
			int *numb;
			green();
			printf("Считывание чисел с файла\n");
			if ((file = fopen("chisla.txt", "r")) == NULL)perror("Ошибка открытия файла: ");
			else
			{
				while (!feof(file))
				{
					razm++;
					numb = (int*)realloc(arr, razm * sizeof(int));
					if (numb != NULL)
					{
						arr = numb;
						fscanf(file, "%d", &arr[razm - 1]);
					}
				}
			}
			fclose(file);
			/*for (int i = 0; i < razm; i++)
			{
				printf("%d\n",arr[i]);
			}*/
			printf("Создание нового файла и запись в него чисел\n");
			white();
			if ((file = fopen("chisla1.txt", "w")) == NULL)perror("Ошибка открытия файла: ");
			else
			{
				for (int i = 0; i < razm; i++)
				{
					if (i < razm - 1) fprintf(file, "%d\n", arr[i]);
					else fprintf(file, "%d", arr[i]);
				}
			}
			fclose(file);
		}
		else if (nz == 2)
		{
			/*2. Имеется типизированный файл с числами.Удалить из него пятое число.
			Результат записать в другой файл*/
			system("cls");
			int razm = 0;
			int *arr = NULL;
			int *numb;
			green();
			printf("Считывание чисел с файла\n");
			if ((file = fopen("chisla.txt", "r")) == NULL)perror("Ошибка открытия файла: ");
			else
			{
				while (!feof(file))
				{
					razm++;
					numb = (int*)realloc(arr, razm * sizeof(int));
					if (numb != NULL)
					{
						arr = numb;
						fscanf(file, "%d", &arr[razm - 1]);
					}
				}
			}
			fclose(file);
			printf("Создание нового файла и запись в него чисел\n");
			white();
			if ((file = fopen("chisla2.txt", "w")) == NULL)perror("Ошибка открытия файла: ");
			else
			{
				for (int i = 0; i < razm - 1; i++)
				{
					if (i < 4)
					{
						fprintf(file, "%d\n", arr[i]);
					}
					else if (i >= 4)
					{
						fprintf(file, "%d\n", arr[i + 1]);
					}
					else if (i < razm - 2)
					{
						fprintf(file, "%d", arr[i + 1]);
					}
				}
			}
			fclose(file);
		}
		else if (nz == 3)
		{
			/*3.	Дан текстовый файл.
				a.Подсчитать количество строк в нем
				b.Подсчитать количество символов в нем
				c.Подсчитать количество символов в каждой строке*/
			system("cls");
			green();
			int razm = 0;
			char arr[80];
			green();
			if ((file = fopen("text.txt", "r")) == NULL)perror("Ошибка открытия файла: ");
			else
			{
				while (!feof(file))
				{
					razm++;
					fgets(arr, 80, file);					
				}
			}			
			fclose(file);
			printf("а. Количество строк в файле: %d\n", razm);
			char r;
			razm = 0;
			if ((file = fopen("text.txt", "r")) == NULL)perror("Ошибка открытия файла: ");
			else
			{
				while (!feof(file))
				{					
					r=fgetc(file);
					if(r!='\n')
					razm++;					
				}
			}
			fclose(file);
			printf("b. Количество символов в файле: %d\n", razm);
			printf("c. Количество символов в строках:\n");
			if ((file = fopen("text.txt", "r")) == NULL)perror("Ошибка открытия файла: ");
			else
			{
				int s = 0,count;
				while (!feof(file))
				{
					arr[0] = '\0';
					fgets(arr, 80, file);
					s++;
					count = strlen(arr);
					printf("%d - %d\n", s, count-1);
				}
			}
			fclose(file);
			white();
		}
		else
		{
			red();
			printf("Такого задания не существует \n");
			white();
		}
	}
}