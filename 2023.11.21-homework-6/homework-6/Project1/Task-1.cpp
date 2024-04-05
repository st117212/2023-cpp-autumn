#include<iostream>

void hanoi(int n, int from, int to);

int main(int argc, char* argv[])
{
	hanoi(2, 1, 3);
	std::cout << std::endl;
	hanoi(3, 1, 3);
	std::cout << std::endl;

	return EXIT_SUCCESS;
}

void hanoi(int n, int from, int to)
{
	if (n <= 0)
	{
		return;
	}

	int temp = n - from - to;
	hanoi(n - 1, from, temp);
	std::cout << n << " " << from << " " << to;
	hanoi(n - 1, temp, to);
}