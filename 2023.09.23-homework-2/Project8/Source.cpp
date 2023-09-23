#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int x = 0;

	std::cin >> a;
	std::cin >> b;
	std::cin >> c;

	if (a > b) {
		x = a;
		a = b;
		b = x;
	}
	if (a > c) {
		x = a;
		a = c;
		c = x;
	}
	if (b > c) {
		x = b;
		b = c;
		c = x;
	}
	std::cout << a << " " << b << " " << c;
	return EXIT_SUCCESS;
}