#include <iostream>

using namespace std;
class Tree{

    private:

        class TreeNode {
            public:
                int data;
                TreeNode* child;
                TreeNode* sibling;
        };
        TreeNode* Root;
        TreeNode* Template;
        TreeNode* NewItem;
        TreeNode* secondryTemplate;

    public:
        Tree(){
            Root= NULL;
            Template = NULL;
            secondryTemplate = NULL; 
        }
        TreeNode* getRoot(){
            return Root;
        }
        TreeNode* inOrderTraversal(TreeNode* root,int DATA) {
            if (root != NULL) { 
                inOrderTraversal(root->child , DATA);
                if(root->data == DATA){
                    Template = root;   
                }
                inOrderTraversal(root->sibling,DATA);
            }
            return Template;
        }
        
        
        void displayTree(TreeNode* root) {
            if (root != NULL) { 
                cout << root->data << " ";
                displayTree(root->sibling);
                displayTree(root->child);
            }
        }

        void InsertNode(int value , int Data){
            NewItem = new TreeNode;
            NewItem->data = value;
            NewItem->sibling = NULL;
            NewItem->child = NULL;

            if(Root == NULL){
                Root = NewItem;
            }else{
                Template = inOrderTraversal(Root,Data);
                if(Template->child == NULL){
                    Template->child = NewItem ;
                 
                }else{
                    Template = Template->child;
                    while(Template->sibling!=NULL){
                        Template = Template->sibling;
                    }
                    Template->sibling= NewItem ;
           
                }
                    
            }

        }
        void DeleteNode(int value){
            Template = inOrderTraversal(Root,value);
            Template->child = NULL;
            if(Template->sibling == nullptr){ 
                Template =findParent(Root , Template);
                Template->child = nullptr;
                
            }else{
                
                TreeNode* Prev = Template;
            
                while(Template->sibling!= NULL){
                    Prev = Template;
                    Template->data = Template->sibling->data;
                    Template->child = Template->sibling->child;
                    Template = Template->sibling;
                }
                Prev->sibling =nullptr;
            }
        }     
        TreeNode* findParent(TreeNode* root, TreeNode* target) {
            if (root == NULL || target == NULL) {
                return NULL;
            }

            TreeNode* parent = root;
            TreeNode* current = root->child;

            while (current != NULL) {
                if (current == target) {
                    return parent;
                }

                parent = current;
                current = current->sibling;
            }

            current = root->child;

            while (current != NULL) {
                TreeNode* result = findParent(current, target);
                if (result != NULL) {
                    return result;
                }
                current = current->sibling;
            }

            return NULL;
        }
        
    
};
int main(){
    Tree obj;
    obj.InsertNode(5,0);
    obj.InsertNode(7,5);
    obj.InsertNode(12,5);
    obj.InsertNode(25,12);
    obj.displayTree(obj.getRoot());
    obj.DeleteNode(7);
    obj.DeleteNode(12);
    cout<<endl;
    obj.displayTree(obj.getRoot());


    return 0;
}