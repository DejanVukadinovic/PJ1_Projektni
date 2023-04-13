//
// Created by dejan on 4/8/23.
//

#ifndef UNTITLED_BINARYOPERATION_H
#define UNTITLED_BINARYOPERATION_H

#include "Node.h"

template <typename T>
class BinaryOperation: public Node<T> {
public:
    T virtual getValue(T arg1, T arg2){};
    std::string virtual serialize(){};

};


#endif //UNTITLED_BINARYOPERATION_H
