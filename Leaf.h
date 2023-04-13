//
// Created by dejan on 4/8/23.
//

#ifndef UNTITLED_LEAF_H
#define UNTITLED_LEAF_H
#include "Node.h"

template<typename T>
class Leaf : public Node<T> {
private:
    T data;
    static T dummy;
public:
    Leaf(){}
    Leaf(T initialData):data(initialData){}
    Leaf(std::string s){
        T tmp = T::deserialize(s);
        data = tmp;
    }
    T getValue() override{
        return data;
    }
    std::string serialize() override {
        return data.serialize();
    }
};


#endif //UNTITLED_LEAF_H
