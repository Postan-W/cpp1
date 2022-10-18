#include <iostream>
#include<vector>
#include<typeinfo>

//引入命名空间中的名字，否则的话使用时要带上命名空间名，如std::cin
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::iterator;
/*std::cout<<是将右侧的对象的内容给左侧的对象cout,std::cin>>是将左侧cin对象读取到的内容给右侧的变量，但两种运算符的
 * 返回结果都是左侧的cin或cout对象,所以可以将多个<<或>>拼接起来使用。
 * */
//和C语言一样，++a和a++一样都是对a加1，但是前者返回加1后的值，后者返回加1前的值
void construct_string(){
    string s1 = "name:";
    string s2 = "Jack";
    string s3(10,'=');//第二个参数是一个char,如果是多个，则只取第一个
    string s4("nation:");
    string s5("China");
    cout << s1+s2<< endl;
    cout << s3 <<endl << s4+s5<<endl;
    string s6 = "input:";
    for(char c: s6){
        cout << c <<endl;
    }
    string s7;
    cin >> s7;//只会保留遇到空格之前的部分
    cout << s7<<endl;
}
//string类型也支持迭代器操作
char upper(char c){
    return c - 32;
}
bool is_space(char c){
    return c == ' ';
}

void string_iter(){
    //string虽然不是容器，但string也像vector那样可以使用迭代器
    string s = "this is an apple";
    //把第一个单词作为大写。迭代器只有++it或--it的用法(指的是移向下一个或前一个元素)，注意没有it++或it--的用法
    for(auto it = s.begin();it != s.end() && !is_space(*it);++it){
        *it = upper(*it);
    }
    cout<< s << endl;

    string s2 = "welcome to beijing";
    string::iterator it_s2 = s2.begin();
    *it_s2 = 'W';
    const string s3 = "yes it is";
    auto it_s3 = s3.begin();
//    *it_s3 = 'H';不可行，因为s3是const的，所以it_s3被定义为const的
//    string::iterator it_s33 = s3.begin();显式定义为非const的将报错
    string::const_iterator it_s32 = s3.begin();//效果等同auto
}

void trail_vector(){
    vector<int> v1 = {1,2,3,4,5};
    //将v1中的元素变为其平方。注意e是引用类型，那么操作e就是操作元素本身
    for(auto &e:v1){
        e *= e;
    }
    for(auto e:v1){
        cout << e <<endl;
    }
}
void trial_on_iter(){
    vector<string> v1(10,"hello");
    const std::vector<int> v2 = {1,2,3,4,5,6,7};
    vector<string>::iterator it1 = v1.begin();//当然，这里可以用auto代替类型
    *it1 = "welcome";//可以更改非const vector的对象
    cout <<*it1<<endl;
    vector<int>::const_iterator it2 = v2.begin();
//    *it2 = 100; 连IDE检查都过不了，因为该iter是const的
    auto it2_auto = v2.begin();
//    *it2_auto = 100;由于v2是const的，所以it2_auto也被定义为const的

}
int main() {
    trial_on_iter();
    return 0;
}
