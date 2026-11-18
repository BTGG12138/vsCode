#include <iostream>
#include <gtest/gtest.h> // 引入 gtest 的核心头文件

using namespace std;

// 这是一个测试用例宏。
// TestName：测试套件名（通常写模块或类的名字）
// Subtest_1：具体的测试名（描述这个测试在测什么）
TEST(TestName, Subtest_1) {
    ASSERT_TRUE(1 == 1); // 断言：确认括号里的表达式为真。如果为假，测试就会失败并报错。
}

// 测试程序的入口，和普通的 C++ main 函数一样
int main(int argc, char **argv) {
    // 初始化 gtest 框架，把命令行参数传进去（允许你在终端过滤只跑某个测试）
    testing::InitGoogleTest(&argc, argv);
    
    // 运行所有的测试用例，并返回结果（0 表示成功，1 表示有测试失败）
    return RUN_ALL_TESTS();
}