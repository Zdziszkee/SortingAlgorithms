//
// Created by zdziszkee on 12/2/23.
//
#include <iostream>
#include <vector>

template<class T>
void selection_min_max_sort(std::vector<T>& vector) {
    int start, end;
    int middle = (vector.size() - 1) / 2;
    int min_index, max_index;
    for (int i = 0; i <= middle; i++) {
        start = i;
        end = vector.size() - 1 - i;

        min_index = i;
        max_index = end;


        for (int j = i; j <= end; j++) {
            if (vector[j] < vector[min_index]) {
                min_index = j;
            } else if (vector[j] > vector[max_index]) {
                max_index = j;
            }
        }

        if (start != min_index) {
            if (vector[start] == vector[max_index]) {
                max_index = min_index;
            }
            std::swap(vector[min_index], vector[start]);
        }

        if (end != max_index) {
            std::swap(vector[max_index], vector[end]);
        }
    }
}

auto main() -> int {
    std::vector<int> integers;
        int integer;

        while (std::cin >> integer) {
            integers.push_back(integer);
        }

    selection_min_max_sort<int>(integers);

    for (const auto& element: integers) {
        std::cout << element << std::endl;
    }
}
