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
    
    int max = 0;
    for (int i = 0; i < n; ++i)
    {
        if (*(m + i) >= *(m + max))
        {
            max = i;
        }
    }

    int min = 0;
    for (int i = 0; i < n; ++i)
    {
        if (*(m + i) < *(m + min))
        {
            min = i;
        }
    }

    int p = 0;
    p = *(m + max);
    *(m + max) = *(m + min);
    *(m + min) = p;

    for (int i = 0; i < n; ++i)
    {
        std::cout << *(m + i) << " ";
    }
    free(m);
    
    return EXIT_SUCCESS;
}
