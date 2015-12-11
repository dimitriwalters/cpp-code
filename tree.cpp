#include <iostream>

using namespace std;

struct node {
    int key;
    node *left;
    node *right;
};

class Tree {
    node *root;
    void destroy(node *tree);
    void insert(node *tree, int v);
    node *search(node *tree, int v);
    void print_in_order(node *tree);
public:
    Tree();
    ~Tree();
    void insert(int v);
    node *search(int v);
    void print_in_order();
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
    if (root != nullptr) {
        insert(root, v);
    } else {
        root = new node;
        root->key = v;
        root->left = nullptr;
        root->right = nullptr;
    }
}

node *Tree::search(int v) {
    if (root != nullptr) {
        return search(root, v);
    } else {
        return root;
    }
}

void Tree::print_in_order() {
    if (root != nullptr) {
        print_in_order(root);
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

void Tree::insert(node *tree, int v) {
    if (v < tree->key) {
        if (tree->left == nullptr) {
            node *newnode = new node;
            newnode->key = v;
            newnode->left = nullptr;
            newnode->right = nullptr;

            tree->left = newnode;
        } else {
            insert(tree->left, v);
        }
    }
    else {
        if (tree->right == nullptr) {
            node *newnode = new node;
            newnode->key = v;
            newnode->left = nullptr;
            newnode->right = nullptr;

            tree->right = newnode;
        } else {
            insert(tree->right, v);
        }
    }
}

node *Tree::search(node *tree, int v) {
    if (v == tree->key) {
        return tree;
    } else if (v < tree->key) {
        if (tree->left == nullptr) {
            return nullptr;
        } else {
            return search(tree->left, v);
        }
    } else {
        if (tree->right == nullptr) {
            return nullptr;
        } else {
            return search(tree->right, v);
        }
    }
}

void Tree::print_in_order(node *tree) {
    if (tree->left != nullptr) {
        print_in_order(tree->left);
    }
    cout << tree->key << " ";
    if (tree->right != nullptr) {
        print_in_order(tree->right);
    }
}

int main() {
    Tree my_tree;
    my_tree.insert(12);
    my_tree.insert(5);
    my_tree.insert(19);
    my_tree.print_in_order();

    node *my_node = my_tree.search(5);
    cout << my_node->key << endl;
}
