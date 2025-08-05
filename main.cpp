#include <iostream>

#include "BST.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
using namespace std;

void test_linked_list();
void test_stack();
void test_queue();
void test_bst();
void test_avl();

int main() {
    cout << "=== Linked List Test ===" << endl;
    test_linked_list();

    cout << "\n=== Queue Test ===" << endl;
    test_queue();

    cout << "\n=== Stack Test ===" << endl;
    test_stack();

    cout << "\n ===BST Tree Test ===" << endl;
    test_bst();

    return 0;
}

void test_linked_list() {
    LinkedList list;
    list.insert_at_tail(2);
    list.insert_at_tail(3);
    list.display();
    cout << "Inserting 1 at head" << endl;
    list.insert_at_head(1);
    list.display();

    cout << "finishing sequence until 10" << endl;
    for (int i = 4; i<=10; i++) {
        if (i == 7) continue;
        list.insert_at_tail(i);
    }
    list.display();

    cout << "Inserting missing value at position" << endl;
    list.insert_at_position(7, 6);
    list.display();

    cout << "deleting even values" << endl;
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) list.delete_value(i);
    }

    list.display();
}

void test_queue() {
    Queue q;
    cout << "Enqueueing values 1 to 5" << endl;
    for (int i = 1; i <= 5; i++) {
        q.enqueue(i);
    }
    q.display();

    cout << "Dequeuing two values" << endl;
    q.dequeue();
    q.dequeue();
    q.display();

    cout << "Peek front: " << q.peek() << endl;

    cout << "Enqueueing values 6 and 7" << endl;
    q.enqueue(6);
    q.enqueue(7);
    q.display();

    cout << "Dequeuing all values" << endl;
    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.peek() << endl;
        q.dequeue();
    }

    q.display();
}

void test_stack() {
    Stack s;
    cout << "Pushing values 1 to 5" << endl;
    for (int i = 1; i <= 5; i++) {
        s.push(i);
    }
    s.display();

    cout << "Popping top value" << endl;
    s.pop();
    s.display();

    cout << "Peek top: " << s.peek() << endl;

    cout << "Pushing 6 and 7" << endl;
    s.push(6);
    s.push(7);
    s.display();

    cout << "Popping all values" << endl;
    while (!s.isEmpty()) {
        cout << "Popped: " << s.peek() << endl;
        s.pop();
    }

    s.display();
}

void test_bst() {
    BST tree;
    int values[] = {5, 3, 7, 2, 4, 6, 8};

    std::cout << "Inserting values: ";
    for (int v : values) {
        std::cout << v << " ";
        tree.insert(v);
    }
    std::cout << "\n\n";

    tree.display_inorder();    // Should print sorted order
    tree.display_preorder();   // Root-Left-Right
    tree.display_postorder();  // Left-Right-Root
}
