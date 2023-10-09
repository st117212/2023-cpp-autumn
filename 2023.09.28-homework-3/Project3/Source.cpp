#include <iostream>

int main(int argc, char* argv[]) 
{
	int a = 0;
	int k = 0;

	std::cin >> a;
	
	for (int i = 1; i <= a / 2; ++i) 
	{
		if (a % i == 0) 
		{
			k++;
		}
	}
	std::cout << k+1 << std::endl;

	return EXIT_SUCCESS;
}
