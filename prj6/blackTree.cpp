#include <iostream>
#include <iomanip>

using namespace std;
enum Color { RED, BLACK };


class Node {
public:
    int data;
    Node* Parent;
    Node* LeftChild;
    Node* RightChild;
    Color color;

    Node(int value){
        data = value;
        Parent = nullptr;
        LeftChild = nullptr;
        RightChild = nullptr;
        color = RED;
    }  
};


class RedBlackTree {
private:
    Node* root;
    //function that useing in background
    void insertFixup(Node* newNode);
    void removeFixup(Node* node, Node* Parent);
    void transplant(Node* u, Node* v);
    void leftRotate(Node* x);
    void rightRotate(Node* y);
    void displayUtil(Node* root, int space);
    Node* minimum(Node* subtreeRoot);

public:
    //function that user can use:
    void insert(int value);
    void remove(int value);
    void display();
    RedBlackTree(){
        root = nullptr;
    } 
    

};


void RedBlackTree::insert(int value) {
    Node* newNode = new Node(value);
    Node* Parent = nullptr;
    Node* current = root;

    while (current != nullptr) {
        Parent = current;
        if (value < current->data) {
            current = current->LeftChild;
        } else {
            current = current->RightChild;
        }
    }

    newNode->Parent = Parent;
    if (Parent == nullptr) {
        root = newNode;
    } else if (value < Parent->data) {
        Parent->LeftChild = newNode;
    } else {
        Parent->RightChild = newNode;
    }

    insertFixup(newNode);
}
void RedBlackTree::remove(int value) {
    Node* nodeToRemove = root;

    while (nodeToRemove != nullptr && nodeToRemove->data != value) {
        if (value < nodeToRemove->data) {
            nodeToRemove = nodeToRemove->LeftChild;
        } else {
            nodeToRemove = nodeToRemove->RightChild;
        }
    }

    if (nodeToRemove == nullptr) {
        cout << "Node with value " << value << " not found in the tree." << endl;
        return;
    }

    Node* y = nodeToRemove;
    Node* x;
    Color yOriginalColor = y->color;

    if (nodeToRemove->LeftChild == nullptr) {
        x = nodeToRemove->RightChild;
        transplant(nodeToRemove, nodeToRemove->RightChild);
    } else if (nodeToRemove->RightChild == nullptr) {
        x = nodeToRemove->LeftChild;
        transplant(nodeToRemove, nodeToRemove->LeftChild);
    } else {
        y = minimum(nodeToRemove->RightChild);
        yOriginalColor = y->color;
        x = y->RightChild;

        if (y->Parent == nodeToRemove) {
            if (x != nullptr) {
                x->Parent = y;
            }
        } else {
            transplant(y, y->RightChild);
            y->RightChild = nodeToRemove->RightChild;
            if (y->RightChild != nullptr) {
                y->RightChild->Parent = y;
            }
        }

        transplant(nodeToRemove, y);
        y->LeftChild = nodeToRemove->LeftChild;
        y->LeftChild->Parent = y;
        y->color = nodeToRemove->color;
    }

    if (yOriginalColor == BLACK) {
        removeFixup(x, y->Parent);
    }

    delete nodeToRemove;
}

void RedBlackTree::display() {
    displayUtil(root, 0);
}

void RedBlackTree::displayUtil(Node* root, int space) {
    const int spacing = 5;

    if (root == nullptr) {
        return;
    }

    space += spacing;

    displayUtil(root->RightChild, space);

    cout << endl;
    for (int i = spacing; i < space; i++) {
        cout << " ";
    }

    cout << root->data << "(" << (root->color == RED ? "R" : "B") << ")" << endl;

    displayUtil(root->LeftChild, space);
}

void RedBlackTree::insertFixup(Node* newNode) {
    while (newNode->Parent != nullptr && newNode->Parent->color == RED) {
        if (newNode->Parent == newNode->Parent->Parent->LeftChild) {
            Node* uncle = newNode->Parent->Parent->RightChild;
            if (uncle != nullptr && uncle->color == RED) {
                newNode->Parent->color = BLACK;
                uncle->color = BLACK;
                newNode->Parent->Parent->color = RED;
                newNode = newNode->Parent->Parent;
            } else {
                if (newNode == newNode->Parent->RightChild) {
                    newNode = newNode->Parent;
                    leftRotate(newNode);
                }
                newNode->Parent->color = BLACK;
                newNode->Parent->Parent->color = RED;
                rightRotate(newNode->Parent->Parent);
            }
        } else {
            Node* uncle = newNode->Parent->Parent->LeftChild;
            if (uncle != nullptr && uncle->color == RED) {
                newNode->Parent->color = BLACK;
                uncle->color = BLACK;
                newNode->Parent->Parent->color = RED;
                newNode = newNode->Parent->Parent;
            } else {
                if (newNode == newNode->Parent->LeftChild) {
                    newNode = newNode->Parent;
                    rightRotate(newNode);
                }
                newNode->Parent->color = BLACK;
                newNode->Parent->Parent->color = RED;
                leftRotate(newNode->Parent->Parent);
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::removeFixup(Node* node, Node* Parent) {
    Node* sibling;
    while (node != root && (node == nullptr || node->color == BLACK)) {
        if (node == Parent->LeftChild) {
            sibling = Parent->RightChild;
            if (sibling->color == RED) {
                sibling->color = BLACK;
                Parent->color = RED;
                leftRotate(Parent);
                sibling = Parent->RightChild;
            }
            if ((sibling->LeftChild == nullptr || sibling->LeftChild->color == BLACK) &&
                (sibling->RightChild == nullptr || sibling->RightChild->color == BLACK)) {
                sibling->color = RED;
                node = Parent;
            } else {
                if (sibling->RightChild == nullptr || sibling->RightChild->color == BLACK) {
                    sibling->LeftChild->color = BLACK;
                    sibling->color = RED;
                    rightRotate(sibling);
                    sibling = Parent->RightChild;
                }
                sibling->color = Parent->color;
                Parent->color = BLACK;
                sibling->RightChild->color = BLACK;
                leftRotate(Parent);
                node = root;
            }
        } else {
            sibling = Parent->LeftChild;
            if (sibling->color == RED) {
                sibling->color = BLACK;
                Parent->color = RED;
                rightRotate(Parent);
                sibling = Parent->LeftChild;
            }
            if ((sibling->RightChild == nullptr || sibling->RightChild->color == BLACK) &&
                (sibling->LeftChild == nullptr || sibling->LeftChild->color == BLACK)) {
                sibling->color = RED;
                node = Parent;
            } else {
                if (sibling->LeftChild == nullptr || sibling->LeftChild->color == BLACK) {
                    sibling->RightChild->color = BLACK;
                    sibling->color = RED;
                    leftRotate(sibling);
                    sibling = Parent->LeftChild;
                }
                sibling->color = Parent->color;
                Parent->color = BLACK;
                sibling->LeftChild->color = BLACK;
                rightRotate(Parent);
                node = root;
            }
        }
    }
    if (node != nullptr) {
        node->color = BLACK;
    }
}

void RedBlackTree::transplant(Node* u, Node* v) {
    if (u->Parent == nullptr) {
        root = v;
    } else if (u == u->Parent->LeftChild) {
        u->Parent->LeftChild = v;
    } else {
        u->Parent->RightChild = v;
    }
    if (v != nullptr) {
        v->Parent = u->Parent;
    }
}

Node* RedBlackTree::minimum(Node* subtreeRoot) {
    while (subtreeRoot->LeftChild != nullptr) {
        subtreeRoot = subtreeRoot->LeftChild;
    }
    return subtreeRoot;
}

void RedBlackTree::leftRotate(Node* x) {
    Node* y = x->RightChild;
    x->RightChild = y->LeftChild;
    if (y->LeftChild != nullptr) {
        y->LeftChild->Parent = x;
    }
    y->Parent = x->Parent;
    if (x->Parent == nullptr) {
        root = y;
    } else if (x == x->Parent->LeftChild) {
        x->Parent->LeftChild = y;
    } else {
        x->Parent->RightChild = y;
    }
    y->LeftChild = x;
    x->Parent = y;
}

void RedBlackTree::rightRotate(Node* y) {
    Node* x = y->LeftChild;
    y->LeftChild = x->RightChild;
    if (x->RightChild != nullptr) {
        x->RightChild->Parent = y;
    }
    x->Parent = y->Parent;
    if (y->Parent == nullptr) {
        root = x;
    } else if (y == y->Parent->LeftChild) {
        y->Parent->LeftChild = x;
    } else {
        y->Parent->RightChild = x;
    }
    x->RightChild = y;
    y->Parent = x;
}