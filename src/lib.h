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

int Check_Write_In_Data(char *arr_input_date[], FILE *output_file, DIR *input_dir);

int Create_Struct_Dir(DIR *input_dir, struct dirent *elemets_in_dir, char *arr_out_data[]);

int Write_In_File(FILE *output_file, char *arr_out_data[]);
