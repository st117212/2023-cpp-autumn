#include <iostream>

int main(int argc, char* argv[]) {
    int y = 0;

    std::cin >> y;

    if (((y % 4) == 0) && ((y % 100) != 0) || ((y % 400) == 0)) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }
    return EXIT_SUCCESS;
}