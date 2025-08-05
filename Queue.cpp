//
// Created by mE on 05/08/2025.
//

#include <iostream>
#include "Queue.h"


using namespace std;

QueueNode::QueueNode(int data, QueueNode *next): data(data), next(next) {}


Queue::Queue(): front(nullptr), rear(nullptr) {}
Queue::~Queue() {
    while (front != nullptr) {
        dequeue();
    }
}

void Queue::enqueue(int value) {
    QueueNode* newNode = new QueueNode(value, nullptr);
    if (!rear) front = rear = newNode; // front and rear will be the same since only 1 entry in entire queue
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void Queue::dequeue() {
    if (!front) return;
    QueueNode* temp = front;
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
}

void Queue::display() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    QueueNode* temp = front;
    cout << "Queue: ";
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int Queue::peek() {
    if (!front) {
        cout << "Queue is empty!!!";
        return -1;
    }

    return front->data;
}


bool Queue::isEmpty() {
    return front == nullptr;
}
