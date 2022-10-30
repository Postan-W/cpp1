#ifndef CPP1_F_H
#define CPP1_F_H

#endif //CPP1_F_H
/*
 *
 *1. 想要创建inline函数，在声明的时候inline标记可带可不带，主要是定义的时候要带上，不然不能成为inline函数。
 * 2.在类内定义的成员函数默认是inline的，在类内声明但在类外定义的默认是正常函数调用，如果在类外定义时想要
 * 其实inline的，需要加上inline标记。
 * 注意:inline成员函数也应该与相应的类定义在同一个头文件中。
 * */
int power(int,int);
inline int scale(int,int);
/*与一般函数定义在cpp中不同，inline函数需要直接被编译器看到，这里是和声明一起放在头文件中，因为该头文件被include进了main.cpp。
 * 如果是定义在其他文件比如.cpp或.h中，也需要被include*/
inline int scale(int n,int scale){
    return n*scale;
}
void io_trial();
//可以用常见的顺序容器构造适配器，比如stack适配器可使任何一种顺序容器以栈的方式工作
void stack_adoptor();

//交换两个数
template <class T>
void Swap(T& a, T& b){
    T temp;
    temp = b;
    b = a;
    a = temp;
}