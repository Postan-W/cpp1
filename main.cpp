#include <iostream>
#include<vector>
#include<typeinfo>
#include <windows.h>
#include "local_algorithm.h"
#include "function.h"
#include "cpp_class.h"
#include "class_oop.h"
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

    //cbegin与cend。无论对象本身如vector或string是否是const,这两个函数都返回const_iterator
    auto it_s22 = s2.cbegin();
//    *it_s22 = "HI";不允许，因为it_s22是const_iterator
//    string::iterator it_s23 = s2.cbegin();不合规，因为cbegin返回的是const_iterator
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
//iter和指针都可以使用箭头运算符或解引用符加.访问的方式访问其指向对象(it用指向这个词可能不太合适)的成员,it->member等同于(*it).member
void iter_arrow(){
    vector<string>  v1 = {"welcome","to","Beijing"};
    vector<string>::const_iterator it1 = v1.begin();//非const容器可以有const的iterator，从容器有cbegin、cend函数就可看出。但反过来不行
    cout <<(*it1).empty()<<endl;
    cout <<it1->empty()<<endl;
}
//迭代器的算术运算都指的是位置而言的(加减一个数值、两个同一个容器的迭代器比较大小或是否相等、两个同一个容器的迭代器相减)
void iter_arithmetic(){
    vector<string> v1 = {"Beijing","city","is","surrended","by","ring","roads","and","the","city","is","well","symmetrical"};
    cout << "vector大小:" << v1.size() <<endl;
    auto middle = v1.begin() + v1.size()/2;
    cout << "中间的词是:"<<*middle <<endl;
    auto start = v1.begin();
    auto end = v1.end();
    cout << (end >= start) << endl;
    auto distance = end - start;//distance的类型名称叫作difference_type
    cout << "end和start的距离是:" << distance<<endl;

}
void print_int_vector(vector<int> v){
    cout << "vector的元素为:";
    for(int i:v){
        cout << i << " ";
    }
    cout << endl;
}
//使用数组初始化vector
void initialize_vector_by_array(){
    //编译器把数组名转为指向第一个元素的指针
    int a[] = {1,2,3,4,5,6};
    vector<int> v1(a+0,a+6);//两个参数分别为起始指针与结尾指针，前闭后开
    print_int_vector(v1);
    vector<int> v2(a+1,a+4);
    print_int_vector(v2);
}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    Person person = Person("Qiang Li","China",20221180,22);
    Person person_temp = person;//使用默认的拷贝构造函数
    person_temp.print_information();
    Person person2 = Person();
    const Person person3 = Person();
    person2.print_information();
    access_person(person);
    change_person(person,"EastWood",20220001,"USA",34);
    person.print_information();
    std::cout << person.get_nation_initial() <<endl;
    std::cout << person.occupation <<endl;
    std::cout << person.getDegree("doctor") <<endl;
    person.degree = "master";
    std::cout << person.degree <<endl;
    const Person person4 = Person();
    person4.degree = "doctor";
    std::cout << person4.degree <<endl;
    Book book = Book();
    book.setIsbn(20221121);
    std::cout << book.isbn << endl;
    Book book2 = Book("the moon and six pennies","Maugham",20221122,30);
    book2.print_bookinfo();
    Book book3 = book2;
    cout << "book3的信息是:"<<std::ends;
    book3.print_bookinfo();
    Book book4 = Book(book3);
    book4.print_bookinfo();
    Book book5 = Book(12,book4);
    AggregateClass ac = {"Peppy",11218526};
    std::cout << "聚合类:" << std::endl << ac.name << "<>" << ac.number << std::endl;
    std::cout << fibonacci_sequence(6) << endl;
    io_trial();
    vector<string> v_temp = {"I","love","China"};
    string s_temp = "so much";
    v_temp.push_back(s_temp);
    s_temp.push_back('!');
    cout << s_temp <<endl;
    cout << *(v_temp.end()-1) << endl;
    cout << v_temp.capacity() << endl;
    stack_adoptor();
    ImplicitClass implicit_class = 10;
    cout << implicit_class.age << endl;
//    ExplicitClass explicit_class = 10;不可行
    Fruit fruit1 = Fruit("fruit_public","fruit_protected","fruit_private");
    cout << fruit1.name_public <<endl;
    Apple1 apple1 = Apple1();
    cout << apple1.name <<endl;
    cout << apple1.name_public << endl;//默认值，空
    Apple2  apple2 = Apple2(10,10);
    cout << apple2.width <<endl;
//    cout << apple2.name_public << endl;因为是protected继承，所以name_public变成protected的了，不能在类外访问
    cout << apple2.class_name <<endl;
    int t1 = 10,t2 = 20;
    Swap(t1,t2);
    cout << "t1=" << t1 <<endl <<"t2=" << t2 <<endl;
    return 0;
}
