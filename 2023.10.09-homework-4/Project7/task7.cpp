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
        if (*(m + i) <= 0)
        {
            for (int j = i; j < n - 1; ++j)
            {
                *(m + j) = *(m + 1 + j);
            }
            --n;
            --i;
        }
    }
    
    for (int i = 0; i < n; ++i)
    {
        std::cout << *(m + i) << " ";
    }
    free(m);
    
    return EXIT_SUCCESS;
}
