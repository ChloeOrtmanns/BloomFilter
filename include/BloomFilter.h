//
// Created by chloe on 8/01/2023.
//

#ifndef INC_07_PROJECT_BLOOMFILTER_H
#define INC_07_PROJECT_BLOOMFILTER_H
#include "../include/Hasher.h"
#include <string>
#include <vector>

template <typename ElementType>

class BloomFilter {
  public:
    // constructor for the size of the bloomfilter
    BloomFilter(
            std::size_t bit_size,
            std::vector<std::size_t> hash_initialization_constant
            );

    // methods of the class
    size_t getBitSize() const;
    const std::vector<bool> &getBf() const;

    void insert(const ElementType& e);
    bool query(const ElementType& e);
    bool is_full() const;

  private:
    // initial values you put inside your bloomfilter
    std::size_t bit_size;
    std::vector<std::size_t> hash_initialization_constant;
    std::vector<bool> bits;
};

// explicit template instantiation
template class BloomFilter<std::string>;

#endif //INC_07_PROJECT_BLOOMFILTER_H
