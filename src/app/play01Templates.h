#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <functional>
#include <memory>

/**
* @brief This template shows how function template works along with function overloading
*/
class FunctionTemplate {
    private:
            template<typename T>
            void printMe(const T num){
                std::cout << "print in templete " << num << std::endl; 
            }

            void printMe (const double num){
                std::cout << "print in overloading " << num << std::endl;
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
        ClassTemplate(){}

        explicit ClassTemplate(const T &value_):value(value_){}

        void write(const T &value_) {
            value = value_;
            std::cout << "ClassTemplate: write value " << value_ << std::endl;
        }

        // it's important to note that you should only declare a member function as const if it genuinely does not modify any member variables of the class. If the function performs any modifications, 
        // such as updating internal state or member variables, it should not be declared as const.
        T read() const{
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
        ValueTemplate(): base(new int[size]) {
            if (base == nullptr) {
                // error assigning memory. Take measures.
                return;
            }

            for (int i = 0; i < size; i++) {
                base[i] = value;
            }
        }

        ~ValueTemplate() {
            delete[] base;
        }

        void print() const{
            for (int i = 0; i < size; i++) {
                std::cout << "print:: " << base[i] << std::endl;
            }
        }
};

/**
 * @brief Type template parameters. class and typename have same meaning. default type and size.
 * 
 */
template<typename T>
int SizeTypename(T num) {
    return(sizeof(num));
}

template<class T>
int SizeClass(T num) {
    return(sizeof(num));
}

template<typename T = int, int size = 10>
class Register {
    private:
        //T *value;
        std::unique_ptr<T[]> value; ///  declares a std::unique_ptr named value without initializing it. 
                                    ///  The <> angle brackets indicate that it is managing a dynamic array of type T. 
                                    /// The square brackets [] indicate that it is a pointer to an array.

    public:
        Register() : value(std::make_unique<T[]>(size)) {
            //value = new T[size];
            //std::memset(value, 0, size*sizeof(T));

            // Initializing member variables in the initialization list can be more efficient because it allows the compiler to directly 
            // initialize the variable instead of first default-initializing it and then assigning a new value in the constructor body.
            //value = std::make_unique<T[]>(size);  /// std::make_unique<T[]>(size) is a function that constructs 
                                                  /// and returns a std::unique_ptr pointing to a dynamically 
                                                  /// allocated array of type T with a size specified by the size argument.          
        }

        ~Register() {
            //delete(value);
        }

        void Print() const{
            for (int cnt = 0; cnt < size; cnt++) {
                std::cout << "Register::Print: " << cnt << " : val = " << value[cnt] << std::endl;
            }
        }

        void Set(const int index,const T value_) {
            bool isValid = index >= 0 && index < size;

            if (isValid) {
                value[index] = value_;
            }
        }

};

/**
 * @brief Templete templete parameter. Template parametrs are  themselves class templetes.
 * 
 *          Parameter MUST be a CLASS templete
 * 
 */
template<typename T, size_t size>
class GenericClass{
    private:
        std::unique_ptr<T[]> value;
    
    public:
        GenericClass(): value(std::make_unique<T[]>(size)) {
        }

        //T& operator[](size_t index) {
        //return value[index];
        //}        
};

template<template<typename T, size_t size> class C, typename T, size_t size>
size_t eSize(C<T, size> &ref) {
    T tmpVeriable;
    return sizeof(T);
};

/* TODO: below code does not work
template<template<typename T, size_t size> class C, typename T, size_t size>
void fillGenericClassData(C<T, size> &ref, size_t index, T num) {
    //ref[index] = num;
};

template<template<typename T, size_t size> class C, typename T, size_t size>
void printGenericClassData(C<T, size> &ref) {
    std::cout << "printGenericClassData: ";
    for (size_t i = 0; i < size; i++) {
       // std::cout << "  " << ref[i];
    }
};
*/


/**
 * @brief Member template: Member templates in C++ allow you to define a template
 *        inside a class that can work with different types of members. They provide
 *        flexibility and reusability in code by allowing you to define generic member 
 *        functions or member variables.
 * 
 */

class DummyUart {
    public:
        void write(std::unique_ptr<char[]> data, size_t size) {
            std::cout << "Sending data bytes using UART... ";
            for (size_t i = 0; i < size; i++) {
                std::cout << data.get()[i] << ", ";
            }
        }
};

class DummySpi {
    public:
        void write(std::unique_ptr<char[]> data, size_t size) {
            std::cout << "Sending data bytes using SPI... ";
            for (size_t i = 0; i < size; i++) {
                std::cout << data.get()[i] << ", ";
            }
        }
};

template<typename T = char, size_t size = 5>
class GenericDataClass {
    private:
        std::unique_ptr<T[]> data;

    public:
        GenericDataClass():data(std::make_unique<T[]>(size)) {
            std::memset(data.get(), 'R', size);
        }

        // local nested class can not have member template
        template<typename P>
        void writeApb(P &p) {
            p.write(std::move(data), size);
        }
};
