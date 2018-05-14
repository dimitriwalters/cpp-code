## Table of Contents
* [Classes](#classes)
* [Linked List](#linked-list)
* [Libraries](#libraries)
* [Division](#division)
* [Decimal](#decimal)
* [Starter](#starter)
* [Sorting](#sorting)
  * [Bubble](#bubble)

## Classes

```cpp
class MyQueue {
    void set_dequeue_state() {
        if (stack_dequeue.empty()) {
            while (!stack_enqueue.empty()) {
                stack_dequeue.push(stack_enqueue.top());
                stack_enqueue.pop();
            }
        }
    }
  
    public:
        stack<int> stack_enqueue, stack_dequeue;   
        void push(int x) {
            stack_enqueue.push(x);
        }

        void pop() {
            set_dequeue_state();
            stack_dequeue.pop();
        }

        int front() {
            set_dequeue_state();
            return stack_dequeue.top();
        }
};
```

## Linked List

```cpp
struct Node {
    int data;
    struct Node* next;
}

bool has_cycle(Node* head) {
    struct Node *slow, *fast;
    slow = head;
    fast = head;
    while (slow != NULL && fast != NULL) {
        slow = slow->next;
        fast = fast->next;
        if (fast == NULL) {
            return true;
        }
        fast = fast->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
```

## Libraries

To use all C++ libraries and `std` namespace:

```cpp
#include <bits/stdc++.h>

using namespace std;
```

## Division

Helper function for dividing two integers and have it return a float:

```cpp
float float_div(int a, int b) {
    return a/(float)b;
}
```

## Decimal

To set output to a specific decimal place:

```cpp
cout.precision(1);
cout.setf(ios::fixed, ios::floatfield);
```

## Starter

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    return 0;
}
```

## Sorting

### Bubble

```cpp
void bubble_sort(vector<int> &v) {
    for (size_t i=0; i<v.size(); i++) {
        for (size_t j=0; j<v.size()-1; j++) {
            if (v[j] > v[j+1]) {
                int tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
}
```
