#include <iostream>

using namespace std;

struct node {
    int item;
    node *next;
    node *prev;
};

class List {
    node *head;
    node *tail;
public:
    List();
    ~List();
    void push_front(int v);
    void push_back(int v);
    void print();
};

List::List() {
    head = nullptr;
    tail = head;
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
    newnode->prev = nullptr;

    head = newnode;
    if (tail == nullptr) {
        tail = head;
    }
}

void List::push_back(int v) {
    node *newnode = new node;
    newnode->item = v;
    newnode->next = nullptr;
    newnode->prev = tail;

    if (tail != nullptr) {
        tail->next = newnode;
    }
    tail = newnode;

    if (head == nullptr) {
        head = tail;
    }
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
    List list;
    list.push_front(5);
    list.push_front(8);
    list.push_back(11);
    list.print();
}