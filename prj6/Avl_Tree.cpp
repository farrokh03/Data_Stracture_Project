#include <iostream>
#include <algorithm>

using namespace std;
class AVLTree {
private:
    struct TreeNode {
        int value;
        TreeNode* leftChild;
        TreeNode* RightChild;
        int Height;

        TreeNode(int k) : value(k), leftChild(nullptr), RightChild(nullptr), Height(1) {}
    };

    TreeNode* Root;

    int Height(TreeNode* Node) {
        if (Node == nullptr)
            return 0;
        return Node->Height;
    }

    int balanceFactor(TreeNode* Node) {
        if (Node == nullptr)
            return 0;
        return Height(Node->leftChild) - Height(Node->RightChild);
    }

    TreeNode* RightRotate(TreeNode* y) {
        TreeNode* x = y->leftChild;
        TreeNode* T2 = x->RightChild;

        x->RightChild = y;
        y->leftChild = T2;

        y->Height = max(Height(y->leftChild), Height(y->RightChild)) + 1;
        x->Height = max(Height(x->leftChild), Height(x->RightChild)) + 1;

        return x;
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->RightChild;
        TreeNode* T2 = y->leftChild;

        y->leftChild = x;
        x->RightChild = T2;

        x->Height = max(Height(x->leftChild), Height(x->RightChild)) + 1;
        y->Height = max(Height(y->leftChild), Height(y->RightChild)) + 1;

        return y;
    }

    TreeNode* InsertNode(TreeNode* Node, int value) {
        if (Node == nullptr)
            return new TreeNode(value);

        if (value < Node->value)
            Node->leftChild = InsertNode(Node->leftChild, value);
        else if (value > Node->value)
            Node->RightChild = InsertNode(Node->RightChild, value);
        else
            return Node;

        Node->Height = 1 + max(Height(Node->leftChild), Height(Node->RightChild));

        int balance = balanceFactor(Node);

     
        if (balance > 1 && value < Node->leftChild->value)
            return RightRotate(Node);

       
        if (balance < -1 && value > Node->RightChild->value)
            return leftRotate(Node);

        
        if (balance > 1 && value > Node->leftChild->value) {
            Node->leftChild = leftRotate(Node->leftChild);
            return RightRotate(Node);
        }

    
        if (balance < -1 && value < Node->RightChild->value) {
            Node->RightChild = RightRotate(Node->RightChild);
            return leftRotate(Node);
        }

        return Node;
    }

    TreeNode* minValueNode(TreeNode* Node) {
        TreeNode* current = Node;
        while (current->leftChild != nullptr)
            current = current->leftChild;
        return current;
    }

    TreeNode* RemoveNode(TreeNode* Root, int value) {
        if (Root == nullptr)
            return Root;

        if (value < Root->value)
            Root->leftChild = RemoveNode(Root->leftChild, value);
        else if (value > Root->value)
            Root->RightChild = RemoveNode(Root->RightChild, value);
        else {
            if ((Root->leftChild == nullptr) || (Root->RightChild == nullptr)) {
                TreeNode* temp = Root->leftChild ? Root->leftChild : Root->RightChild;
                if (temp == nullptr) {
                    temp = Root;
                    Root = nullptr;
                } else {
                    *Root = *temp;
                }
                delete temp;
            } else {
                TreeNode* temp = minValueNode(Root->RightChild);
                Root->value = temp->value;
                Root->RightChild = RemoveNode(Root->RightChild, temp->value);
            }
        }

        if (Root == nullptr)
            return Root;

        Root->Height = 1 + max(Height(Root->leftChild), Height(Root->RightChild));

        int balance = balanceFactor(Root);

       
        if (balance > 1 && balanceFactor(Root->leftChild) >= 0)
            return RightRotate(Root);

        
        if (balance > 1 && balanceFactor(Root->leftChild) < 0) {
            Root->leftChild = leftRotate(Root->leftChild);
            return RightRotate(Root);
        }

        if (balance < -1 && balanceFactor(Root->RightChild) <= 0)
            return leftRotate(Root);

        if (balance < -1 && balanceFactor(Root->RightChild) > 0) {
            Root->RightChild = RightRotate(Root->RightChild);
            return leftRotate(Root);
        }

        return Root;
    }

    void inOrderTraversal(TreeNode* Node) {
        if (Node != nullptr) {
            inOrderTraversal(Node->leftChild);
            cout << Node->value << " ";
            inOrderTraversal(Node->RightChild);
        }
    }

public:
    AVLTree() : Root(nullptr) {}

    void InsertNode(int value) {
        Root = InsertNode(Root, value);
    }

    void remove(int value) {
        Root = RemoveNode(Root, value);
    }

    void printInOrder() {
        cout << "In-order traversal: ";
        inOrderTraversal(Root);
        cout << "\n";
    }
    void displayTree(TreeNode* Node, int space = 0) {
        if (Node == nullptr) {
            return;
        }

        const int spacing = 5;

        space += spacing;

        displayTree(Node->RightChild, space);

        cout << endl;
        for (int i = spacing; i < space; ++i) {
            cout << " ";
        }
        cout << Node->value << "\n";

        displayTree(Node->leftChild, space);
    }
    void display(){
        displayTree(Root,0);
    }
};