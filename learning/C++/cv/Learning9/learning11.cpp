#include <iostream>
#include <type_traits>

template<class Element>
struct tree_iterator {
    tree_iterator& operator++() { return *this; }
};

template<class Element>
struct vector_iterator {
    vector_iterator& operator++() { return *this; }
    vector_iterator operator+(int) const { return *this; }
};

template<class E> struct vector { using iterator = vector_iterator<E>; };
template<class E> struct set    { using iterator = tree_iterator<E>; };

// 探测：能不能做 it + int
template<typename Iter, typename = void>
struct has_plus : std::false_type {};

template<typename Iter>
struct has_plus<Iter, std::void_t<decltype(std::declval<Iter>() + 0)>>
    : std::true_type {};

// 两个版本 advance_n，根据特征自动选择
template<typename Iter>
void advance_n(Iter& it, int n, std::true_type /* random access */) {
    it = it + n;
    std::cout << "随机访问：直接 +n\n";
}

template<typename Iter>
void advance_n(Iter& it, int n, std::false_type /* bidirectional */) {
    for(int i=0; i<n; ++i) ++it;
    std::cout << "双向迭代器：循环 ++\n";
}

template<typename Iter>
void advance_n(Iter& it, int n) {
    advance_n(it, n, has_plus<Iter>{});
}

int main() {
    vector<int>::iterator vit;
    set<int>::iterator sit;
    advance_n(vit, 5);
    advance_n(sit, 5);
    return 0;
}
