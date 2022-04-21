#include <iostream>

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

int main() {
    std::cout << "Hello, World!" << std::endl;
    Stack::push('b');
    Stack::push('b');
    std::cout << Stack::pop() << std::endl;
    Stack::pop();
    Stack::pop();
    std::cout << "End." << std::endl;

    // 2.5.2.

    return 0;
}
