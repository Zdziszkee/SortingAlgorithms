//
// Created by zdziszkee on 12/2/23.
//
#include <iostream>
#include <vector>

void counting_sort(std::vector<int>& array) {
    const int size = array.size();
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    int counting[max + 1]{0};
    for (int i = 0; i < size; i++) {
        counting[array[i]]++;
    }
    int k = 0;
    for (int i = 0; i < max + 1; i++) {
        int count = counting[i];
        for (int j = 0; j < count; j++) {
            array[k] = i;
            k++;
        }
    }
}

auto main() -> int {
    std::vector<int> integers;

    int integer;

    while (std::cin >> integer) {
        integers.push_back(integer);
    }

    counting_sort(integers);

    for (const auto& element: integers) {
        std::cout << element << std::endl;
    }
}
