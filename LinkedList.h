//
// Created by mE on 05/08/2025.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    Node* next;

    Node(int data, Node* next = nullptr);
};

class LinkedList {
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    void insert_at_head(int value);
    void insert_at_tail(int value);
    void insert_at_position(int value, int pos);
    void delete_value(int value);
    void display();
};

#endif //LINKEDLIST_H
