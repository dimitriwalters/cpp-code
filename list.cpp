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
    ~List();
    void push_front(int v);
    void print();
};

List::List(int v) {
    head = new node;
    head->item = v;
    head->next = nullptr;
}

List::~List() {
    node *current, *next;
    current = head;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

void List::push_front(int v) {
    node *newnode = new node;
    newnode->item = v;
    newnode->next = head;

    head = newnode;
}

void List::print() {
    node *current, *next;
    current = head;
    while (current != nullptr) {
        next = current->next;
        cout << current->item << " --> ";
        current = next;
    }
    cout << "NULL" << endl;
}

int main() {
    List list(5);
    list.push_front(8);
    list.print();
}