/*!
\file lib.h
\brief Бібіиотечный файл

Це файл, який містить декларацію функції CreateConst.
*/

/**
Функція mul_matrix
 \param a[] - масив у якому зберігається строка яку ввів користувач.
 \return Повертає сформоване число або нуль.
*/

int Check_Write_In_Data(int number_arguments, char *arr_arguments[]);

int* Write_Struct_Dir(char arg_for_file[],char present_dir[],char parents_dir[]);

int Write_Out_File(char element[],int type, char arg_for_file[],char present_dir[],char parents_dir[]);
