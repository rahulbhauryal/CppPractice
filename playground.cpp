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

}