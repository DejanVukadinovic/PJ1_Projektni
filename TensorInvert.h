//
// Created by dejan on 4/8/23.
//

#ifndef UNTITLED_TENSORINVERT_H
#define UNTITLED_TENSORINVERT_H

#include "UnaryOperation.h"
#include "exception"

template<typename T>
class TensorInvert : public UnaryOperation<T>{
private:
    T data;
public:
    T getValue(T arg) override {
        T res(arg);
        for (int i = 0; i < res.size(); ++i) {
            res[i]*=(-1);
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


#endif //UNTITLED_TENSORINVERT_H
