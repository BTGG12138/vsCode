#include <iostream>

// ================= 基类（父亲） =================
class Base {
public:
    int pub_val = 1;      // 公开：谁都能看
protected:
    int prot_val = 2;     // 受保护：只有自己和儿子能看
private:
    int priv_val = 3;     // 私有：只有自己能看

public:
    // 1. 本类内部视角：三个全都能访问
    void testInsideBase() {
        std::cout << "--- 在 Base 类内部 ---" << std::endl;
        pub_val = 10; 
        prot_val = 20; 
        priv_val = 30; 
        std::cout << "pub_val: " << pub_val 
                  << ", prot_val: " << prot_val 
                  << ", priv_val: " << priv_val << std::endl;
    }
};

// ================= 派生类（儿子） =================
class Derived : public Base {
public:
    // 2. 派生类内部视角：能访问 public 和 protected，不能访问 private
    void testInsideDerived() {
        std::cout << "--- 在 Derived 类内部 ---" << std::endl;
        pub_val = 100;    // ✅ OK
        prot_val = 200;   // ✅ OK：儿子可以碰父亲的 protected
        // priv_val = 300; // ❌ 取消注释这行会编译报错：private 只有父亲自己能碰
        
        std::cout << "pub_val: " << pub_val 
                  << ", prot_val: " << prot_val << std::endl;
    }

    // ⚠️ 高级易错点：儿子只能通过“儿子自己”或“孙子”访问继承的 protected
    void testProtectedTrap(Base& b, Derived& d) {
        // b.prot_val = 1000; // ❌ 取消注释报错：儿子不能通过“父亲的对象”碰 protected
        d.prot_val = 2000;    // ✅ OK：儿子可以通过“儿子的对象”碰 protected
        this->prot_val = 3000; // ✅ OK：儿子可以通过“自己”碰 protected
    }
};

// ================= 类外部视角（路人） =================
int main() {
    std::cout << "--- 在 main 函数（类外部） ---" << std::endl;
    
    Base b;
    b.pub_val = 10;        // ✅ OK：public 所有人都能碰
    // b.prot_val = 20;    // ❌ 取消注释报错：外部不能碰 protected
    // b.priv_val = 30;    // ❌ 取消注释报错：外部不能碰 private
    
    b.testInsideBase();    // 调用父亲内部的测试函数

    Derived d;
    d.testInsideDerived(); // 调用儿子内部的测试函数
    
    // d.prot_val = 40;    // ❌ 取消注释报错：哪怕是通过儿子对象，外部也不能碰 protected
    
    // 验证 protected 的易错点
    d.testProtectedTrap(b, d); 
    std::cout << "testProtectedTrap 运行成功，d.prot_val 变为了 3000" << std::endl;

    return 0;
}