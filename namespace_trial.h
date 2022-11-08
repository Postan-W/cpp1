//
// Created by 15216 on 2022/11/1.
//

#ifndef CPP1_NAMESPACE_TRIAL_H
#define CPP1_NAMESPACE_TRIAL_H

#endif //CPP1_NAMESPACE_TRIAL_H
//命名空间必须在全局定义，不能在块中，如函数中定义。可以给命名空间取别名，namespace 别名 = 命名空间。
/*在某个作用域内使用using关键字，如using int_set::a,这叫using声明，相当于该作用域内(局部的或者全局的)默认引入了变量a，则不能再定义同名变量导致冲突，可以理解为同一个作用域内不能两次声明同名对象。
 。使用using namespace int_set引入命名空间，使得，命名空间内所有成员可被直接使用，这叫using编译指令，如果之后再定义与空间中同名的对象时，会使用后来定义的，因为离得近*/
namespace int_set{
    int a = 10;
    int b = 20;
    int c = 30;
}
//命名空间可扩展
namespace int_set{
    int d = 40;
}

//命名空间可以嵌套
namespace string_set{
    std::string s1 = "abcd";
    //这个int_set和外面那个没关系，使用这个的时候必须加上string_set作用域
    namespace int_set{
        int e = 60;
    }
}
//如果命名空间包含一组用相同名字重载的函数，using声明就声明了这个重载函数的所有集
namespace function_namespace{
    void function();
    void function(int a);
    int function(int a,int b);
}
//可以在空间外定义
inline void function_namespace::function(){std::cout << "function_namespace中的无参重载函数" <<std::endl;}
inline void function_namespace::function(int a){std::cout << "function_namespace中的一个参数重载函数，参数是:" <<a <<std::endl;}
inline int function_namespace::function(int a, int b) {std::cout << "function_namespace中的两个参数重载函数，参数是:" <<a<<","<<b <<std::endl;}
