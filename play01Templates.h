#pragma once
#include <iostream>
#include <stdio.h>
#include <string>

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
