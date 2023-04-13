//
// Created by dejan on 4/9/23.
//

#ifndef UNTITLED_TENSOR_H
#define UNTITLED_TENSOR_H

#import <iostream>
#import "vector"
#include "sstream"

template<typename T, size_t ... args>
class Tensor {
private:
        std::vector<int> shape{{args...}};
        static constexpr size_t capacity = (args * ...);
        std::vector<T> arr;
public:
    Tensor(){
    }
    Tensor(Tensor &t):arr(t.arr){

    }
    size_t getCapacity(){
        return capacity;
    }
    size_t size(){
        return arr.size();
    }
    std::vector<int> getShape(){
        return shape;
    }
    void add(T num){
        if(arr.size()>=capacity)throw std::runtime_error("Tensor is full");
        arr.push_back(num);
    }
    T& operator[](int n){
        if(n>=arr.size())throw std::runtime_error("Out of bounds");
        return arr[n];
    }
    const T operator[](int n) const{
        if(n>=arr.size())throw std::runtime_error("Out of bounds");
        return arr[n];
    }
    auto begin() {
        return arr.begin();
    }
    auto cbegin() const {
        return arr.cbegin();
    }
    auto end() {
        return arr.end();
    }
    auto cend() const {
        return arr.cend();
    }

    std::string serialize() const {
        std::ostringstream os;
        os << "shape: ";
        for (int dim : shape){
           os << dim << ",";
        }
        os<<";,";
        os << "data: ";
        for (const T& value : arr) {
            os << value << ",";
        }
        return os.str();
    }
    static Tensor<T, args...> deserialize(const std::string& serialized) {
        std::istringstream is(serialized);
        std::string token;
        std::vector<int> tmpshape;
        std::vector<T> data;

        // parse the shape from the serialized string
        is >> token; // read the "shape:" prefix
        std::getline(is, token, ',');
        while (token!=""&&token!=";") {
            tmpshape.push_back(std::stoi(token));
            std::getline(is, token, ',');
        }

        // parse the data from the serialized string
        is >> token; // read the "data:" prefix
        std::getline(is, token, ' ');
        while (std::getline(is, token, ',')) {
            data.push_back(std::stof(token));
        }

        // create a new Tensor object and copy the data into it
        if (tmpshape.size() != sizeof...(args)) {
            throw std::runtime_error("Serialized shape does not match template arguments");
        }
        Tensor<T, args...> tensor;
        for (const auto& item : data) {
            tensor.add(item);
        }
        return tensor;
    }

};


#endif //UNTITLED_TENSOR_H
