

#include <iostream>
using namespace std;
main()
{
	int a, b, c, d;
	cin >> a >> b;
	c = a * b % 109;
	d = (c + 109) % 109 + 1;
	cout << d;
}