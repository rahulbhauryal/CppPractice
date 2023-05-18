#pragma once
#include <iostream>
#include <stdio.h>
#include <string>

/**
* @brief This template shows how function template works along with function overloading
*/
class FunctionTemplate {
    private:
            template<typename T>
            void printMe(T num) {
                std::cout << "print in templete " << num << std:endl; 
            }

            void printMe(double num) {
                std::cout << "print in overloading " << num << std:endl; 
            }

    public:

    void playFnTemplate();
};

/**
* @brief This template shows how class template works
*/
template<typename T>
class ClassTemplate {
    private:
        T value;

    public:
        ClassTemplate() {}

        ClassTemplate(T value_):value(value_){}

        void write(T value_) {
            value = value_;
            std::cout << "ClassTemplate: write value " < value_ << std::endl;
        }

        T read() {
            std::cout << "ClassTemplate: read value " ;
            return value;
        }
};

/**
* @brief This template shows how default value parameters. 
*         The code provided is a C++ template class named "ValueTemplate".
*/
template<int size, int value = 0>
class ValueTemplate {
    private:
        int *base;
    
    public:
        ValueTemplate() {
            base = new int[size];

            for (int i = 0; i < size; i++) {
                base[i] = value;
            }
        }

        void print() {
            for (int i = 0; i < size; i++) {
                std::cout << "print:: " << base[i] << std::endl;
            }
        }
};
