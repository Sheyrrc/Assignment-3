#include "RecursiveLinearSearch.h"

template int recursiveLastOccurrence<int>(std::vector<int> const& vec, int target, int index);

template <typename T>
int recursiveLastOccurrence(std::vector<T> const& vec, T target, int index) {
    if (index == vec.size() - 1) {
        return vec[index] == target ? index : -1;
    }
    int result = recursiveLastOccurrence(vec, target, index + 1);
    return result != -1 ? result : (vec[index] == target ? index : -1);
}
