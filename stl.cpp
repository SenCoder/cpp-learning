// 为了实现泛型程序设计, C++ 设计了模板, 用于将数据类型参数化
// STL(Standard Template Library) 标准模板库是 C++ 对数据结构进行封装后的称呼.
// 函数模板

#include <iostream>
#include <string>

// template 是函数模板的关键字, <> 尖括号包围的是类型参数
// typename 是另外一个关键字, 用来声明具体的类型参数(也叫虚拟类型/类型占位符), 这里使用了类型参数 T
// typename 关键字也可以用 class 关键字代替; 原因是 c++ 早期对模板的支持并不严谨, 没有引进新的关键字而直接复用了 class, 但这样并不友好, 后来才引进 typename
// template<typename T> 被称为模板头
// 类型参数可以用在函数定义的各个位置，包括参数，返回值，和函数体
// 类型参数的命名规则在语法上与变量一样，但是使用 T、T1、T2、Type 等已经称为惯例
template<typename T>
void swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

void swap_everything() {
    using namespace std;
    int n1 = 10, n2 = 20;
    swap(&n1, &n2);
    cout << "n1: " << n1 << " n2: " << n2 << endl;

    string s1 = "first", s2 = "second";
    swap(&s1, &s2);
    cout << "s1: " << s1 << " s2: " << s2 << endl;
}

// 指针在本质上是存放地址的一个变量, 在逻辑上是独立的, 它所指向的地址可以改变, 它所指向的地址中存放的数据也可以改变.
// 引用是一个别名, 它的存在具有依附性, 必须在一开始就被初始化, 其引用对象在其整个生命周期是不能被改变的(只能依附于同一个变量).

// C++ 中引用和指针经常用于参数传递. 指针传递参数本质上是值传递。

// 类模板
// 除了支持函数模板, C++ 还支持类模板
// 类模板中支持的类型参数可以用在类的声明和类的实现中
template<typename T1, typename T2>
class Point {
private:
    T1 m_x;
    T2 m_y;

public:
    Point(T1 x, T2 y) : m_x(x), m_y(y) {};

    T1 getX() const;

    T2 getY() const;

    T1 setX(T1 x);

    T2 setY(T2 y);

    void print();
};

template<typename T1, typename T2>
T1 Point<T1, T2>::getX() const {
    return m_x;
}

template<typename T1, typename T2>
T2 Point<T1, T2>::getY() const {
    return m_y;
}

template<typename T1, typename T2>
T1 Point<T1, T2>::setX(T1 x) {
    this->m_x = x;
}

template<typename T1, typename T2>
T2 Point<T1, T2>::setY(T2 y) {
    this->m_y = y;
}

template<typename T1, typename T2>
void Point<T1, T2>::print() {
    using namespace std;
    cout << "X: " << m_x << " Y: " << m_y << endl;
}

void make_point() {
    Point<int, int> p1(10, 20);
    Point<int, float> p2(10, 15.5);
    Point<float, std::string> p3(12.4, "180 degrees east longitude");
    p3.print();

    auto *p = new Point<float, float>(10.6, 108.3);
    p->print();
    delete p;
}