#include <iostream>

int main(int argc, char* argv[]) {

	int n = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;

	int p1 = 15;
	int p5 = 70;
	int p10 = 125;
	int p20 = 230;
	int p60 = 440;

	std::cin >> n;

	e = n / 60;
	n %= 60;
	d = n / 20;
	n %= 20;
	c = n / 10;
	n %= 10;
	b = n / 5;
	n %= 5;
	a = n;
	if (a * p1 >= p5) {
		a = 0;
		b += 1;
	}
	if (a * p1 + b * p5 >= p10) {
		a = 0;
		b = 0;
		c += 1;
	}
	if (a * p1 + b * p5 + c * p10 >= p20) {
		a = 0;
		b = 0;
		c = 0;
		d += 1;
	}
	if (a * p1 + b * p5 + c * p10 + d * p20 >= p60) {
		a = 0;
		b = 0;
		c = 0;
		d = 0;
		e += 1;
	}
	std::cout << a << " " << b << " " << c << " " << d << " " << e;
	return EXIT_SUCCESS;
}