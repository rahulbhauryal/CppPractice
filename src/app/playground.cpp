#include "playground.h"
#include "play01Templates.h"
#include <memory>

void Playground::PlayTemplate() {
    FunctionTemplate playFnTmp;
    playFnTmp.playFnTemplate();

    ClassTemplate<int> playClassTemplate1(100);
    std::cout << "read value: " << playClassTemplate1.read() << std::endl;

    // class template using unique pointers
    std::unique_ptr<ClassTemplate<std::string>> playClassTemplate2;
    playClassTemplate2 = std::make_unique<ClassTemplate<std::string>>("hi");
    std::cout << "read value: " << playClassTemplate2->read() << std::endl;

    // default value parameter
    ValueTemplate<5, 100> valueTemplate1;
    valueTemplate1.print();

    ValueTemplate<3> valueTemplate2;
    valueTemplate2.print();

}