#include <iostream>
#include <stack>

using namespace std;

struct node {
    int key;
    node *left;
    node *right;
};

class Tree {
    node *root;
    void destroy(node *tree);
    node *insert(node *tree, int v);
    node *search(node *tree, int v);
    node *max(node *tree);
    node *min(node *tree);
    node *deleteKey(node *tree, int v);
    void print_in_order_rec(node *tree);
    void print_in_order_iter(node *tree);
    void print_pre_order_iter(node *tree);
public:
    Tree();
    ~Tree();
    void insert(int v);
    node *search(int v);
    node *max();
    node *min();
    void deleteKey(int v);
    void print_in_order();
    void print_pre_order();
};

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    if (root != nullptr) {
        destroy(root);
    }
}

void Tree::insert(int v) {
    root = insert(root, v);
}

node *Tree::search(int v) {
    return search(root, v);
}

node *Tree::max() {
    if (root != nullptr) {
        return max(root);
    } else {
        return root;
    }
}

node *Tree::min() {
    if (root != nullptr) {
        return min(root);
    } else {
        return root;
    }
}

void Tree::deleteKey(int v) {
    root = deleteKey(root, v);
}

void Tree::print_in_order() {
    if (root != nullptr) {
        print_in_order_iter(root);
        cout << endl;
    } else {
        cout << "empty" << endl;
    }
}

void Tree::print_pre_order() {
    if (root != nullptr) {
        print_pre_order_iter(root);
        cout << endl;
    } else {
        cout << "empty" << endl;
    }
}

void Tree::destroy(node *tree) {
    if (tree->left != nullptr) {
        destroy(tree->left);
    }
    if (tree->right != nullptr) {
        destroy(tree->right);
    }
    delete tree;
}

node *Tree::insert(node *tree, int v) {
    if (tree == nullptr) {
        tree = new node;
        tree->key = v;
        tree->left = nullptr;
        tree->right = nullptr;
    } else if (v < tree->key) {
        tree->left = insert(tree->left, v);
    } else if (v > tree->key) {
        tree->right = insert(tree->right, v);
    }
    return tree;
}

node *Tree::search(node *tree, int v) {
    if (tree == nullptr || tree->key == v) {
        return tree;
    } else if (v < tree->key) {
        return search(tree->left, v);
    } else {
        return search(tree->right, v);
    }
}

node *Tree::max(node *tree) {
    if (tree->right != nullptr) {
        return max(tree->right);
    } else {
        return tree;
    }
}

node *Tree::min(node *tree) {
    if (tree->left != nullptr) {
        return min(tree->left);
    } else {
        return tree;
    }
}

node *Tree::deleteKey(node *tree, int v) {
    if (tree == nullptr) {
        return tree;
    } else {
        if (v < tree->key) {
            tree->left = deleteKey(tree->left, v);
        } else if (v > tree->key) {
            tree->right = deleteKey(tree->right, v);
        } else {
            node *left = tree->left;
            node *right = tree->right;
            if (left == nullptr && right == nullptr) {
                delete tree;
                return nullptr;
            } else if (tree->left == nullptr) {
                delete tree;
                return right;
            } else if (tree->right == nullptr) {
                delete tree;
                return left;
            } else {
                node *maxnode = max(tree->left);
                int maxkey = maxnode->key;
                deleteKey(maxkey);
                tree->key = maxkey;
            }
        }
        return tree;
    }
}

void Tree::print_in_order_iter(node *tree) {
    node *current = tree;
    stack<node *> s;
    bool done = false;

    while (!done) {
        if (current != nullptr) {
            s.push(current);
            current = current->left;
        } else if (!s.empty()) {
            current = s.top();
            s.pop();
            cout << current->key << " ";
            current = current->right;
        } else {
            done = true;
        }
    }
}

void Tree::print_in_order_rec(node *tree) {
    if (tree->left != nullptr) {
        print_in_order_rec(tree->left);
    }
    cout << tree->key << " ";
    if (tree->right != nullptr) {
        print_in_order_rec(tree->right);
    }
}

void Tree::print_pre_order_iter(node *tree) {
    stack<node *> s;
    s.push(tree);
    node *current;

    while (!s.empty()) {
        current = s.top();
        s.pop();
        cout << current->key << " ";

        if (current->right != nullptr) {
            s.push(current->right);
        }
        if (current->left != nullptr) {
            s.push(current->left);
        }
    }
}

int main() {
    Tree my_tree;
    my_tree.insert(12);
    my_tree.insert(5);
    my_tree.insert(19);
    my_tree.insert(19);
    my_tree.print_in_order();
    my_tree.print_pre_order();

    my_tree.deleteKey(12);
    my_tree.print_in_order();
    my_tree.deleteKey(5);
    my_tree.print_in_order();
}
