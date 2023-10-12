#include<iostream>

int main(int argc, char* argv[])
{
	unsigned short int a = 0;
	std::cin >> a;

	unsigned short int b = 0;
	std::cin >> b;

	int c = 0;

	while (b != 0)
	{
		c = a & b;
		a ^= b;
		b = c << 1;
	}

	std::cout << a << std::endl;

	return EXIT_SUCCESS;
}