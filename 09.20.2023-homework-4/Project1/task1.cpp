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

    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        if (*(m + i) > 0)
        {
            k += 1;
        }
    }
    std::cout << k;
    free(m);
    
    return EXIT_SUCCESS;
}
