#include <iostream>

int main(int argc, char* argv[]) 
{
    int n = 0;
    int f = 0;
    int f0 = 0;
    int f1 = 1;

    std::cin >> n;

    if (n <= 2) 
    {
        std::cout << f1;
    }

    if (n > 2) 
    {
        for (int i = 2; i < n; ++i) 
        {
            f = f1 + f0;
            f0 = f1;
            f1 = f;
        }
        f += f0;

        std::cout << f << std::endl;
    }
 
    return EXIT_SUCCESS;
}
