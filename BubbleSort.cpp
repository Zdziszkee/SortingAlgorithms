//
// Created by zdziszkee on 12/2/23.
//

#include <iostream>
#include <vector>

template<class T>
void sort(std::vector<T>& vector) {
    for (size_t n = 0; n < vector.size(); ++n) {
        for (size_t j = 0; j < vector.size() - n -1; ++j) {
            if (vector[j] > vector[j+1]) {
                std::swap(vector[j], vector[j+1]);
            }
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
