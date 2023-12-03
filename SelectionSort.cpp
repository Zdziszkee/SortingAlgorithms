//
// Created by zdziszkee on 12/2/23.
//
#include <iostream>
#include <vector>

// Selection sort
template<class T>
void sort(std::vector<T>& vector) {
    const size_t size = vector.size();
    for (size_t minimum = 0; minimum < size - 1; ++minimum) {
        size_t current_minimum_index = minimum;
        for (size_t current = minimum + 1; current < size; ++current) {
            if (vector[current] < vector[current_minimum_index]) {
                current_minimum_index = current;
            }
        }
        if (current_minimum_index != minimum) {
            std::swap(vector[minimum], vector[current_minimum_index]);
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
