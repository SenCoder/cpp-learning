#include <iostream>
#include <cstdio>  // cstdio/cstdlib 位于 std 命名空间； stdio.h/stdlib.h 等没有命名空间，位于全局作用域
#include <string>
#include "oop.h"

// 如果希望在所有函数中使用 std 命名空间，可以在这里添加，更方便; 但在大型项目中，不推荐这样做
// using namespace std;


int sum(int n) {
//    c++ 中变量的定义不强制要求在函数开头
    int total = 0;
    for (int i = 0; i < n; i ++) {
        total += i;
    }
    return total;
}

int main() {
//    :: 域解析操作符
    std::cout << "Hello, World!" << std::endl;
    std::printf("hello, c++\n");

    using namespace std;
    string str;
    int age;

//    C 中的 scanf printf c++ 也支持, 但是 c++ 提供了 cin/cout/cerr
//    cin/cout/cerr 都是 c++ 内置对象而不是关键字
//    cin istream 的对象；cout ostream 的对象
//    endl 与 '\n' 的作用相同
//    非 int 类型的输入会被转化为 int 后输入 age
    cin >> str >> age;
    cout << str << age << endl;

//    c++ 支持 bool 类型， 但是 cout bool 类型的结果依然为 0/1
//    bool flag = true;

//    c++/c 中 const 的作用域都是当前文件, 但可见范围不同; c 中 const 整个程序可见（extern）, c++ 中仅当前文件可见
//    c 中用 malloc 和 free 动态管理内存; c++ 使用 new 和 delete 分配堆内存
//    int *p = new int[10];
//    delete[] p;
//    int *p = new int;
//    delete p;

//    c++ 支持内联函数，在函数定义处添加 inline 关键字（声明处不用）, 这样实际上会将函数调用处的代码替换为 inline 函数的代码
//    一般只建议对较小的函数这样做; 对较大的函数大量使用内联函数，会造成编译后程序体积变大
//    与一般函数不同,内联函数的定义可以放在头文件中，被 include 多次也不会发生重复定义的错误; 非内联函数禁止定义在头文件中
//    内联函数虽然叫做函数，定义和声明也与一般函数类似，但是它已经失去了函数的本质
//    函数是一段可以重用的代码，位于虚拟地址空间中的代码区，占用可执行文件的体积; 而内联函数的代码在编译后就消除了
//    实践中, 可将内联函数放在头文件中，并禁用内联函数的声明，将函数定义放在本应该出现函数声明的地方

//    c++ 和 python 一样, 支持为形参指定默认参数
//    c++ 中带默认参数的形参必须在函数参数列表的最后
//    c++ 中支持函数重载: 多个函数名字相同, 但是其参数列表不同; 返回值类型不同不能作为重载的依据, 重载函数的返回之类型可以相同或不同
//    重载仅仅是语法方面的方便，事实上在编译的时候，多个重载函数的名称会依据类型不同而被替换

//    char *name = "mary";
    makeStudent((char*)"mary", 12, 98.5);
    return 0;
}
