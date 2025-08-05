//
// Created by mE on 05/08/2025.
//
#include <iostream>
#include "Stack.h"

using namespace std;

StackNode::StackNode(int data, StackNode* next) : data(data), next(next) {}

Stack::Stack(): top(nullptr) {}
Stack::~Stack() {
    while (top != nullptr) {
        pop();
    }
}

void Stack::push(int value) {
    StackNode* newNode = new StackNode(value, top);
    top = newNode;
}

void Stack::pop() {
    if (top == nullptr) return;
    StackNode* temp = top;
    top = top->next;
    delete temp;
}

int Stack::peek() {
    if (top == nullptr) {
        cout << "Stack is empty!!!" << endl;
        return -1;
    }

    return top->data;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::display() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }

    cout << "Stack (top to bottom): ";
    StackNode* temp = top;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}