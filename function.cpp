#include "function.h"
#include<iostream>
#include<stack>
#include<vector>
using std::cout;
using std::cin;
using std::endl;
using std::flush;
using std::ends;
using std::string;
int power(int n,int scale){
    int temp = n;
    for(int i = 1;i < scale;i++){
        temp *= n;
    }
    return temp;
}

void io_trial(){
    /*一般来说buffer缓冲这个词更适合与写搭配，意义在于把要写的内容先放到缓冲区，等满足了触发条件后一次写入，这样就把多次写操作
     * 变成一次写操作，降低了写的开销；
     * cache缓存这个词更适合与读搭配，即把频繁取用的内容放到缓存区，降低从低速设备取数据的开销。
     * C++种buffer flush缓冲刷新(即把缓冲区的内容往目的位置写)的触发原因有很多：
     * 1.缓冲区满时
     * 2.main函数正常结束
     * 3.使用操作符，如endl
     * 4.在每个输出操作之后，我们可以用操纵符unitbuf设置流的内部状态，来清空缓冲区。默认情况下，
     * 对cerr是设置unitbuf的，因此写到cerr的内容都是立即刷新的
     * 5.一个输出流可能被关联到另一个流。默认情况下，cin和cerr都关联到cout。因此，读cin或写cerr都会导致cout的缓冲区被刷新。
     * 也就是说在读之前输出流缓冲区被刷新。
     *
     * */
    auto pre_state = std::cin.rdstate();
    std::cout << "初始状态:" << pre_state << std::endl;
    cout << "endl在前面字符的结尾添加一个换行，刷新缓冲区" << endl;
    cout << "flush不向前面字符的最后添加内容，刷新缓冲区\n" << flush;
    cout << "ends在前面字符的结尾添加一个空字符，刷新缓冲区\n" << ends;//注意这里是在换行后又加了一个空白字符
    //通过使用unitbuf告诉流在接下来的每次写操作之后都进行一次flush操作。而nounitbuf操纵符则重置流，使其恢复使用正常的系统管理的缓冲区刷新机制
//    cout << std::unitbuf;
//    cout << std::nounitbuf;
}
void stack_adoptor(){
    //适配器不能使用底层容器的方法
    std::stack<string,std::vector<string>> st1;//使用vector构造空栈
    st1.push("China");
    std::vector<string> v = {"China","love","I"};//使用底层容器初始化站，元素从前到后依次入栈
    std::stack<string,std::vector<string>> st2(v);
    while(!st2.empty()){
        cout << st2.top()<< endl;//top()返回栈顶元素，但不删除
        st2.pop();//pop()删除栈顶元素，但不返回
    }
}

