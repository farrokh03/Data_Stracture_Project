#include <iostream>
using namespace std;

//insert
//search
//delete

class BineryTree{

    private:
        struct binarytreeitems{
            public:
                int data;
                binarytreeitems *leftchild;
                binarytreeitems *rightchild;
        };
        binarytreeitems* newitems;
        binarytreeitems* Root; 
        binarytreeitems* temp;  

        int degree =  0 ;
    public: 
        BineryTree () {
            Root = NULL ;  
            temp = NULL ;
            newitems = NULL ; 
        }

        void InsertTreeItem(int value) {
            newitems = new binarytreeitems;
            newitems->data = value;
            newitems->leftchild = NULL;
            newitems->rightchild = NULL;

            if (Root == NULL) {
                Root = newitems;
                degree++;
            } else {
                temp = Root;
                while (temp != NULL) {
                    if (value > temp->data) {
                        if (temp->rightchild == NULL) {
                            temp->rightchild = newitems;
                            break;
                        }
                        temp = temp->rightchild;
                    } else if (value < temp->data) {
                        if (temp->leftchild == NULL) {
                            temp->leftchild = newitems;
                            break;
                        }
                        temp = temp->leftchild;
                    } else {
                        break;
                    }
                }
            }
        }
        binarytreeitems* getRoot(){
            return Root;
        }
        void inOrderTraversal(binarytreeitems* Root) {
            if (Root != NULL) { 
                inOrderTraversal(Root->leftchild);
                cout << Root->data << " ";
                inOrderTraversal(Root->rightchild);
            }
        }
         void preOrderTraversal(binarytreeitems* Root) {

            if (Root != NULL) {
                cout << Root->data << " ";
                preOrderTraversal(Root->leftchild);
                preOrderTraversal(Root->rightchild);
            }

        }
         void postOrderTraversal(binarytreeitems* Root) {
            if (Root != NULL) { 
                postOrderTraversal(Root->leftchild);
                postOrderTraversal(Root->rightchild);
                cout << Root->data << " ";
            }
        }
        void displayTree(binarytreeitems* Root, int space = 0) {
        if (Root == nullptr) {
            return;
        }

        const int spacing = 5;

        space += spacing;

        displayTree(Root->rightchild, space);

        cout << endl;
        for (int i = spacing; i < space; ++i) {
            cout << " ";
        }
        cout << Root->data << "\n";

        displayTree(Root->leftchild, space);
    }
    void search(int  value ){
        temp = Root; 
        cout<<"address is :"<<"\t";
        while (temp != NULL) {  
            if(value == temp->data){
                cout << temp->data<<"\t";
                break;
            }else if(value >temp->data){
                cout<<temp->data<<"\t";
                temp = temp->rightchild;
            }else if(value < temp->data){
                cout<<temp->data<<"\t";
                temp = temp->leftchild;
            }
        }
    }
    void deleteitems(int value) {
        temp = Root; 
        binarytreeitems* smallestRD;
        binarytreeitems* prevD;
        smallestRD = nullptr;
        prevD = nullptr;

        while (temp != nullptr) {  
            if (value == temp->data) {
                break;
            } else if (value > temp->data) {
                temp = temp->rightchild;
            } else if (value < temp->data) {
                temp = temp->leftchild;
            }
        }
        
        if (temp != nullptr) {
            smallestRD = temp->rightchild;
            prevD = temp->rightchild;
            while (smallestRD != nullptr && smallestRD->leftchild != nullptr) {
                prevD = smallestRD;
                smallestRD = smallestRD->leftchild;
            }

            if (prevD == smallestRD) {
                while (temp->rightchild != nullptr) {
                    prevD = temp;
                    temp->data = temp->rightchild->data;
                    temp = temp->rightchild;
                }
                prevD->rightchild =NULL;
                
            } else {
                temp->data = smallestRD->data;
                if (prevD != nullptr) {
                    prevD->leftchild = smallestRD->rightchild;
                } else {
                    temp->rightchild = smallestRD->rightchild;
                }
                delete smallestRD;
                delete prevD;
            }
        }
    }
    int depthofnodes(int value){
        int deg= 0;
        temp = Root;
        while(temp!=NULL){
            if(value>temp->data){
                temp=temp->rightchild;
                deg++;
            }else if(value <temp->data){
                temp=temp->leftchild;
                deg++;
            }else{
                deg++;
                break;
            }
        }
        return deg;
    }
    int treeDepth(binarytreeitems* Root) {
    if (Root == nullptr) {
        return 0;
    } else {
        int leftDepth = treeDepth(Root->leftchild);
        int rightDepth = treeDepth(Root->rightchild);

        return 1 + max(leftDepth, rightDepth);
    }
}

};


int main(){
    
    return 0;
}