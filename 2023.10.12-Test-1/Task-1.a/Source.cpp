#include <iostream>

int main(int argc, char** argv)
{
	int res = 0;
	int n = 0;
	std::cin >> n;

	for (int i = 0; i <= 31; ++i)
	{
		if ((n >> (31 - i) & 1) == 1)
		{
			++res;
		}
	}

	std::cout << res << std::endl;

	return EXIT_SUCCESS;
}