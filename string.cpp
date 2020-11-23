//
// Created by Neo_Y on 2020/11/19.
//

//C 中的 struct 只能包含变量，不能包含成员函数; C++ 中 struct 类似于 class, 可以包含成员变量和成员函数.
//C++ 中 struct 与 class 的区别:
//  class 默认 private, struct 默认 public
//  class 默认 private 继承, struct 默认 public 继承
//  class 可使用模板 , struct 不能

#include <iostream>
#include <string>

//C++ 增强了对 string 的支持，内置了 string 类, 用来替换 C 中的字符数组或字符串指针

void make_string() {
    using namespace std;
    string s1;
    string s2 = "hello, string";
    string s3 = s2;

    cout << s2.length() << endl;
    for (int i = 0, len = s2.length(); i < len; i++) {
        cout << s2[i] << " ";
    }
    cout << endl;
    s2[5] = ' ';
    cout << s2 << endl;

    // string 可以和 char* char[] string 通过 + 运算进行字符串拼接
}

// using 用法总结
// 1）配合命名空间，对命名空间权限进行管理
// using namespace std; //释放整个命名空间到当前作用域
// using std::cout;    //释放某个变量到当前作用域
// 2) 类型重命名
// 作用等同typedef，但是逻辑上更直观。
typedef std::string TString;   //! 使用typedef的方式
using Ustring = std::string;   //！使用 using typeName_self = stdtypename;
