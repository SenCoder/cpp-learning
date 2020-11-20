//
// Created by Neo_Y on 2020/11/18.
//

#include <iostream>
#include <string>

class Student {
private:
//    成员变量大都以m_开头，这是约定成俗的写法，不是语法规定的内容
    float m_salary;
//    初始化 const 成员变量的唯一方法就是使用初始化列表
//    const int m_sex;
    static int s_total;

public:
//    类只是一个模板, 编译后不占用内存空间, 所以类的定义不能对成员进行初始化; 只有对象才可以
    char *m_name;
    int m_age;
    float m_score;
//    静态成员变量，多个实例共享数据
//    静态成员变量必须在类外部初始化，而且必须初始化，否在就不会被分配内存空间; 初始化时可以赋值或不赋值
//    静态成员变量可以通过类或者对象访问，也受类的访问权限控制


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
    virtual ~Student();

//    const 成员函数可以访问成员变量，但不能修改成员变量的值
    void say() const {
        using namespace std;
        cout << "student: " << m_name << " " << m_age << " " << m_score << " " << m_salary;
//        static 成员变量的内存不是在声明类的时候分配，也不是在对象创建时分配，而是在类外初始化时分配
//        即使类没有实例化， static 成员变量也可以访问，它就想一个全局变量，内存分配独在全局数据区
        cout << " total: " << s_total << endl;
    }

    void set_salary(float salary);

//    静态成员函数只能访问静态成员，不能访问 this 指针或非静态成员变量/函数
//    普通函数也可被 static 关键字修饰，其特点是: 静态函数不能被其它文件所用；其它文件中可以定义相同名字的函数，不会发生冲突；
    static int get_total();

//    声明非成员函数为友元函数
//    允许函数 exam 访问 Student 的私有成员
//    还可以使用 friend class 声明友元类
//    友元的关系时单向的; 友元关系不能传递
    friend void exam(Student *p);

    void say_hello();
    void say_goodbye();
};

Student::Student() {
    s_total++;
}

Student::Student(char *name, int age, float score) {
    m_name = name;
    m_age = age;
    m_score = score;
    s_total++;
}

//采用初始化列表
//成员变量的初始化顺序与初始化列表中列出的变量的顺序无关，它只与成员变量在类中声明的顺序有关
Student::Student(char *name, int age) : m_name(name), m_age(age) {
    //TODO:
    s_total++;
}

int Student::s_total = 0;

void Student::set_salary(float salary) {
//    this 是 C++ 中的一个关键字，也是一个 const 指针，它指向当前对象，通过它可以访问当前对象的所有成员。
//    this 只能用在类的内部，通过 this 可以访问类的所有成员
//    this 是 const 指针，它的值是不能被修改的，一切企图修改该指针的操作，如赋值、递增、递减等都是不允许的
//    只有当对象被创建后 this 才有意义，因此不能在 static 成员函数中使用
//    m_salary = salary;
    this->m_salary = salary;
}

int Student::get_total() {
    return s_total;
}

void Student::say_hello() {
    using std::cout;
    using std::endl;
    cout << "hello hello ..." << endl;
}

void Student::say_goodbye() {
    using std::cout;
    using std::endl;
    cout << "goodbye ";
}

Student::~Student() {
    using std::cout;
    using std::endl;
    s_total--;
    cout<< m_name << ": student destructed" <<endl;
}

class SeniorStudent : public Student {
public:
    using Student::say_goodbye;
    SeniorStudent(char *name, int age, float score):Student(name, age, score){};
    ~SeniorStudent() {
        using std::cout;
        using std::endl;
        cout<< m_name << ": senior student destructed" <<endl;
    };

    void say_hello();
    void say_goodbye(std::string someone);
};

void SeniorStudent::say_hello() {
//    子类中调用父类方法
    using std::cout;
    cout << "I am " << this->m_name << ", ";
    Student::say_hello();
}

void SeniorStudent::say_goodbye(std::string someone) {
    using std::cout;
    using std::endl;

    Student::say_goodbye();
    cout<< someone << endl;
}

void exam(Student *p) {
    using namespace std;
    cout << p->m_name << " " << p->m_salary << endl;
}

// 提前声明类
class School;

class Graduate {
private:
    const int m_sex;
public:
    char *m_name;
    int m_age;
    float m_score;

    Graduate(char * name, int sex);

    // 成员方法在类内声明，但在类外实现
    void say();
    void info(School *sgl);
};

class School {
private:
    char *m_name;
    char *m_address;
    // 允许类 Graduate 的 info 方法访问 school 的 private/protected/public 属性
    friend void Graduate::info(School *sgl);
public:
    School(char * name, char * m_address);
};


//类外实现的成员函数必须加上类名
//域解析符（也称作用域运算符或作用域限定符），用来连接类名和函数名，指明当前函数属于哪个类
//在类体中和类体外定义成员函数是有区别的：在类体中定义的成员函数会自动成为内联函数，在类体外定义的不会
//内联函数一般不是我们所期望的，它会将函数调用处用函数体替代，所以建议在类体内部对成员函数作声明，而在类体外部进行定义，这是一种良好的编程习惯
//如果希望类外实现的函数变成内联函数，可以添加 inline 关键字
void Graduate::say() {
    using namespace std;
    cout << "graduate: " << m_name << " sex: " << m_sex << " age: " << m_age;
    cout << " score: " << m_score << endl;
}

Graduate::Graduate(char * name, int sex) : m_sex(sex) {
    this->m_name = name;
}

void Graduate::info(School *sgl) {
    using namespace std;
    cout << "graduate: " << m_name << " school: " <<  sgl->m_address << " " << sgl->m_name <<endl;
}

School::School(char *name, char *address) : m_name(name), m_address(address) {

}

//在类体外定义 inline 函数的方式，必须将类的定义和成员函数的定义都放在同一个头文件中（或者同一个源文件中），否则编译时无法进行嵌入
//inline void Graduate::say() {
//    using namespace std;
//    cout<<"graduate: "<<name<<" "<< age << score << endl;
//}


void make_student(char *name, int age, float score) {

    using namespace std;
//    class Student mary; 也是 OK 的
//    创建对象
    Student mary;
    mary.m_name = name;
    mary.m_age = age;
    mary.m_score = score;
    mary.set_salary(36000);
    mary.say();

//     创建对象数组
//    Student studs[100];

//    在堆上创建对象，对内存需要程序员自行管理
//    调用没有参数的构造函数也可以省略括号
    Student *peter = new Student;
    peter->m_name = (char *) "peter";
    peter->m_age = 13;
    peter->m_score = 97;
    peter->set_salary(19000);
    peter->say();
    exam(peter);
//    释放内存，否则会内存泄露
    delete peter;
//    cout << "total: " << Student::get_total() << endl;

//    const 对象一旦初始化后不允许修改
    const class Student tidy((char *) "tidy", 11, 96);
    tidy.say();

    Graduate g((char *)"sunny", 1);
    School sgl((char *)"Hang Xinglu school", (char *)"Zhejiang Yuhang Liangzhu");
    g.say();
    g.info(&sgl);

//    通过基类指针只能访问派生类的成员变量，不能访问派生类的成员函数; 为了消除这种尴尬, C++ 设计了虚函数
//    基类指针指向基类对象就使用基类的成员，指向派生类的对象，就使用派生类的成员。这种基类指针可以有多种形态和表现方式，我们称之为多态
//    C++ 中虚函数的作用是构成多态
//    构造函数不能声明为虚函数，析构函数可以是虚函数；虚函数必须实现，否则编译会报错
//    纯虚函数的声明如下：
//    virtual void function1()=0;
//    如果类包含纯虚函数，这个类就称为抽象类。抽象类一般作为基类使用，无法被实例化，类似于接口。
//    纯虚函数的作用类似于接口，用来规范子类的行为。
//    一般，我们将基类的析构函数声明为虚函数

    SeniorStudent shelly((char *) "shelly", 8, 100);
    shelly.say_hello();
    shelly.say_goodbye("sunny");

//    基类中采用的是非虚析构函数，当删除基类指针指向的派生类对象时就不会触发动态绑定，因而只会调用基类的析构函数，而不会调用派生类的析构函数。
//    如果派生类中申请了内存空间，并在析构函数中释放，这种情况因为派生类虚函数未调用，会产生内存泄露。
//    为了防止这种情况的发生，C++中基类的析构函数应采用virtual虚析构函数。
    Student *anna = new SeniorStudent((char *) "anna", 8, 98);
    delete anna;
}
