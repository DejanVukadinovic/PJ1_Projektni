//
// Created by dejan on 4/8/23.
//

#ifndef UNTITLED_UNARYOPERATION_H
#define UNTITLED_UNARYOPERATION_H

#include "Node.h"

template <typename T>
class UnaryOperation : public Node<T> {
public:
    T virtual getValue(T arg){};
    std::string virtual serialize(){};
};


#endif //UNTITLED_UNARYOPERATION_H
