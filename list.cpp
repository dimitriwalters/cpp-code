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
    void delete_item(int v);
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

    if (head != nullptr) {
        head->prev = newnode;
    }
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

void List::delete_item(int v) {
    node *current, *next, *prev;
    current = head;
    while (current != nullptr) {
        prev = current->prev;
        next = current->next;
        if (current->item == v) {
            if (prev == nullptr && next == nullptr) {
                head = nullptr;
                tail = head;
            } else if (prev == nullptr) {
                head = next;
                next->prev = nullptr;
            } else if (next == nullptr) {
                tail = prev;
                prev->next = nullptr;
            } else {
                prev->next = next;
                next->prev = prev;
            }

            delete current;
            return;
        } else {
            prev = current;
            current = next;
        }
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
    list.push_front(9);
    list.push_front(8);
    list.push_back(11);
    list.print();
    list.delete_item(9);
    list.print();
    list.delete_item(8);
    list.print();
    list.delete_item(11);
    list.print();
    list.delete_item(5);
    list.print();
}