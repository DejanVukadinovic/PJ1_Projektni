//
// Created by dejan on 4/8/23.
//

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H

#include "vector"
#include "Node.h"
#include "exception"
#include "Leaf.h"
#include "UnaryOperation.h"
#include "BinaryOperation.h"
#include "sstream"
#include <utility>
#include "memory"

#include "TensorInvert.h"
#include "TensorAddition.h"
#include "TensorSubtraction.h"
#include "ScalarMultiply.h"
#include "ScalarAdd.h"
#include "HadamarMultiplication.h"

template<typename T>
class Graph {
private:
    std::vector<Node<T>*> nodes;
    std::vector<std::vector<int>> rel;
public:
    Graph(){}
    Graph(std::string s){
        std::istringstream is(s);
        std::string token;
        std::vector<T> data;
        std::getline(is, token, '\n');
        for (int i = 0; i < std::stoi(token); ++i) {
            std::cout<<"\nprocessing\n";
            std::string nodeType;
            std::getline(is, nodeType, '\n');
            std::string initializator;
            std::getline(is, initializator, '\n');
            if(nodeType== typeid(Leaf<T>).name()){
                std::cout<<"leaf\n";
                std::cout<<initializator<<"\n";
                Leaf<T>* tmp = new Leaf<T>(initializator);
                std::cout<<tmp->serialize()<<"\n\n\n";
                nodes.push_back(tmp);
            }else if(nodeType == typeid(ScalarAdd<T>).name()){
                std::cout<<"scalarAdd\n";
                ScalarAdd<T>* tmp = new ScalarAdd<T>(std::stod(initializator));
                nodes.push_back(tmp);
            }else if(nodeType == typeid(HadamarMultiplication<T>).name()){
                std::cout<<"hadamur\n";
                HadamarMultiplication<T>* tmp = new HadamarMultiplication<T>;
                nodes.push_back(tmp);

            }else if(nodeType == typeid(ScalarMultiply<T>).name()){
                std::cout<<"scalarMulti\n";
                ScalarMultiply<T>* tmp = new ScalarMultiply<T>(std::stod(initializator));
                nodes.push_back(tmp);

            }else if(nodeType == typeid(TensorAddition<T>).name()){
                std::cout<<"tensorAdd\n";
                TensorAddition<T>* tmp = new TensorAddition<T>;
                nodes.push_back(tmp);

            }else if(nodeType == typeid(TensorInvert<T>).name()){
                std::cout<<"TensorInvert\n";
                TensorInvert<T>* tmp = new TensorInvert<T>;
                nodes.push_back(tmp);

            }
            else if(nodeType == typeid(TensorSubtraction<T>).name()){
                std::cout<<"TensorSubtraction\n";
                TensorSubtraction<T>* tmp = new TensorSubtraction<T>;
                nodes.push_back(tmp);

            }
            std::vector<int> tmp;

            for(int i=0; i<nodes.size();i++){
                tmp.push_back(0);
                if(i!=nodes.size()-1){
                    rel[i].push_back(0);
                }
            }
            rel.push_back(tmp);
            std::cout<<"145     "<<serialize()<<"\n\n";
            std::cout<<"\n\n\n\n";
        }
    }

    void add(Node<T> &n){
        nodes.push_back(&n);
        std::vector<int> tmp;
        if(nodes.size()==1){
            tmp.push_back(0);
            rel.push_back(tmp);
            return;
        }
        for(int i=0; i<nodes.size();i++){
            tmp.push_back(0);
            if(i!=nodes.size()-1){
                rel[i].push_back(0);
            }
        }
        rel.push_back(tmp);
    }
    void addRel(int x, int y){
        rel[x][y]=1;
    }
    void print(){
        int count =0;
        for(auto el:nodes){
            std::cout<<count<<": "<<el<<"\n";
            count++;
        }
    }
    void printRel(){
        for(auto el:rel){
            std::cout<<"[ ";
            for(auto elem:el){
                std::cout<<elem<<" ";
            }
            std::cout<<"]\n";
        }
    }
    T calculate(int n){
     std::vector<int> currentRels;
     for(int i=0;i<nodes.size();i++){

        if(rel[n][i]){currentRels.push_back(i);
        }
     }
     if(dynamic_cast<Leaf<T>*>(nodes[n])!=nullptr){
        return nodes[n]->getValue();
     }
     else if(dynamic_cast<UnaryOperation<T>*>(nodes[n])!=nullptr){
        return nodes[n]->getValue(this->calculate(currentRels[0]));
     }
     else if(dynamic_cast<BinaryOperation<T>*>(nodes[n])!=nullptr){
         return nodes[n]->getValue(this->calculate(currentRels[0]), this->calculate(currentRels[1]));
     }
    }
    std::string serialize(){
        std::ostringstream os;
        os<<nodes.size();
        os<<"\n";
        for (int i = 0; i < nodes.size(); ++i) {
            os<<typeid(*nodes[i]).name();
            os<<"\n";
            os<<nodes[i]->serialize();
            os<<"\n";
        }
        for(auto el:rel){
            for(auto elem:el){
                os<<elem<<" ";
            }
            os<<"\n";
        }
        return os.str();
    }
    static Graph<T> deserialize(std::string s){
        Graph<T> res;
        std::istringstream is(s);
        std::string token;
        std::vector<T> data;
        std::getline(is, token, '\n');
        for (int i = 0; i < std::stoi(token); ++i) {
            std::cout<<"\nprocessing\n";
            std::string nodeType;
            std::getline(is, nodeType, '\n');
            std::string initializator;
            std::getline(is, initializator, '\n');
            if(nodeType== typeid(Leaf<T>).name()){
                std::cout<<"leaf\n";
                std::cout<<initializator<<"\n";
                Leaf<T> tmp(initializator) ;
                std::cout<<tmp.serialize()<<"\n\n\n";
                res.add(tmp);
                std::cout<<"118     "<<res.serialize()<<"\n\n";
            }else if(nodeType == typeid(ScalarAdd<T>).name()){
                std::cout<<"scalarAdd\n";
                ScalarAdd<T> tmp(std::stod(initializator));
                res.add(tmp);
            }else if(nodeType == typeid(HadamarMultiplication<T>).name()){
                std::cout<<"hadamur\n";
                HadamarMultiplication<T> tmp;
                res.add(tmp);
            }else if(nodeType == typeid(ScalarMultiply<T>).name()){
                std::cout<<"scalarMulti\n";
                ScalarMultiply<T> tmp(std::stod(initializator));
                res.add(tmp);
            }else if(nodeType == typeid(TensorAddition<T>).name()){
                std::cout<<"tensorAdd\n";
                TensorAddition<T> tmp;
                res.add(tmp);
            }else if(nodeType == typeid(TensorInvert<T>).name()){
                std::cout<<"TensorInvert\n";
                TensorInvert<T> tmp;
                res.add(tmp);
            }
            else if(nodeType == typeid(TensorSubtraction<T>).name()){
                std::cout<<"TensorSubtraction\n";
                TensorSubtraction<T> tmp;
                res.add(tmp);
            }
            std::cout<<"145     "<<res.serialize()<<"\n\n";
            std::cout<<"\n\n\n\n";
        }

        return res;
    }

};


#endif //UNTITLED_GRAPH_H
