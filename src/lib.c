/**
\file lib.c
\brief Файл з реалізацією функцій

Цей файл, містить реалізацію функції CreateConst.
*/

#include <stdio.h>
#include <string.h>
#include <dirent.h>

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

int Write_Struct_Dir(char arg_for_file[],char arg_for_dir[])
{		
	FILE *output_file = fopen(arg_for_file, "a");
	DIR *input_dir = opendir(arg_for_dir);
	struct dirent *elements;
	int number_elements = 0;
	
	elements = readdir(input_dir);
	while(elements != NULL)
	{	
		number_elements++;
		
		if(elements->d_type == DT_DIR && strcmp(elements->d_name, ".") != 0 && strcmp(elements->d_name, "..") != 0)
		{
			char path[PATH_MAX] = {0};
			
			strcat(path, arg_for_dir);
			strcat(path, "/");
			strcat(path, elements->d_name);
			
			number_elements += Write_Struct_Dir(arg_for_file, path);
		}
		fprintf(output_file,"%s/%s\n", arg_for_dir,elements->d_name);
		elements = readdir(input_dir);
		
	}
	
	number_elements -= 2;
	fprintf(output_file,"\n\n");
	
	closedir(input_dir);
	fclose(output_file);
	
	return number_elements;
}









