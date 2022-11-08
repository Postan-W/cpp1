#ifndef CPP1_CPP_CLASS_H
#define CPP1_CPP_CLASS_H
#endif
#include<iostream>
/*1.使用class和struct的唯一区别是：使用class定义的类在没有被强制限定的话，其成员时私有的，既不能被外部调用。使用struct的话，其成员是公共的，
 * 可以被外部调用。
    2.访问控制符的影响范围是遇到下一个访问控制符或者遇到类结尾；
    3.类可以允许其他类或者函数访问它的非公有成员，方法是令其他类或者函数成为它的友元（friend。友元声明只能出现在类定义的内部，但是在类内出现的具体位置不限。
    友元不是类的成员也不受它所在区域访问控制级别的约束。友元的声明仅仅指定了访问的权限，而非一个通常意义上的函数声明。如果我们希望类的用户能够调用某个友元函数，
    那么我们就必须在友元声明之外再专门对函数进行一次声明。
    4.类的声明和定义以及类成员函数的声明(在类里面声明)和定义可以在不同的文件中。如果成员函数在类内定义，那么默认就是inline的，如果在类
    外定义默认就是非inline的，类外定义时应该在函数名前使用::指名所属类，比如 inline std::string SomeClass::getName(){}
    5.类内初始值。就是在类中定义成员变量的时候就赋值用=或{}都可以。比如int age = 20;string name {"Jack"}。创建对象时先使用类内初始值
    初始化，若调用的构造函数为该成员变量赋值，则类内初始值被覆盖。类内初始值以及类型默认值是调用构造函数体之前用来初始数据成员的。
    6.构造函数。如果构造函数被定义为private的，那么就无法通过该构造函数直接生成该类的实例。构造函数的名字和类名相同。和其他函数不一样的是，
    构造函数没有返回类型，不同的构造函数之间必须在参数数量或参数类型上有所区别；不同于其他成员函数，构造函数不能被声明成const的。当我们创建类的一个const对象时，
    直到构造函数完成初始化过程，对象才能真正取得其“常量”属性。因此，构造函数在const对象的构造过程中可以向其写值。如果没有定义构造函数，那么编译器就会为该类
    生成默认的构造函数，即没有参数与函数体，如果定义了构造函数，则不会默认生成，此时可以手动生成，例如ClassName() = default，默认
    构造函数不做任何事情，编译器将按照如下规则初始化成员:如果有类内初始值则按类内初始值初始化，如果没有则默认初始化，比如int初始化为0;
    7.编译器分两步处理类：首先编译数据成员的声明，然后才轮到成员函数体（如果有的话）。因此，成员函数体可以随意使用类中的
    其他成员而无须在意这些成员出现的次序
    8.成员函数通过一个名为this的额外的隐式参数来访问调用它的那个对象。当我们调用一个成员函数时，用请求该函数的对象地址初始化this，
    this的类型是指向该对象(该对象是非const的)的常量指针，即*const this，这一情况也就使得我们不能在一个常量对象上调用普通的成员函数。
    鉴于此，可以把this定义为一个指向常量的常量指针，const class_type *const this，尽管该对象不是常量对象。此时在成员函数内无法
    通过this更改对象的内容，做法是在参数列表的后面跟上const关键字，例如 int getNum() const{},这样的函数被称为常量成员函数。常量对象
    只能调用常量成员函数，本人猜测可能是参数匹配的原因，因为非常量成员函数的隐式参数this是class_type *const this而不是const class_type *const this,但反过来可以，即
    非常量对象调用常量成员函数就是可以的，因为class_type *const this 可以作为以const class_type *cosnt this为隐式形参的常量成员函数的实参。
    9.mutable数据成员无论对于const对象(只能调用const成员函数)还是非const对象，无论是直接点访问更改其值，还是在const成员函数或非const
    成员函数中更改其值，都是可行的。当然，该数据成员本身不能是const的，mutable和const两个关键字不能同时使用。
    10.函数重载的区分是参数的数量、顺序、类型，跟返回类型无关。const成员函数和非const成员函数可以用来区分重载，这与函数重载原则并不矛盾，
    因为const成员函数的this是const class_type *const this,而非const成员函数的this是class_type *const this。
    11.初始值列表有时候是必要的。当然，初始值列表是对有参构造函数而言的，调用有参构造函数，执行函数体之前，会先执行初始值列表，
    如果没有初始值列表(无参构造函数或者有参构造函数但没有给初始值列表),就会对成员执行默认初始化，之后再执行函数体。换言之，在执行
    构造函数体之前，成员就已经被初始化了完成了。所以像引用这种类型的成员，由于引用类型必须被明确引用到一个目标身上，所以具有引用类型
    成员的类必须有带初始值列表的构造函数，否则编译器执行默认初始化时到引用类型成员这一步会报错。初始值列表可以使用构造函数的参数值。
    12.拷贝构造函数第一个参数必须是引用类型，否则的话，为了调用拷贝构造函数，我们必须拷贝它的实参，但为了拷贝实参，我们又需要调用拷贝构造函数，如此无限循环
    13.一个类有且仅有一个析构函数。如果定义类时没写析构函数，则编译器生成默认析构函数。如果定义了析构函数，则编译器不生成默认析构函数。
    析构函数在对象消亡时即自动被调用。可以定义析构函数在对象消亡前做善后工作。例如，对象如果在生存期间用 new 运算符动态分配了内存，
   则在各处写 delete 语句以确保程序的每条执行路径都能释放这片内存是比较麻烦的事情。有了析构函数，只要在析构函数中调用 delete 语句，就能确保对象运行中用 new 运算符分配的空间在对象消亡时被释放
 *
 *
 * */
class Person{
public:
    typedef std::string::size_type bignum;//放在类的开头也行，只要使用bignum这个名字的语句位置在其后就行。但类外无法使用
//    using bignum = std::string::size_type;//类型别名。效果等同于typedef
    std::string name;
    const std::string occupation = "unknown";//cosnt成员用类内初始值初始化，或者在初始值列表中初始化，不能在构造函数中赋值初始化
    Person() = default;//默认构造函数。和空函数体的无参构造函数等效Person(){}。有类内初始值则使用类内初始值，没有则使用默认值
    //构造函数的初始值列表初始化一个或多个数据成员。用法是，数据成员(函数的某个参数)
    Person(std::string name,std::string nation,bignum id,int age):age(age),nation(nation),name(name),id(id){
        std::cout << "name:" << name << "<>nation:" << nation << "<>id:" << id << "<>age:" << age << std::endl;
    }
    void print_information();//类内声明，类外定义。构造函数也可以如此。
    friend void access_person(Person p);//该条是声明access_person为类的友元函数，但不是函数本身的声明
    friend void change_person(Person &p,std::string new_name,std::string::size_type new_id,std::string new_nation,int new_age);
    inline char get_nation_initial();//声明时inline不是必须的，在类外部定义时使用inline关键字就可以。当然，如果定义就在类内(此时不可以再有一条声明语句)，那么默认就是inline的
    mutable std::string degree;
    const std::string &getDegree(std::string degree) const;

private:
    int age = 0;
    bignum id = 20220000;
    std::string nation = "China";
    int getAge() const {
        return age;
    }

    bignum getId() const {
//        name = "da";不可在常量函数内修改对象的内容
        return id;
    }

    const std::string &getNation() const {
        return nation;
    }
};
//在函数体外定义print_information，那么其默认就是非inline的
void Person::print_information() {
    std::cout << "对象信息为:" << std::endl << "name:" << name << std::endl << "id:" << getId() << std::endl << "nation:" << getNation()
    << std::endl << "age:" << getAge() << std::endl;
}
//友元函数不受类的访问权限限制
void access_person(Person p){
    std::cout << "友元函数内可以直接访问类的私有成员:" << std::endl;
    std::cout << p.name << " " << p.id << " " << p.nation << " " << p.age << std::endl;
}
void change_person(Person &p,std::string new_name,std::string::size_type new_id,std::string new_nation,int new_age){
    p.name = new_name;
    p.id = new_id;
    p.nation = new_nation;
    p.age = new_age;
    std::cout << "友元函数内可以直接更改类的私有成员(如果不是const的话):" << std::endl;
    std::cout << p.name << " " << p.id << " " << p.nation << " " << p.age << std::endl;
}

//类外定义默认非inline，所以需要指定inline关键字
inline char Person::get_nation_initial() {
    return nation[0];
}

const std::string &Person::getDegree(std::string degree_mutable) const {
    //因为degree是mutable的，所以在该常量函数内也可修改
    degree = degree_mutable;
    return degree;
}

class Book{
public:
    typedef std::string::size_type bignum;
    std::string name = "undefined";
    //typedef unsigned long long int size_t
    bignum isbn = 10000000;
    std::string author = "undefined";
    bignum setIsbn(bignum isbn);
    Book() = default;
//    ~Book(){std::cout << "book的析构函数"<<std::endl;}
    Book(int a,Book book){std::cout << "第一个参数如果是本类类型，那么就会被认为是拷贝构造函数，而且要求必须是引用"<<std::endl;}
    Book(std::string name,std::string author,bignum isbn,int price=50):price(price),name(name),isbn(isbn),author(author){}//使用初始值列表初始化
    //只要第一个参数是本类类型，则就认为是拷贝构造函数，并且要求一定是要const class_type &
    Book(const Book &book);//拷贝构造函数。第一个参数是const引用(多个参数的话其他参数要有默认值),见第12点的叙述。

    //显式初始化。为了区分上面那个函数调换了一下参数顺序
    Book(std::string name,bignum isbn,std::string author){
        //注意类数据成员和形参的区分
        this->name = name;
        this->isbn = isbn;
        this->author = author;
    }

    int getPrice() const;

    void setPrice(int price);

    void print_bookinfo();

private:
    int price;
};
/*
 * bignum是在类内定义的,在类外找不到，所以必须指名所在类;而函数名被类名限定后,参数列表和函数体的作用域就是类内的了，如所见
 * 参数列表中直接使用了bignum。
 * 注意形参名字如果和数据成员相同，赋值的时候isbn = isbn,因为形参的作用范围更小，将同名数据成员覆盖了，左右两侧其实都是形参，
 * 所以数据成员要标类名或者显式使用this->
 * */
//注意这里的price直接用的是点访问，因为是在Book类内部。下面的显示定义和没有拷贝构造函数时编译器自动合成的效果一样
//调用方法是Book new = Book(old)或者直接赋值Book new = old;
//这里是通过初始值列表给成员初始化。如果连初始值列表都没有，函数体为空，则新对象的成员数据都是类内初始化值或者是类型默认值。此时还不如使用编译器默认的拷贝构造函数，其会为对应成员赋值
Book::Book(const Book &book):name(book.name),isbn(book.isbn),author(book.author),price(book.price){
    //这里是空函数体
}
inline Book::bignum Book::setIsbn(bignum isbn) {Book::isbn = isbn;}
inline void Book::print_bookinfo() {std::cout << name << "<>" << isbn << "<>" << author << "<>"<< price <<std::endl;}

int Book::getPrice() const {
    return price;
}

void Book::setPrice(int price) {
    Book::price = price;
}

/*
 * 聚合类。所有成员都是public的;没有类内初始值；没有构造函数；没有基类，没有virtual函数；初始值的顺序必须和声明的顺应一样，
 * 如果初始值的列表中的元素个数少于类的成员数量，则靠后的成员被值初始化。但是初始值列表的元素个数绝对不能超过类的成员数量。
 * 重复一遍，struct和class的区别是struct默认成员是public的而class默认成员是private的。
 * struct AggregateClass{
 *                          std::string name;
                            size_t number;
                            };
此时相当于C中的struct
 * */
class AggregateClass{
public:
    std::string name;
    size_t number;
};
/*C++中的explicit关键字只能用于修饰只有一个参数的类构造函数(或者除第一个参数外其他参数都有默认值), 它的作用是表明该构造函数是显式的,
 * 而非隐式的, 跟它相对应的另一个关键字是implicit, 意思是隐藏的,类构造函数默认情况下即声明为implicit(隐式).*/
class ImplicitClass{
public:
    int age;
    ImplicitClass(int age){
        this->age = age;
    }
};
class ExplicitClass{
public:
    int age;
    explicit ExplicitClass(int age){
        this->age = age;
    }
};
