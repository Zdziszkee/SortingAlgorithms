//
// Created by zdziszkee on 12/2/23.
//
#include <iostream>
#include <random>
std::random_device rd;
std::mt19937 gen(rd());

auto main(int argc, char** argv) -> int {
    if (argc != 3) {
        std::cerr << "You must specify the amount of numbers (n) and upper number range (max)!" << std::endl;
    }

    const int n = std::stoi(argv[1]);
    const int max = std::stoi(argv[2]);


    std::uniform_int_distribution<int> r_num(1, max);

    for (int i = 0; i < n; ++i) {
        std::cout << r_num(gen) << std::endl;
    }
}
