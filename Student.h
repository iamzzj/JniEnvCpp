class Student {
public:
    //构造函数
    Student();

    explicit Student(char *name);

    //析构函数，不能有参数
    ~Student();

    //拷贝构造函数 = 号赋值
    //会有一个默认的拷贝构造函数，用来对象之间的赋值
    Student(const Student &stu) {
        this->name = stu.name;
        this->age = stu.age;
    }

private:
    char *name{};
public:
    int age{};
public:
    void setAge(int age);

    void setName(char *name);

    int getAge();

    char *getName();
};