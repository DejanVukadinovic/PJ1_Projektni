#include <iostream>
#include "Node.h"
#include "Leaf.h"
#include "vector"
#include "TensorAddition.h"
#include "BinaryOperation.h"
#include "TensorSubtraction.h"
#include "HadamarMultiplication.h"
#include "TensorInvert.h"
#include "ScalarMultiply.h"
#include "ScalarAdd.h"
#include "Graph.h"
#include "Tensor.h"


void test(int n, std::vector<int>...){

}

int main() {
    /*
    Leaf<std::vector<int>> l({1,2,3});

    std::vector<int> v2={4,5,6};


    TensorAddition<std::vector<int>> ta;
    TensorSubtraction<std::vector<int>> ts;
    HadamarMultiplication<std::vector<int>> th;
    TensorInvert<std::vector<int>> ti;
    ScalarMultiply<std::vector<int>> sm(2);
    ScalarAdd<std::vector<int>> sa(2);


    if(dynamic_cast<Node<std::vector<int>>*>(&l)!= nullptr){
        std::cout<<"something\n";
    }
    if(dynamic_cast<Leaf<std::vector<int>>*>(&ta)== nullptr){
        std::cout<<"Not a leaf\n";
    }
    if(dynamic_cast<BinaryOperation<std::vector<int>>*>(&ta)!= nullptr){
        std::cout<<"BinaryOperation\n";
    }
    std::vector<int> v = l.getValue();

    std::vector<int> v3 = ta.getValue(v,v2);
    std::vector<int> v4 = ts.getValue(v2,v);
    std::vector<int> v5 = th.getValue(v2,v);
    std::vector<int> v6 = ti.getValue(v2);
    std::vector<int> v7 = sm.getValue(v2);
    std::vector<int> v8 = sa.getValue(v2);

    for(auto el:v3){
        std::cout<<el<<"   ";
    }
    std::cout<<"\n";
    for(auto el:v4){
        std::cout<<el<<"   ";
    }
    std::cout<<"\n";
    for(auto el:v5){
        std::cout<<el<<"   ";
    }
    std::cout<<"\n";
    for(auto el:v6){
        std::cout<<el<<"   ";
    }
    std::cout<<"\n";
    for(auto el:v7){
        std::cout<<el<<"   ";
    }
    std::cout<<"\n";
    for(auto el:v8){
        std::cout<<el<<"   ";
    }
    std::cout<<"\n";

    Graph<std::vector<int>> gr;

    gr.add(l);
    gr.add(ta);
    gr.add(l);

    gr.addRel(1,2);
    gr.addRel(0,1);
    gr.addRel(1,0);
    std::vector v9 = gr.calculate(1);
    gr.printRel();
    for(auto el:v9){
        std::cout<<el<<"   ";
    }
    std::cout<<"\n";
     */


    Tensor<double, 3,4,5> ten;
    ScalarAdd<Tensor<double, 3,4,5>> sat(2.0);
    TensorAddition<Tensor<double, 3,4,5>> tat;

    ten.add(2.3);
    ten.add(3.2);
    ten.add(4.0);
    std::cout<<ten.size()<<"\n";
    for(auto el: ten){
       // std::cout<<el<<"   ";
    }
    Tensor<double, 3,4,5> ten1 = tat.getValue(ten, ten);
    for(auto el: ten1){
        //std::cout<<el<<"   ";
    }

    std::string sten = ten1.serialize();
    //std::cout<<sten<<"\n";
    Tensor<double, 3,4,5> ten2 = Tensor<double, 3,4,5>::deserialize(sten);
    for(auto el: ten2){
        //std::cout<<el<<"   ";
    }
    Graph<Tensor<double, 3,4,5>> graph2;
    Leaf<Tensor<double, 3,4,5>> tl(ten);
    ScalarAdd<Tensor<double, 3,4,5>> tsa(5);


    graph2.add(tl);
    graph2.add(tl);
    graph2.add(tl);
    graph2.add(tsa);
    //std::cout<<"\n";
    //std::cout<<graph2.serialize();
    std::string sgraph = graph2.serialize();
    std::string sgraph2 = graph2.serialize();
    //std::cout<<"===========================================================================\n";
    Graph<Tensor<double, 3,4,5>> graph3 = Graph<Tensor<double, 3,4,5>>::deserialize(sgraph);
    Graph<Tensor<double, 3,4,5>> graph4(sgraph);
    std::string sgraph3 = graph4.serialize();
    std::cout<<"===========================================================================\n";
    std::cout<<sgraph3;
    //graph3.serialize();

    /*
    Tensor<double, 3,4,5> ten;
    ten.add(2.3);
    ten.add(3.2);
    ten.add(4.0);
    Leaf<Tensor<double, 3,4,5>> tl(ten);
    std::string stl = tl.serialize();
    std::cout<<"\n";
    std::cout<<stl;
    Leaf<Tensor<double, 3,4,5>> tl2(stl);
    std::string stl2 = tl2.serialize();
    std::cout<<"\n";
    std::cout<<stl2;
    Leaf<Tensor<double, 3,4,5>> tl3(stl2);
    std::string stl3 = tl3.serialize();
    std::cout<<"\n";
    std::cout<<stl2
    */
     return 0;

}
