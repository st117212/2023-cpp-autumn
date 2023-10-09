#include <iostream>

int main(int argc, char* argv[]) 
{
	int a = 0;
	int b = 0;

	std::cin >> a;
	
	while (a) 
	{
		b = (b * 10) + (a % 10);
		a /= 10;
	}
	
	std::cout << b << std::endl;
	return EXIT_SUCCESS;
}
