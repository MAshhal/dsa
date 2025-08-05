//
// Created by mE on 05/08/2025.
//

#ifndef STACK_H
#define STACK_H

struct StackNode {
    int data;
    StackNode* next;

    StackNode(int data, StackNode* next = nullptr);
};

class Stack {
    StackNode* top;

public:
    Stack();
    ~Stack();

    void push(int value);
    void pop();
    int peek();
    bool isEmpty();
    void display();
};

#endif //STACK_H
