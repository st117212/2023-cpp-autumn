#include <iostream>


int main(int argc, char* argv[])
{
	int v, t = 0;

	std::cin >> v;
	std::cin >> t;

	int l = v * t;

	std::cout << ((((l % 109) + 109) % 109) + 1) << std::endl;
	EXIT_SUCCESS
}