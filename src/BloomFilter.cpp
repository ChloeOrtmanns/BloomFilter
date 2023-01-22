//
// Created by chloe on 8/01/2023.
//

#include "../include/BloomFilter.h"

#include <utility>
#include <vector>

template <typename ElementType>
BloomFilter<ElementType>::BloomFilter(
        size_t bit_size,
        std::vector<std::size_t> hash_initialization_constant) :
        bit_size(bit_size),
        hash_initialization_constant(std::move(hash_initialization_constant)) {
            bits.resize(bit_size, false);
        }

template <typename ElementType>
void BloomFilter<ElementType>::insert(const ElementType& e) {
    // insert an elementtype e in BloomFilter
    for (int i = 0; i < hash_initialization_constant.size(); i++) {
            const Hasher<ElementType> h(hash_initialization_constant[i]);
            const std::size_t string_hash = h(e);
            size_t index = string_hash % bit_size;
            bits[index] = true;
        }
}

template <typename ElementType>
bool BloomFilter<ElementType>::query(const ElementType& e) {
    for (int i = 0; i < hash_initialization_constant.size(); i++) {
        const Hasher<ElementType> h(hash_initialization_constant[i]);
        const std::size_t string_hash = h(e);
        size_t index = string_hash % bit_size;
        if (!bits[index]) {
            return false;
        }
    }
    return true;
}

template <typename ElementType>
bool BloomFilter<ElementType>::is_full() const {
    for (int i = 0; i < bit_size; i ++) {
        if (!bits[i])
            return false;
        else
            if (i == bit_size-1 && bits[bit_size - 1])
                return true;
    }
}

template<typename ElementType>
size_t BloomFilter<ElementType>::getBitSize() const {
    return bit_size;
}

template<typename ElementType>
const std::vector<bool> &BloomFilter<ElementType>::getBf() const {
    return bits;
}
