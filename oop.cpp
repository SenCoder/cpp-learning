//
// Created by Neo_Y on 2020/11/18.
//

#include <iostream>

class Student {
public:
//    类只是一个模板, 编译后不占用内存空间, 所以类的定义不能对成员进行初始化; 只有对象才可以
    char *name;
    int age;
    float score;

    void say() {
        using namespace std;
        cout << name << " " << age << " " << score << endl;
    }
};

void makeStudent(char *name, int age, float score) {
//    class Student mary; 也是 OK 的
    // 创建对象
    Student mary;
    mary.name = name;
    mary.age = age;
    mary.score = score;
    mary.say();
    // 创建对象数组
//    Student studs[100];

//    在堆上创建对象，对内存需要程序员自行管理
    Student *peter = new Student;
    peter->name = (char*)"peter";
    peter->age = 13;
    peter->score = 97;
    peter->say();
//    释放内存，否则会内存泄露
    delete peter;
}