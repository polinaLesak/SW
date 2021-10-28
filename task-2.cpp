#include <iostream>
#include <locale>
#include <conio.h>
#include <cstdlib>
#include<string>

using namespace std;

int find_element();
int search_for_an_element_smaller_then_the_difference_of_the_previous_two();
int max_lenght_of_repeating_elements();

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	do
	{
		cout << "Введите номер задания (0 - чтобы выйти): ";
		cin >> n;
		switch (n)
		{
		case 0: break;
		case 1:
			find_element();
			cout << endl;
			break;
		case 2:
			search_for_an_element_smaller_then_the_difference_of_the_previous_two();
			cout << endl;
			break;
		case 3:
			max_lenght_of_repeating_elements();
			cout << endl;
			break;
		default:
			cout << "Такого задания нет" << endl;
			break;
		}
	} while (n != 0);
	return 0;
}

int* entering_filling_oneDimensional_array(int& size_of_array)
{
	cout << "Введите размер массива: ";
	cin >> size_of_array;
	int* arr = new int[size_of_array];
	srand(time(0));
	cout << "Массив :" << endl;
	for (int i = 0; i < size_of_array; i++)
	{
		arr[i] = rand() % 5 + (-2);
		cout << "[" << i + 1 << "]= " << arr[i] << endl;
	}
	return arr;
}

int find_element()
{
	int size_of_array;
	int* arr = entering_filling_oneDimensional_array(size_of_array);

	cout << "Введите число: " << endl;
	int k;
	cin >> k;

	for (int i = 0; i <= size_of_array; i++)
	{
		if (arr[i] == k)
		{
			cout << "Ваше число находится под индеском : [" << i << "]\n"; break;
		}
		if (i == size_of_array)
			cout << "Такого числа в последовательности нет" << endl;
	}
	return 0;
}

int search_for_an_element_smaller_then_the_difference_of_the_previous_two()
{
	int size_of_array;
	int* arr = entering_filling_oneDimensional_array(size_of_array);

	for (int i = 3; i < size_of_array - 2; i++)
	{
		if (arr[i] < (arr[i - 2] - arr[i - 1]))
		{
			cout << "Число соответсвующее условию:  " << "[" << i + 1 << "]";
			cout << arr[i] << "\n";
		}
	}

	return 0;
}

int max_lenght_of_repeating_elements()
{
	int size_of_array;
	int* arr = entering_filling_oneDimensional_array(size_of_array);
	int i = 0, k = 0, max_value = 0, number_of_order, t;

	while (i < size_of_array)
	{
		int p = 0;
		t = arr[i];
		while (arr[i] == t && i < size_of_array)
		{
			p++;
			i++;
		}
		if (p >= max_value)
			if (p > max_value) {
				max_value = p;
				number_of_order = t;
			}
			else  k = p;
	}

	if (max_value != k)
		cout << "Количество чисел в наиболее длинной последовательности, состоящей из " << number_of_order << ": " << max_value;
	else
		cout << "Найдено несколько максимальных последовательностей длиной " << max_value;

	cout << endl;

	return 0;
}