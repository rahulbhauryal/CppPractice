#include <gtest/gtest.h>
#include "../../src/app/play01Templates.h"

// Test class templete
TEST(TempleteTest, ClassTemplateTest) {
    ClassTemplate<int> playClassTemplate(100);
    ASSERT_EQ(playClassTemplate.read(), 100);

    playClassTemplate.write(50);
    ASSERT_EQ(playClassTemplate.read(), 50);
}


// Test class templete using unique pointer
TEST(TempleteTest, ClassTemplateTestUniquePointer) {
    std::string testString = "Hi Test";
    std::unique_ptr<ClassTemplate<std::string>> playClassTemplate;
    playClassTemplate = std::make_unique<ClassTemplate<std::string>>(testString);
    ASSERT_EQ(playClassTemplate->read(), testString);

    testString = "Hi Test again";
    playClassTemplate->write(testString);
    ASSERT_EQ(playClassTemplate->read(), testString);
}


// Test class templete using unique pointer
TEST(TempleteTest, ClassTemplateSeprateMethodDefinitions) {
    SepMetRegister SepMethodDef1(100);
    ASSERT_EQ(SepMethodDef1.read(), 100);
    SepMethodDef1.write(50);
    ASSERT_EQ(SepMethodDef1.read(), 50);
}