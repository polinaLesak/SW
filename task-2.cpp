#include <iostream>
#include <locale>
#include <conio.h>
#include <cstdlib>
#include<string>

using namespace std;

int find_element();


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


