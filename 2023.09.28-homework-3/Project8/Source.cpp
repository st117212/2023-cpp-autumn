#include <iostream>

int main(int argc, char* argv[]) {
	int a = 0;
	int b = 0;
	int n = 0;
	int ost = 0;
	int r = 0;
	int m = 0;
	char an = 'A';
	char bn = 'B';

	std::cin >> a;
	std::cin >> b;
	std::cin >> n;

	int a1 = a;
	int b1 = b;
	while (b1 != 0) {
		ost = a1 % b1;
		a1 = b1;
		b1 = ost;
	}

	if (a < b) {
		m = a;
		a = b;
		b = m;
		an = 'B';
		bn = 'A';
	}
	
	if ((a < n) || (n % a1 != 0)) {
		std::cout << "Impossible" << std::endl;
		return 0;
	}

	if (n == a) {
		std::cout << ">" << an << std::endl;
		return 0;
	}
	else {
		while (true) {
			r += b;
			std::cout << ">" << bn << std::endl;
			std::cout << bn << ">" << an << std::endl;

			if (r >= a) {
				std::cout << an << ">" << std::endl;
				std::cout << bn << ">" << an << std::endl;
				r %= a;
			}

			if ((r == n) || (r == 0)) {
				break;
			}
		}
	}

	return EXIT_SUCCESS;
}