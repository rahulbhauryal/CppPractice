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
                printf("print in templete %s\n", std::to_string(num));
            }

            void printMe(double num) {
                printf("print in overloading %f\n", num);
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
