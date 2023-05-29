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

TEST(TempleteTest, ClassTemplateSpecialization) {
    GenericArray<int,3> g1;
    GenericArray<int,2> g2;    
    g2.setValue(5, 4);
    ASSERT_EQ(g2.sum(), 9);

    (void)g1;
    //g1.sum(); /// ILLEGAL: does not exists
}


TEST(TempleteTest, ClassTemplatePartialSpecialization) {
    PartialGenericArray<int, 30> partialGenericArray;
    partialGenericArray.set(5, 3);

    ASSERT_EQ(partialGenericArray.read(5), 3);
}