#pragma once

#include <deque>

template<class T, class Comp>
std::deque<T> Merge(const std::deque<T>& half1, const std::deque<T>& half2, const Comp& comparator) {
    std::deque<T> result;
    auto it1 = half1.begin();
    auto it2 = half2.begin();
    for ( ;it1 < half1.end(); ++it1) {
        while(it2 !=half2.end() && comparator(*it2,*it1)) {
            result.push_back(*it2);
            ++it2;
        }
        result.push_back(*it1);
    }
    for ( ;it2 < half2.end(); ++it2) result.push_back(*it2);
    return result;
}

template<class T, class Comp>
std::deque<T> MergeSort(const std::deque<T>& src, const Comp& comparator) {
    if (src.size() <= 1) {
        return src;
    }
    const size_t mid = src.size() / 2;
    const std::deque<T> left = {src.begin(), src.begin() + mid};
    const std::deque<T> right = {src.begin() + mid, src.end()};
    const std::deque<T> left_sorted = MergeSort(left, comparator);
    const std::deque<T> right_sorted = MergeSort(right, comparator);
    return Merge(left_sorted, right_sorted, comparator);
}
