#include <iostream>

int main(int argc, char* argv[]) {
    int n = 0;
    int k = 1;
    int a = 0;

    std::cin >> n;

    while (k < n) {
        k *= 2;
        a += 1;
    }

    std::cout << a << std::endl;
    return EXIT_SUCCESS;
}