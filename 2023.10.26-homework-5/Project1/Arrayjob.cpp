#include"Arrayjob.h"
#include"iostream"
#include"cstdlib"
#include"ctime"

void Menu()
{
	std::cout << "0 - Выход" << std::endl;
	std::cout << "1 - Вывести массив" << std::endl;
	std::cout << "2 - Добавить элемент в массив" << std::endl;
	std::cout << "3 - Удалить элемент из массива" << std::endl;
	std::cout << "4 - Отсортировать массив по возрастанию" << std::endl;
	std::cout << "5 - Развернуть массив" << std::endl;
	std::cout << "6 - Поменять местами максимальный и минимальный элемент массива" << std::endl;
	std::cout << "7 - Удалить из массива все дубликаты" << std::endl;
	std::cout << "8 - Добавить в массив n случайных элементов" << std::endl;
}

void printArray(int*& Array, int len)
{
	if (Array == nullptr)
	{
		std::cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << Array[i] << " ";
		}
	}
	std::cout << std::endl;
}

void addElement(int*& Array, int& len)
{
	int newlen = len + 1;
	int element = 0;
	std::cout << "Введите элемент" << std::endl;
	std::cin >> element;

	int* newArray = new int[newlen]{ 0 };
	for (int i = 0; i < len; ++i) 
	{
		newArray[i] = Array[i];
	}

	newArray[len] = element;

	delete[] Array;
	Array = newArray;
	++len;
}

void deleteElement(int*& Array, int& len)
{
	int index = 0;
	std::cout << "Введите индекс элемента, который хотите удалить" << std::endl;
	std::cin >> index;
	int newlen = len - 1;
	int* newArray = new int[newlen]{ 0 };
	for (int i = 0, j = 0; i < len; ++i)
	{
		if (i != index)
		{
			newArray[j] = Array[i];
			++i;
		}
	}
	delete[] Array;
	Array = newArray;
	--len;
}
 
void sortArray(int*& array, int len) 
{
	for (int i = 0; i < len; ++i) 
	{
		for (int j = 0; j < len - i - 1; ++j) 
		{
			if (array[j] > array[j + 1]) 
			{
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}

void reverseArray(int*& Array, int len)
{
	for (int i = 0; i < len / 2; ++i)
	{
		std::swap(Array[i], Array[len - 1 - i]);
	}
}

void swithminmax(int*& Array, int len)
{
	bool maxFound = false;
	bool minFound = false;

	int max = Array[0];
	int min = Array[0];

	for (int i = 0; i < len; ++i) 
	{
		if (Array[i] > max) 
		{
			max = Array[i];
		}
		if (Array[i] < min) 
		{
			min = Array[i];
		}
	}

	int maxIndex = 0;
	int minIndex = 0;
	for (int i = 0; i < len; ++i) 
	{
		if (Array[i] == max) 
		{
			maxIndex = i;
			break;
		}
	}
	for (int i = len - 1; i > 0; --i) 
	{
		if (Array[i] == min) 
		{
			minIndex = i;
			break;
		}
	}
	std::swap(Array[maxIndex], Array[minIndex]);
}

void deleteDuplicates(int*& Array, int& len) 
{
	int* newArray = new int[len]{ 0 };
	newArray[0] = Array[0];
	int newlen = 1; 

	for (int i = 1; i < len; ++i) 
	{
		bool isDuplicate = false;
		for (int j = 0; j < newlen; ++i) 
		{
			if (Array[i] == newArray[j]) 
			{
				isDuplicate = true;
				break;
			}
		}

		if (!isDuplicate) 
		{
			newArray[newlen] = Array[i];
			newlen++;
		}
	}	
	delete[] Array;
	Array = newArray;
	len = newlen;
}

void addRandom(int*& Array, int& len)
{
	std::cout << "Введите n" << std::endl;
	int n = 0;
	std::cin >> n;
	int newlen = len + n;

	int* newArray = new int[newlen]{ 0 };
	for (int i = 0; i < len; ++i) 
	{
		newArray[i] = Array[i];
	}

	srand(time(0));
	for (int i = len; i < len + n; ++i) 
	{
		newArray[i] = rand() % 100;
	}

	delete[] Array;
	Array = newArray;
	len += n;
}