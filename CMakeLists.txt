cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp Node.h Leaf.h UnaryOperation.h BinaryOperation.h TensorAddition.h TensorSubtraction.h HadamarMultiplication.h TensorInvert.h ScalarMultiply.h ScalarAdd.h Graph.h Tensor.h)
