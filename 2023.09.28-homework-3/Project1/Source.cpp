#include <iostream>

int main(int argc, char* argv[]) {
    int a = 0;
    std::cin >> a;
    int b = a;

    for (int i = 1; i <= a; ++i) {
        for (int j = 1; (j <= i) && (b > 0); j++) {
            std::cout << i << " ";
            b--;
        }
    }

    return EXIT_SUCCESS;
}