#include "playground.h"
#include "play01Templates.h"
#include <memory>

void Playground::PlayTemplate() {
    std::cout << "\n************* Templete *************" << std::endl;
    std::cout << "\n>> Function templete : " << std::endl;
    FunctionTemplate playFnTmp;
    playFnTmp.playFnTemplate();

    std::cout << "\n>> Class templete : " << std::endl;
    ClassTemplate<int> playClassTemplate1(100);
    std::cout << "read value: " << playClassTemplate1.read() << std::endl;

    // class template using unique pointers
    std::unique_ptr<ClassTemplate<std::string>> playClassTemplate2;
    playClassTemplate2 = std::make_unique<ClassTemplate<std::string>>("hi");
    std::cout << "read value: " << playClassTemplate2->read() << std::endl;

    std::cout << "\n>> Default value templete : " << std::endl;
    // default value parameter
    ValueTemplate<5, 100> valueTemplate1;
    valueTemplate1.print();

    ValueTemplate<3> valueTemplate2;
    valueTemplate2.print();

    std::cout << "\n>> Type templete parameter : " << std::endl;
}