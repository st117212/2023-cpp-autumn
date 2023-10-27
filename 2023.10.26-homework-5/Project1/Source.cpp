#include"iostream"
#include "Arrayjob.h"


int main(int argc, char* argv[])
{
	int len = 0;
	std::cout << "Введите размер массива" << std::endl;
	std::cin >> len;

	std::cout << "Введите элементы массива" << std::endl;
	int* Array = new int[len] { 0 };
	for (int i = 0; i < len; i++)
	{
		std::cin >> Array[i];
	}

	bool exit = false;
	while (!exit)
	{
		{
			system("cls");
			Menu();
		}
		int choice = 0;
		std::cin >> choice;

		{
			switch (choice)
			{
			case 0:
			{
				exit = true;
				break;
			}
			case 1:
			{
				printArray(Array, len);
				system("pause");
				break;
			}
			case 2:
			{
				addElement(Array, len);
				break;
			}
			case 3:
			{
				deleteElement(Array, len);
				break;
			}
			case 4:
			{
				sortArray(Array, len);
				break;
			}
			case 5:
			{
				reverseArray(Array, len);
				break;
			}
			case 6:
			{
				swithminmax(Array, len);
				break;
			}
			case 7:
			{
				deleteDuplicates(Array, len);
				break;
			}
			case 8:
			{
				addRandom(Array, len);
				break;
			}
			default:
			{
				std::cout << "Unknown command" << std::endl;
				break;
			}

			}

		}
	}
	
	
	delete[] Array;
	return EXIT_SUCCESS;
}