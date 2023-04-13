//
// Created by dejan on 4/8/23.
//

#ifndef UNTITLED_SCALARADD_H
#define UNTITLED_SCALARADD_H

#include "UnaryOperation.h"
#include "exception"

template<typename T>
class ScalarAdd : public UnaryOperation<T>{
private:
    T data;
    double scalar;
public:
    ScalarAdd(double scalar):scalar(scalar){}
    T getValue(T arg) override {
        T res(arg);
        for (int i = 0; i < res.size(); ++i) {
            res[i]+=scalar;
        }
        data=res;
        return res;
    }
    std::string serialize() override {
        std::string res = std::to_string(scalar);

        return res;
    }
};
#endif //UNTITLED_SCALARADD_H
