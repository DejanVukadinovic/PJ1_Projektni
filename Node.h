//
// Created by dejan on 4/8/23.
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H
#include "string"

template<typename T>
class Node {
public:
    T virtual getValue(){};
    T virtual getValue(T arg){};
    T virtual getValue(T arg, T arg2){};
    std::string virtual serialize(){};
};


#endif //UNTITLED_NODE_H
