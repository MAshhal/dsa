//
// Created by mE on 05/08/2025.
//

#ifndef QUEUE_H
#define QUEUE_H

// struct Node {
//     int data;
//     Node* next;
//
//     Node(int data, Node* next = nullptr);
// };

struct QueueNode {
    int data;
    QueueNode* next;

    QueueNode(int data, QueueNode* next = nullptr);
};

class Queue {
    QueueNode *front, *rear;

public:
    Queue();
    ~Queue();

    void enqueue(int value);
    void dequeue();
    int peek();
    bool isEmpty();
    void display();
};

#endif //QUEUE_H
