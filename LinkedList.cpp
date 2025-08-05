//
// Created by mE on 05/08/2025.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;

Node::Node(int data, Node* next) : data(data), next(next) {}

LinkedList::LinkedList(): head(nullptr) {}
LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void LinkedList::insert_at_head(int value) {
    Node* newNode = new Node(value, head);
    head = newNode;
}

void LinkedList::insert_at_tail(int value) {
    Node* newNode = new Node(value, nullptr);
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void LinkedList::insert_at_position(int value, int pos) {
    if (pos == 0) {
            insert_at_head(value);
            return;
        }

        Node* temp = head;
        int i = 0;
        while (temp && i < pos - 1) {
            temp = temp->next;
            i++;
        }

        if (!temp) {
            cout << "Position out of bounds";
            return;
        }

        Node* newNode = new Node(value, temp->next);
        temp->next = newNode;
}

void LinkedList::display() {
    Node* temp = head;
        // while temp is not null
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n" << endl;
}

void LinkedList::delete_value(int value) {
    if (head == nullptr) return;

    if (head->data == value) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node* temp = head;
    while (temp->next && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    } else {
        cout << "Value not found in list" << endl;
    }
}