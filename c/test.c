#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

struct test_object
{
	char* name;
	double amount;
};

typedef struct test_object t_obj;

t_obj* create_array(int amount);
void remove_array(t_obj* arr, int size);
void fill_array(t_obj* arr, int size);
double array_sum(t_obj* arr, int size);

int main()
{
	const int tests_amount = 10;
	double total = 0.;
	clock_t start, end;
	double diff;
	unsigned int array_size = 10000000;
	for (int i = 0; i < tests_amount; ++i) 
	{
		start = clock();
		t_obj* const arr = create_array(array_size);
		fill_array(arr, array_size);
		double sum = array_sum(arr, array_size);
		printf("%.0lf\n", sum);
		remove_array(arr, array_size);
		end = clock();

		diff =(double)(end - start);
		total += diff;
		printf("Elapsed: %.0lf ms.\n", diff);
	}
	double mean = (double)total / tests_amount;
	printf("Mean: %.2lf\n", mean);
	return 0;
}

t_obj* create_array(int amount)
{
	return (t_obj*)malloc(sizeof(t_obj) * amount);
}

void remove_array(t_obj* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		free(arr[i].name);
	}
	free(arr);
}

void fill_array(t_obj* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i].name = (char*)malloc(17);
		_itoa(i, arr[i].name, 10);
		arr[i].amount = i;
	}
}

double array_sum(t_obj* arr, int size)
{
	double sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += arr[i].amount;
	}
	return sum;
}