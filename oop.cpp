//
// Created by Neo_Y on 2020/11/18.
//

#include <iostream>

class Student {
private:
//    成员变量大都以m_开头，这是约定成俗的写法，不是语法规定的内容
    float m_salary;
//    初始化 const 成员变量的唯一方法就是使用初始化列表
//    const int m_sex;

public:
//    类只是一个模板, 编译后不占用内存空间, 所以类的定义不能对成员进行初始化; 只有对象才可以
    char *m_name;
    int m_age;
    float m_score;

//    在一个类体中，private 和 public 可以分别出现多次。每个部分的有效范围到出现另一个访问限定符或类体结束时（最后一个右花括号）为止。
//    但是为了使程序清晰，应该养成这样的习惯，使每一种成员访问限定符在类定义体中只出现一次。

//    声明构造函数
//    如果用户自己没有定义构造函数，那么编译器会自动生成一个默认的构造函数，只是这个构造函数的函数体是空的，也没有形参，也不执行任何操作
//    构造函数必须是 public 属性的，否则创建对象时无法调用。当然，设置为 private、protected 属性也不会报错，但是没有意义
    Student();

    Student(char *name, int age, float score);

    Student(char *name, int age);

//    析构函数（Destructor）也是一种特殊的成员函数，没有返回值，不需要程序员显式调用（程序员也没法显式调用），而是在销毁对象时自动执行
//    析构函数没有参数，不能被重载，因此一个类只能有一个析构函数。如果用户没有定义，编译器会自动生成一个默认的析构函数
    ~Student();

    void say() {
        using namespace std;
        cout << "student: " << m_name << " " << m_age << " " << m_score << " " << m_salary << endl;
    }

    void set_salary(float salary);
};

Student::Student() {

}

Student::Student(char *name, int age, float score) {
    m_name = name;
    m_age = age;
    m_score = score;
}

//采用初始化列表
//成员变量的初始化顺序与初始化列表中列出的变量的顺序无关，它只与成员变量在类中声明的顺序有关
Student::Student(char *name, int age) : m_name(name), m_age(age) {
    //TODO:
}

void Student::set_salary(float salary) {
//    this 是 C++ 中的一个关键字，也是一个 const 指针，它指向当前对象，通过它可以访问当前对象的所有成员。
//    this 只能用在类的内部，通过 this 可以访问类的所有成员
//    this 是 const 指针，它的值是不能被修改的，一切企图修改该指针的操作，如赋值、递增、递减等都是不允许的
//    只有当对象被创建后 this 才有意义，因此不能在 static 成员函数中使用
//    m_salary = salary;
    this->m_salary = salary;
}

Student::~Student() {

}

class Graduate {
public:
    char *name;
    int age;
    float score;

    // 成员方法在类内声明，但在类外实现
    void say();
};

//类外实现的成员函数必须加上类名
//域解析符（也称作用域运算符或作用域限定符），用来连接类名和函数名，指明当前函数属于哪个类
//在类体中和类体外定义成员函数是有区别的：在类体中定义的成员函数会自动成为内联函数，在类体外定义的不会
//内联函数一般不是我们所期望的，它会将函数调用处用函数体替代，所以建议在类体内部对成员函数作声明，而在类体外部进行定义，这是一种良好的编程习惯
//如果希望类外实现的函数变成内联函数，可以添加 inline 关键字
void Graduate::say() {
    using namespace std;
    cout << "graduate: " << name << " " << age << score << endl;
}

//在类体外定义 inline 函数的方式，必须将类的定义和成员函数的定义都放在同一个头文件中（或者同一个源文件中），否则编译时无法进行嵌入
//inline void Graduate::say() {
//    using namespace std;
//    cout<<"graduate: "<<name<<" "<< age << score << endl;
//}


void makeStudent(char *name, int age, float score) {
//    class Student mary; 也是 OK 的
    // 创建对象
    Student mary;
    mary.m_name = name;
    mary.m_age = age;
    mary.m_score = score;
    mary.set_salary(36000);
    mary.say();
    // 创建对象数组
//    Student studs[100];

//    在堆上创建对象，对内存需要程序员自行管理
//    调用没有参数的构造函数也可以省略括号
    Student *peter = new Student;
    peter->m_name = (char *) "peter";
    peter->m_age = 13;
    peter->m_score = 97;
    peter->say();
//    释放内存，否则会内存泄露
    delete peter;
}