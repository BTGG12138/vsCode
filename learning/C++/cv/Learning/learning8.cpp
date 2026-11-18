/*
class Base {}; // 父类（比如叫“动物”）
class Derived : public Base {}; // 子类（比如叫“狗”）
Derived* d_ptr = new Derived(); // 创建一只狗，d_ptr 是牵狗的绳子（指针）
Base* b_ptr = static_cast<Base*>(d_ptr); // 把狗绳当成动物绳来用（向上转型）

class Animal { public: virtual void makeSound() { cout << "动物叫\n"; } };
class Dog : public Animal { public: void makeSound() override { cout << "汪汪\n"; } };
class Cat : public Animal { public: void makeSound() override { cout << "喵喵\n"; } };

// 重点来了！只需要这一个函数！
// 不管你传进来的是狗、猫、还是猪，我都当作“动物（Animal）”来处理
void vaccinate(Animal* a) {
    cout << "打疫苗中... ";
    a->makeSound(); // 此时会根据实际传入的对象，自动调用对应的叫声！
}
int main() {
    Dog* d = new Dog();
    Cat* c = new Cat();

    // 向上转型（隐式发生）
    vaccinate(d); 
    vaccinate(c); 
}

栈内存用于短期存储，与函数或类的作用域紧密相关。它的管理是自动的（后进先出，LIFO），
访问速度很快，但容量通常较小（例如，在Linux上默认可能只有8MB）。所有局部变量通常都分配在栈上。
堆内存用于长期存储，其生命周期由程序员显式控制（通过 new 和 delete）。
堆的容量可以非常大（可达系统物理内存大小），但分配和释放速度较慢，因为涉及操作系统的调用。
如果需要在多个作用域或线程间共享大型数据，就必须使用堆内存。

.cpp	独立编译单元	普通函数的实现、main 函数	绝不包含（否则会报重复定义）
.hpp	对外接口	类定义、函数声明、宏、全局变量声明	被 .cpp 包含
.ipp	内联实现	inline 函数的实现代码	被 .hpp 包含
.tpp	模板实现	template 模板的实现代码	被 .hpp 包含

局部变量的生命周期，就是它所在作用域从 `{` 到 `}`
*/