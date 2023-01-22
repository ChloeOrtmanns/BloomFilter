//
// Created by chloe on 7/01/2023.
//

#ifndef INC_07_PROJECT_HASHER_H
#define INC_07_PROJECT_HASHER_H
#include <string>

template <typename ElementType>

class Hasher {
public:
    std::size_t c;                       // constant initial value
    explicit Hasher(std::size_t c);      // constructor
    std::size_t operator() (ElementType e) const;
};

// explicit template instantiation
template class Hasher<std::string>;


#endif //INC_07_PROJECT_HASHER_H
