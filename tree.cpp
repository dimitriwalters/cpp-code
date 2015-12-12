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
    node *max(node *tree);
    void deleteKey(node *tree, node *parent, int v);
    void print_in_order(node *tree);
public:
    Tree();
    ~Tree();
    void insert(int v);
    node *search(int v);
    node *max();
    void deleteKey(int v);
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

node *Tree::max() {
    if (root != nullptr) {
        return max(root);
    } else {
        return root;
    }
}

void Tree::deleteKey(int v) {
    if (root != nullptr) {
        deleteKey(root, nullptr, v);
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

node *Tree::max(node *tree) {
    if (tree->right != nullptr) {
        return max(tree->right);
    } else {
        return tree;
    }
}

void Tree::deleteKey(node *tree, node *parent, int v) {
    if (v == tree->key) {
        node *left = tree->left;
        node *right = tree->right;
        if (left == nullptr && right == nullptr) {
            if (parent == nullptr) {
                delete tree;
                root = nullptr;
            } else {
                if (parent->left->key == v) {
                    delete parent->left;
                    parent->left = nullptr;
                } else {
                    delete parent->right;
                    parent->right = nullptr;
                }
            }
        } else if (left == nullptr) {
            if (parent == nullptr) {
                delete tree;
                root = right;
            } else {
                if (parent->left->key == v) {
                    delete parent->left;
                    parent->left = right;
                } else {
                    delete parent->right;
                    parent->right = right;
                }
            }
        } else if (right == nullptr) {
            if (parent == nullptr) {
                delete tree;
                root = left;
            } else {
                if (parent->left->key == v) {
                    delete parent->left;
                    parent->left = left;
                } else {
                    delete parent->right;
                    parent->right = left;
                }
            }
        } else {
            node *predecessor = max(tree->left);
            int predecessorKey = predecessor->key;
            deleteKey(predecessorKey);
            tree->key = predecessorKey;
        }
    } else if (v < tree->key) {
        if (tree->left != nullptr) {
            deleteKey(tree->left, tree, v);
        }
    } else {
        if (tree->right != nullptr) {
            deleteKey(tree->right, tree, v);
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

    my_tree.deleteKey(12);
    my_tree.print_in_order();
    my_tree.deleteKey(5);
    my_tree.print_in_order();
}
