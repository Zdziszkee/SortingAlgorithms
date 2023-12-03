//
// Created by zdziszkee on 12/3/23.
//

#include <chrono>
#include <iostream>
#include <vector>
#include <functional>
#include <fstream>

template<class T>
void bubble_sort(std::vector<T>& vector) {
    for (size_t n = 0; n < vector.size(); ++n) {
        for (size_t j = 0; j < vector.size() - n - 1; ++j) {
            if (vector[j] > vector[j + 1]) {
                std::swap(vector[j], vector[j + 1]);
            }
        }
    }
}


//insertion
template<class T>
void insertion_sort(std::vector<T>& vector) {
    for (size_t i = 0; i < vector.size(); i++) {
        for (size_t j = i; j > 0 && vector[j] < vector[j - 1]; j--) {
            std::swap(vector[j], vector[j - 1]);
        }
    }
}

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


// Selection sort
template<class T>
void selection_sort(std::vector<T>& vector) {
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

template<class T>
void benchmark(const std::function<void(std::vector<T>&)>& sorting_function, std::vector<T> integers,
               const std::string& output_file_name) {
    const auto start = std::chrono::high_resolution_clock::now();
    sorting_function(integers);
    const auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> time = end - start;
    std::ofstream output(output_file_name,std::ios::app);
    output << std::fixed << integers.size() << "\t" << time.count() << std::endl;
    if (!output.is_open()) {
        std::cerr << "Could not open " << output_file_name << std::endl;
        exit(EXIT_FAILURE);
    }
    output.close();
}

auto main() -> int {
    std::vector<int> integers;
    int integer;

    while (std::cin >> integer) {
        integers.push_back(integer);
    }
    benchmark<int>(&bubble_sort<int>, integers, "BubbleSortBenchmark");
    benchmark<int>(&insertion_sort<int>, integers, "InsertionSortBenchmark");
    benchmark<int>(&selection_min_max_sort<int>, integers, "SelectionMinMaxSortBenchmark");
    benchmark<int>(&selection_sort<int>, integers, "SelectionSortBenchmark");
    benchmark<int>(&counting_sort, integers, "CountingSortBenchmark");
}
