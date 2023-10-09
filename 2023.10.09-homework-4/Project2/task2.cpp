#include <iostream>
#include <cstdlib>

int main(int, char**)
{
    int n;
    std::cin >> n;

    int* m = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> *(m + i);
    }

    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            std::cout << *(m + i) << " ";
        }
    }
    free(m);
    
    return EXIT_SUCCESS;
}
