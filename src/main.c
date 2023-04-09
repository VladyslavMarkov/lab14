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
	char arg_for_file[PATH_MAX] = {0};
	char arg_for_dir[PATH_MAX] = {0};
	int number_elements = 0;
	
	printf("\nАвтор:Марков Владислав\nГрупа:КН-922Б\nНомер лабараторної роботи:14\nТема:Строки Взаємодія з файлами\n\n");
	printf("Вивести структуру файлів та каталогів, як це робить утиліта Linux tree.\n\n");
	
	if(Check_Write_In_Data(argc, argv) != 0)
		return 1;
	
	strcat(arg_for_file,*(argv + 2));
	strcat(arg_for_dir,*(argv + 1));
	
	
	FILE *output_file = fopen(arg_for_file, "a");
	fprintf(output_file,"%s\n|\n", arg_for_dir);
	fclose(output_file);
	
	number_elements = Write_Struct_Dir(arg_for_file, arg_for_dir, arg_for_dir);
	
	FILE *out_file = fopen(arg_for_file, "a");
	fprintf(output_file,"\nВсього файлів та каталогів у дерикторії :%d", number_elements);
	fclose(out_file);
	

	
	
	return 0;
}

















