#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>

bool accept() {
    std::cout << "Do you want to proceed (y or n)?\n";
    char answer = 0;
    std::cin >> answer;

    switch (answer) {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            std::cout << "I'll take that for n.";
            return false;
    }
}

/**
namespace Stack {
    const int MAX_SIZE = 1;
    char v[MAX_SIZE];
    int top = 0;
    class Overflow {};
    class Underflow{};

    void push(char);
    char pop();

    void push(char c) {
        try {
            if (top == MAX_SIZE) throw Overflow();
            else{
                v[top] = c;
                top++;
            }
        } catch (Stack::Overflow) {
            std::cout << "!!Stack is Full!! Will not do anything." << std::endl;
        }
    }

    char pop() {
        try {
            if (top == 0) throw Underflow();
            else {
                return v[--top];
            }
        } catch (Stack::Underflow) {
            std::cout << "!!Stack is Empty!! Will not do anything." << std::endl;
        }
        return NULL;
    }
}
**/

// 类的声明
class Stack {
    char* v;
    int top;
    int max_size;
public:
    class Underflow{};
    class Overflow{};
    class BadSize{};

    Stack(int s);
    ~Stack();

    void push(char c);
    char pop();
};

Stack::Stack(int s) {
    top = 0;
    if (s < 0 || s > 10000) throw BadSize();
    max_size = s;
    v = new char[s];
}

Stack::~Stack() {
    delete[] v;
}

void Stack::push(char c) {
    if (top == max_size) throw Overflow();
    v[top++] = c;
}

char Stack::pop() {
    if (top == 0) throw Underflow();
    return v[--top];
}

struct Entry {
    std::string name;
    int number;
};

template<typename T> void print(T items) {
    for(int i = 0; i < 3; i++) {
        std::cout << items[i] << " ";
    }
    std::cout << std::endl;
}

class Shape {
        int a;
public:
        Shape();
        Shape(int a);
        ~Shape();
        void draw();
    };

Shape::Shape() {}
Shape::Shape(int a) {this -> a = a;}
Shape::~Shape() {}
void Shape::draw() {std::cout << a << std::endl;}

void draw(Shape* p) {
    p -> draw();
}
void f(std::list<Shape*>& sh) {
    std::for_each(sh.begin(), sh.end(), draw);
}

int main() {
    /**
    std::cout << "Hello, World!" << std::endl;
    Stack::push('b');
    Stack::push('b');
    std::cout << Stack::pop() << std::endl;
    Stack::pop();
    Stack::pop();
    std::cout << "End." << std::endl;**/

    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(3);

    // sort
    print(nums);
    std::sort(nums.begin(), nums.end());
    print(nums);

    std::string m = "Mary has a little lamb";
    int a_count = std::count(m.begin(), m.end(), 'a');
    std::cout << a_count << std::endl;

    Shape sh1(1);
    Shape sh2(2);
    std::list<Shape*> ls;
    ls.push_front(&sh1);
    ls.push_front(&sh2);
    f(ls);







    return 0;
}
