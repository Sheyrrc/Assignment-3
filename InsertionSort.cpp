#include "InsertionSort.h"

template void insertionSort<int>(std::vector<int>& vec);

template <typename T>
void insertionSort(std::vector<T>& vec) {
    for (std::size_t i = 1; i < vec.size(); ++i) {
        T key = vec[i];
        std::size_t j = i - 1;
        while (j < vec.size() && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}
