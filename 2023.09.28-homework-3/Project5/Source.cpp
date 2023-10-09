#include <iostream>

int main(int argc, char* argv[])
{
    int k = 0;
    int a = 0;
    std::cin >> k;

    for (int i = 1; i <= k; ++i) 
    {
        int j = i;
        int b = 0;
        while (j > 0) 
        {
            b = j % 10 + b * 10;
            j = j / 10;
        }
        if (b == i) {
            a += 1;
        }
    }

    std::cout << a << std::endl;
    return EXIT_SUCCESS;
}
