/**
\file lib.c
\brief Файл з реалізацією функцій

Цей файл, містить реалізацію функції CreateConst.
*/

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "lib.h"

/**
 
 Функція mul_matrix
 \param a[] - масив у якому зберігається строка яку ввів користувач.
 \return Повертає сформоване число або нуль.
 
 
 Послідовність дій
 
- Створення змінних
	number_letter - кількість букв у слові
	res - число яке сформувала функція.

- Перевіряємо порожня наша строка чи ні, як що так то повертємо 0.

- Як що строка не порожня то рахуємо скільки в ній літер та цифр.

- Запускаємо цил який буде пребирати слова у нашому речені.

- Запускаємо другий цикл який буде преебирати літери у нашому слові.

- Первіряємо як що це латиниця або число то додаємо до j + 1. Як що не те не інше перевіряємо на те чи це кирилиця, як що так то додаємо до кількості літер +1 і до j та i +1 так як кирилиця займає два байти. Як що це щось інше завершуємо цикл та переходимо до наступного слова.

- Потім присвоюємо різницю між j та кількітю літер змінній number_letter, таким чином слова у яких є кирилиця дорівнюють кількості символлів а не кількості занятих байт.

- Перевіряємо як що у слові кількість літер більша ніж 10 то множимо змінну res на 100 та додаємо кількість літер, як що менше десяти то множимо змінну res на 10 та додаємо кількість літер.

- Повертаємо res. 

*/

int Check_Write_In_Data(int number_arguments,char *arr_arguments[])
{
	FILE *output_file;
	DIR *input_dir;
	
	if(number_arguments > 1)
	{	
		if(number_arguments != 3)
			printf("Ви ввели некоректну кількість даних");
		else
		{	
			output_file = fopen(*(arr_arguments + 2), "w");
			input_dir = opendir(*(arr_arguments + 1));
		
			if(output_file == NULL || input_dir == NULL )
				printf("Не можливо отримати доступ до файлу або дерикторії");
			else
				return 0;
		}		
	}
	else	
		printf("Ви не ввели ніякі дані");
		
	return 1;
}

int Write_Struct_Dir(char arg_for_file[],char present_dir[],char parents_dir[])
{		
	DIR *input_dir = opendir(present_dir);
	struct dirent *elements;
	int number_elements = 0;
	
	
	elements = readdir(input_dir);
	while(elements != NULL)
	{	
		number_elements++;
		
		if(elements->d_type == 4 && strcmp(elements->d_name, ".") != 0 && strcmp(elements->d_name, "..") != 0)
		{
			char path[PATH_MAX] = {0};
			char element[255];
			int type = elements->d_type;
			
			strcat(element, elements->d_name);
			strcat(path, present_dir);
			strcat(path, "/");
			strcat(path, elements->d_name);
			
			Write_Out_File(element, type, arg_for_file, present_dir, parents_dir);
			
			memset(element, 0, 255);
			
			number_elements += Write_Struct_Dir(arg_for_file, path, parents_dir);
		}
		if(elements->d_type != 4 && strcmp(elements->d_name, ".") != 0 && strcmp(elements->d_name, "..") != 0)
		{	
			char element[255];
			
			strcat(element, elements->d_name);
		
			Write_Out_File(element, 0,arg_for_file, present_dir, parents_dir);
			
			memset(element, 0, 255);
		}
		elements = readdir(input_dir);
	}
		
	number_elements -= 2;
	
	closedir(input_dir);
	
	
	return number_elements;
}

int Write_Out_File(char element[],int type,char arg_for_file[],char present_dir[],char parents_dir[])
{	
	int entry_par_path = 0;
	int entry_pre_path = 0;
	int number_tab = 0;
	
	FILE *output_file = fopen(arg_for_file, "a");
	
	for(int i = 0; parents_dir[i] != '\0';i++)
	{
		if(parents_dir[i] == '/')
			entry_par_path++;		
	}
	
	for(int i = 0; present_dir[i] != '\0';i++)
	{
		if(present_dir[i] == '/')
			entry_pre_path++;
	}
	
	if(entry_pre_path >= entry_par_path)
	{
		number_tab = entry_pre_path - entry_par_path;
		
		if(type == 4)
		{	
		
			for(int i = 0; i < number_tab; i++)
				fprintf(output_file,"|\t");
			
			if(number_tab == 0)
				number_tab++;
			
			fprintf(output_file,"|");
			while(number_tab + 6 != 0)
			{
				fprintf(output_file,"-");
				number_tab--;
			}
			
			fprintf(output_file,"%s\n", element);
			fclose(output_file);
			
			return 0;
		}
		
		while(number_tab != 0)
		{
			fprintf(output_file,"|\t");
			number_tab--;
		}
			
		fprintf(output_file,"|-%s\n", element);	
	}
	else
		return 1;
		
	fclose(output_file);

	return 0;
}









