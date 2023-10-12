#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	
	//A
	{                                  
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << j + 1 << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	//B
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << i + 1 << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	//C
	{ 
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << (i + j) % n + 1 << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	//D
	{
		for (int i = n; i > 0; --i)
		{
			for (int j = n; j > 0; --j)
			{
				std::cout << i + j - 1 << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	//E
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << std::max(std::min(i + 1, n - i), std::min(j + 1, n - j)) << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	//F
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << (i + 1) % 2 * (j + 1) + i % 2 * (n - j) << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}
