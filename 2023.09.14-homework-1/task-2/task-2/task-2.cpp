
#include <iostream>

int main(int argc, char* argv[])
{
    int a0 = 1;
    int an = 0;
    int d = 0;
    int n = 0;
    int sum = 0;

    std::cin >> an;
    d = (an + 1) / (abs(an + 1));
    n = (abs((an - 1) / d) + 1);
    sum = ((an + 1) * n) / 2;
    std::cout << sum << std::endl;
}

