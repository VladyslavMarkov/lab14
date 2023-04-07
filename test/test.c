#include "../src/lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <check.h>
#include <math.h>

START_TEST(test_CreateConst_EasySentence)
{	
	char test_str[] = "Я роблю домашнє завдання";
	long int expected_res = 1578;
	long int actual_res = CreateConst(test_str);
	
	ck_assert_int_eq(expected_res, actual_res);
}
END_TEST

START_TEST(test_CreateConst_HardSentence)
{	
	char test_str[] = "То мати пирогів напече, то бабуся з булочками приїде.";
	long int expected_res = 247626196;
	long int actual_res = CreateConst(test_str);
	
	ck_assert_int_eq(expected_res, actual_res);
}
END_TEST

START_TEST(test_CreateConst_SentenceWithNumber)
{	
	char test_str[] = "Я народився у 1999";
	long int expected_res = 1914;
	long int actual_res = CreateConst(test_str);
	
	ck_assert_int_eq(expected_res, actual_res);
}
END_TEST

START_TEST(test_CreateConst_EnglishQuestion)
{	
	char test_str[] = "Who are you?";
	long int expected_res = 333;
	long int actual_res = CreateConst(test_str);
	
	ck_assert_int_eq(expected_res, actual_res);
}
END_TEST

START_TEST(test_CreateConst_NoSentence)
{	
	char test_str[] = "\0";
	long int expected_res = 0;
	long int actual_res = CreateConst(test_str);
	
	ck_assert_int_eq(expected_res, actual_res);
}
END_TEST

START_TEST(test_CreateConst_BigWord)
{	
	char test_str[] = "Що таке паралелепіпед?";
	long int expected_res = 2413;
	long int actual_res = CreateConst(test_str);
	
	ck_assert_int_eq(expected_res, actual_res);
}
END_TEST

Suite *lab_test_suite(void)
{
	Suite *s;
	TCase *tc_CreateConst;

	s = suite_create("lab13");

	tc_CreateConst = tcase_create("CreateConst");

	tcase_add_test(tc_CreateConst, test_CreateConst_EasySentence);
	tcase_add_test(tc_CreateConst, test_CreateConst_HardSentence);
	tcase_add_test(tc_CreateConst, test_CreateConst_SentenceWithNumber);
	tcase_add_test(tc_CreateConst, test_CreateConst_EnglishQuestion);
	tcase_add_test(tc_CreateConst, test_CreateConst_NoSentence);
	tcase_add_test(tc_CreateConst, test_CreateConst_BigWord);

	suite_add_tcase(s, tc_CreateConst);

	return s;
}

int main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = lab_test_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
