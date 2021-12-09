//// 4 варинат 114302 Лесак
//предлагаемый вариант заполнения файла
//1 3.5 trpo 4
//3 5.6 trpo 2
//2 1.1 trpo 1



#include <iostream>
#include <fstream>
#include <string>


using namespace std;

struct Struct
{
	string word;
	int num = 0;
	double average = 0;
	int index = 0;
};

Struct* read_file(string Name, int& size);

void count_lines();

Struct* resize_array(int& oldFileSize, int newFileSize, Struct* files);

void print_task_in_file(string Name, Struct* files, int size, int openMode);

void sotr(string Name, Struct* files, int size, int openMode);

int main()
{

	int size = 1;
	setlocale(LC_ALL, "rus");
	Struct* files = read_file("trpo.txt", size);
	print_task_in_file("trpo.txt", files, size, ios_base::app);

	fstream file("trpo.txt");
	int sizeoffile = 0;
	file.seekg(0, ios::end);
	sizeoffile = file.tellg();
	cout << "В измененном файле " << sizeoffile << " байт" << endl;
	file.close();
	count_lines();
	sotr("trpo.txt", files, size, ios_base::app);
	print_task_in_file("trpo.txt", files, size, ios_base::app);
	cout << "Работа закончена" << endl;
	system("pause");

	return 0;
}



Struct* read_file(string Name, int& size)
{
	ifstream file(Name);
	if (!file.is_open())
	{
		return nullptr;
	}
	size <= 0 ? size = 10 : size = size;
	Struct* files = new Struct[size];
	int numOfLines = 0;
	while (!file.eof())
	{
		if (numOfLines == size)
		{
			files = resize_array(size, size + 1, files);
		}
		file >> files[numOfLines].num;
		file >> files[numOfLines].average;
		file >> files[numOfLines].word;
		file >> files[numOfLines].index;
		numOfLines++;
	}
	files = resize_array(size, numOfLines - 1, files);
	file.close();
	return files;
}

void count_lines()
{
	char* str = new char[1024];
	int i = 0;
	ifstream base("trpo.txt");
	while (!base.eof())
	{
		base.getline(str, 1024, '\n');
		i++;
	}
	base.close();
	delete str;
}

Struct* resize_array(int& oldFileSize, int newFileSize, Struct* files)
{
	if (oldFileSize == newFileSize)
	{
		return files;
	}
	Struct* newArray = new Struct[newFileSize];
	oldFileSize = newFileSize < oldFileSize ? newFileSize : oldFileSize;
	for (int i = 0; i < oldFileSize; i++)
	{
		newArray[i] = files[i];
	}
	oldFileSize = newFileSize;
	delete[] files;
	return newArray;
}

void print_task_in_file(string Name, Struct* files, int size, int openMode)
{
	ofstream file(Name, openMode);
	if (!file.is_open()) {
		return;
	}
	else {
		for (int i = size - 1; i >= 0; i--) {
			file
				<< files[i].num << " "
				<< files[i].average << " "
				<< files[i].word << " "
				<< files[i].index << endl;
		}
		file.close();
		cout << "Задание сделано! " << endl;
	}
}

void sotr(string Name, Struct* files, int size, int openMode)
{
	ofstream file(Name, openMode);
	if (!file.is_open()) {
		return;
	}
	else
	{
		cout << "Файл открыт!  " << endl;
	}
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (files[j].num < files[j + 1].num)
			{
				Struct temp = files[j];
				files[j] = files[j + 1];
				files[j + 1] = temp;

			}
		}
	}
	file << "Сортированный по возрастанию первых элементов массив" << endl;
	file.close();
}