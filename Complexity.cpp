//
// Created by zdziszkee on 12/3/23.
//
#include <iostream>
#include <vector>
// Selection sort
template<class T>
void sort(std::vector<T>& vector) {
    const size_t size = vector.size();
    int number_of_swaps = 0;
    int number_of_comparisons = 0;

    for (size_t minimum = 0; minimum < size - 1; minimum++) {
        size_t current_minimum_index = minimum;
        for (size_t current = minimum + 1; current < size; current++) {
            if (vector[current] < vector[current_minimum_index]) {
                current_minimum_index = current;
            }
            number_of_comparisons++;
        }
        if (current_minimum_index != minimum) {
            std::swap(vector[minimum], vector[current_minimum_index]);
            number_of_swaps++;
        }
    }
    std::cout << number_of_comparisons<<std::endl;
    std::cout << number_of_swaps<<std::endl;

}

auto main() -> int {
    std::vector<int> integers;

    int integer;

    while (std::cin >> integer) {
        integers.push_back(integer);
    }


    sort<int>(integers);
}
