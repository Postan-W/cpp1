#include <iostream>
#include<vector>
//引入命名空间中的名字，否则的话使用时要带上命名空间名，如std::cin
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
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
    cin >> s7;
    cout << s7<<endl;
}
//string类型也支持迭代器操作，下面是把第一个单词改为大写
char upper(char c){
    return c - 32;
}
bool is_space(char c){
    return c == ' ';
}

void string_iter(){
    string s = "this is an apple";
    for(auto it = s.begin();it != s.end() && !is_space(*it);++it){
        *it = upper(*it);
    }
    cout<< s << endl;
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
int main() {
    string_iter();
    return 0;
}
