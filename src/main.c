/**
 * \mainpage
 * # Лабораторна робота №13
 *
 * \author Марков Владислав, КН-922б
 * \date 03-04-2023
 */

/*!
\file main.c
\brief Головний файл

Це файл, який містить точку входу, код для запису строки,
виклики функцій CreateConst та код виводу результату її роботи .
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "lib.h"

/**
 Головна функція.

 Послідовність дій

- Створення змінних
	str - маисв куди записуємо строку
	res - число яке сформувала функція.
	
	
- Виводимо на екран інформацію про автора, номер, тему лабараторної роботи , і що виконує програма
- Записуємо строку яку ввів користувач
- Викликаємо функцію CreateConst та записуємо результат який вона повернула у змінну res
- Виводимо результат на екран
*/

int main(int argc, char* argv[])
{
	
	FILE *output_file;  // = fopen(argv[1], "w");
	DIR *input_dir;
	struct dirent *elemets;
	char **out_data;
	
	printf("\nАвтор:Марков Владислав\nГрупа:КН-922Б\nНомер лабараторної роботи:14\nТема:Строки Взаємодія з файлами\n\n");
	printf("Вивести структуру файлів та каталогів, як це робить утиліта Linux tree.\n\n");
	
	if(argc > 1)
	{	
		
		if(argc != 3)
		{
			printf("Ви ввели некоректну кількість даних");
			return 1;
		}
		
		if(Check_Write_In_Data(argv, output_file, input_dir) == 0)
		{
			Create_Struct_Dir(input_dir, elemets, out_data);
			Write_In_File(output_file, out_data);
			
			return 0;
		}
		else
			printf("Не можливо отримати доступ до файлу або дерикторії");
	}
	else
		printf("Ви не ввели ніякі дані");
	

	return 1;
}

















