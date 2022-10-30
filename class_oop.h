#ifndef CPP1_CLASS_OOP_H
#define CPP1_CLASS_OOP_H
#endif //CPP1_CLASS_OOP_H
#include<string>
using std::string;
/*
 * 访问权限:
 * 类成员的访问权限由高到低依次为 public --> protected --> private，public 成员可以通过对象来访问，
 * private 成员不能通过对象访问。protected 成员和 private 成员类似，也不能通过对象访问。但是当存在继承关系时，
 * protected 和 private 就不一样了，基类中的 protected 成员可以在派生类中使用，而基类中的 private 成员不能在派生类中使用。
 * ---------------------------------------------------------------------------------------------------------------------------------
 * public继承方式:
    基类中所有 public 成员在派生类中为 public 属性；
    基类中所有 protected 成员在派生类中为 protected 属性；
    基类中所有 private 成员在派生类中不能使用。
    protected继承方式:
    基类中的所有 public 成员在派生类中为 protected 属性；
    基类中的所有 protected 成员在派生类中为 protected 属性；
    基类中的所有 private 成员在派生类中不能使用。
    private继承方式:
    基类中的所有 public 成员在派生类中均为 private 属性；
    基类中的所有 protected 成员在派生类中均为 private 属性；
    基类中的所有 private 成员在派生类中不能使用。

    综上：基类的public和protected成员不论以何种形式，均能被派生类访问，只是根据继承方式的不同，在派生类中的权限也不同。而
    private成员任何继承方式均访问不了。所以要明确的是这是访问控制，基类的私有成员是会被派生类继承的，但是不能被派生类访问；
    从物理上讲是复制过来了，在内存中确实有复制。但是从程序上看是被屏蔽了，不能直接调用。
*/
/*在一个类中同名的成员函数因为参数特点不同而构成重载overload，而派生类与基类函数重名时，不论参数是否相同，不会构成重载，
 * 而是覆盖override，即基类同名函数无效。
 * 如果派生类存在和基类同名的数据成员，不论数据类型是否相同，也是覆盖。
 * 覆盖不是清除，只是访问层面访问的是派生类的成员。可以通过作用域符指定为基类的，基类名::同名成员。
 * 静态成员的处理方式同。
 *--------------------------------------------------------------------------------------------------------------------
 * 派生类对象的大小 = 基类对象成员变量的大小 + 派生类对象自己的成员变量的大小。在派生类对象中，
 * 包含着基类对象，而且基类对象的存储位置位于派生类对象新增的成员变量之前，相当于基类对象是头部。
 * */
/*
 * 构造和析构：
 * 先执行父类构造函数再执行子类构造函数，先执行子类析构再执行父类析构。
 *
 *
 * */
class Fruit{
public:
    Fruit() = default;
    std::string name_public;
    string class_name = "Fruit";
    Fruit(string name_public,string name_protected,string name_private);
protected:
    std::string name_protected;
private:
    std::string name_private;
};
inline Fruit::Fruit(string name_public, string name_protected, string name_private):name_private(name_private),name_protected(name_protected),
name_public(name_public){}

class Apple1:public Fruit {
public:
    int width;
    int height;
    const static string name;
};
const string Apple1::name = "apple1";//静态成员要在类外定义，并且不带static关键字
class Apple2: protected Fruit {
public:
    //通过初始化列表初始化成员并且调用基类构造函数
    Apple2(int width,int height,string name_public="fruit_public",string name_protected="fruit_protected", string name_private="fruit_private"):width(width),height(height),Fruit(name_public, name_protected, name_private){}
    string class_name = "Apple2";
    int width;
    int height;
};

class Apple3:private Fruit {
public:
    int width;
    int height;
};