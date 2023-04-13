//
// Created by dejan on 4/8/23.
//

#ifndef UNTITLED_TENSORSUBTRACTION_H
#define UNTITLED_TENSORSUBTRACTION_H

#include "BinaryOperation.h"
#include "exception"

template<typename T>
class TensorSubtraction: public BinaryOperation<T> {
private:
    T data;
public:
    T getValue(T arg, T arg2) override {
        if(arg.size()!=arg2.size())throw std::runtime_error("Wrong format");
        T res(arg);
        for (int i = 0; i < res.size(); ++i) {
            res[i]-=arg2[i];
        }
        data=res;
        return res;
    }
    std::string serialize() override {
        std::string res = "data";
        for(auto el:data){
            std::cout<<el<<"\n";
        }

        return res;
    }

};


#endif //UNTITLED_TENSORSUBTRACTION_H
