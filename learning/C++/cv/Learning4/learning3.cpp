#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    std::unordered_map<int, string> cpp_students;
    cpp_students.emplace(1509, "Nacho");
    cpp_students.emplace(2000, "Pepe");
    cpp_students.emplace(8820, "Marcelo");
    // 随便加点“捣乱”的数据，凑满 15 个
    for (int i = 0; i < 12; ++i) {
        cpp_students.emplace(i * 100, "Test");
    }

    cout << "当前哈希表桶的总数量: " << cpp_students.bucket_count() << endl;

    for (const auto& [id, name] : cpp_students) {
        cout << "id: " << id 
             << ", 名字: " << name 
             << " | 所在桶索引: " << cpp_students.bucket(id) 
             << " | 哈希值: " << std::hash<int>{}(id) << endl;
    }
    return 0;
}
/*
数据量下，GCC 会对 int 哈希直接取模映射到桶，如果余数恰好递增，遍历时就会看似有序。
GCC 常采用头插法。如果你刚好按大小升序插入，倒序遍历输出就会变成降序。
原形毕露：一旦插入数据过多触发 Rehash（扩容重排），或者遇到哈希冲突（不同数据算出的桶索引相同），输出顺序瞬间“群魔乱舞”。
铁律：C++ 标准绝不保证 unordered_map 的遍历顺序！ 任何依赖其输出顺序的代码都是不可移植的定时炸弹。

无论你定义的容器本身是不是 const，使用 cbegin() 返回的迭代器都是只读的。
作用：它不仅能防止你手滑修改了原本不该改的数据，还能作为一种“意图声明”。编译器看到 const 迭代器，还能进行更好的优化。

rbegin()：返回指向容器最后一个元素的反向迭代器。
rend()：返回指向第一个元素前面位置的反向迭代器。
*/