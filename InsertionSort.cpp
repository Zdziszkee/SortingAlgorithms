//
// Created by zdziszkee on 12/2/23.
//
#include <iostream>
#include <vector>

template<class T>
void sort(std::vector<T>& vector) {
    for (size_t i = 0; i < vector.size(); i++) {
        for (size_t j = i; j > 0 && vector[j] < vector[j - 1]; j--) {
            std::swap(vector[j], vector[j - 1]);
        }
    }
}

auto main() -> int {
    std::vector<int> integers;
    int integer;

    while (std::cin >> integer) {
        integers.push_back(integer);
    }

    sort<int>(integers);

    for (const auto& element: integers) {
        std::cout << element << std::endl;
    }
}
