#include <iostream>

using namespace std;

struct node {
    int item;
    node *next;
};

class List {
    node *head;
public:
    List(int v);
    void push_front(int v);
    void print();
};

List::List(int v) {
    head = new node;
    head->item = v;
    head->next = nullptr;
}

void List::push_front(int v) {
    node *newnode = new node;
    newnode->item = v;
    newnode->next = head;

    head = newnode;
}

void List::print() {
    node *current;
    current = head;
    while (current != nullptr) {
        cout << current->item << " --> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    List list(5);
    list.push_front(8);
    list.print();
}