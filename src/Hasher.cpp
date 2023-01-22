//
// Created by chloe on 7/01/2023.
//

#include "../include/Hasher.h"

template <typename ElementType> Hasher<ElementType>::Hasher(size_t c) : c(c) {}

template <typename ElementType> std::size_t Hasher<ElementType>::operator() (ElementType e) const {
    uint64_t H = 0;
    char Cletter, hash_index;
    size_t initial_value = c;
    uint64_t shifted_c;                         // 8 bytes large, so 8 times '0000 0000'
    for (int i = 0; i < e.length(); i++) {
        Cletter = e[i];                         // takes the i-th character his ascii-bin value in C, eg. A = 01000001
        hash_index = i % 8;                     // is 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
        char toshift = hash_index * 8;          // says how many bytes it'll shift (because 8 bits = 1 byte)
        shifted_c = Cletter << (toshift);       // shift C (bv '01000001') # bytes to the left in the 8 byte large shifted_c
        shifted_c = shifted_c * initial_value;  // use the initial value to change the value uniquely
        H = H ^ shifted_c;                      // H XOR shifted_c => overlays shifted_c over H, simple XOR use
    }
    return H;
}