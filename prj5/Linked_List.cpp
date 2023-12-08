#include<iostream>
using namespace std;




class LinkedList{

    private:
        struct ListItem{
            public:
                int data;
                struct ListItem *next;
        };
        ListItem* firstnode;
        ListItem* lastnode;
        ListItem* newnode;
        ListItem* temp;

    public:
    // Constructor to initialize pointers
        LinkedList() {
            firstnode = NULL;
            lastnode = NULL;
            newnode = NULL;
            temp = NULL;
        }
        
    
        void InsertAtIndex(int index , int value) {

            temp = firstnode;
            for(int i=1 ; i<index;i++){

                temp = temp->next;
            }
            newnode->data = value ;
            newnode->next = temp->next;
            temp->next = newnode;
            

        }

        void InsertAtEnd(int value) {
            newnode = new ListItem;
            if(SizeofList()==0) {
                 newnode->data = value;
                 newnode->next = NULL;
                 firstnode = newnode;
                 lastnode = newnode;
            } else {
                lastnode->next = newnode;
                newnode->data = value;
                newnode->next = NULL; 
                lastnode = newnode;
            }
        }   

        void InsertAtBegin(int value) {
            newnode = new ListItem;
            if(SizeofList() == 0 ){
                newnode->data = value;
                newnode->next = NULL;
                lastnode = newnode;
                firstnode =newnode; 
            } else {

                newnode->data = value ;
                newnode->next = firstnode;
                firstnode = newnode;
            }
            
            
        }

        void UpdateNode(int value , int index) {
            temp = firstnode;
            for(int i = 1 ; i<index ; i++ ){
                temp = temp->next; 
            }
            temp->data = value;
        }
        int SizeofList() {
            temp =  firstnode;
            int counter = 0;
            for( ; temp!= NULL ; temp = temp->next ){
                counter++;
            }

            return counter;
        }
        void display(){
            temp = firstnode ;
            for( temp = firstnode;temp!= NULL ;temp = temp->next )
                cout<<temp->data<<endl;
        }
        ~LinkedList() {
            temp = firstnode;
            while (temp != NULL) {
                ListItem* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
        }
        void RemoveNodeAtIndex(int index) {
            temp = firstnode;
            for(int i=1 ; i<index-1;i++){

                temp = temp->next;
            }
            ListItem* current = temp->next;
            temp->next = current->next;
            current->next = NULL ;
            delete current;
        }
       void RemoveNodeAtEnd() {
            
            if (SizeofList() == 0) {
                cout << "List is empty"<< endl;
            } else if (SizeofList() == 1) {
            delete temp;
            firstnode = lastnode = NULL;
            } else {
                temp = firstnode;
                while (temp->next != lastnode) {
                    temp = temp->next;
                }
                temp->next = NULL;
                lastnode = temp;
            }
        }
            
           
        void RemoveNodeAtBegin() {

             if (SizeofList() == 0) {
                cout << "List is empty. Cannot remove from the end." << endl;
            } else if (SizeofList() == 1) {
            delete temp;
            firstnode = lastnode = NULL;
            } else {
               temp = firstnode;
               temp = temp->next;
               firstnode->next = NULL;
               firstnode = temp;
            }

        }
        void Concatenate(LinkedList& otherList) {
            if (otherList.firstnode != NULL) {
                if (lastnode != NULL) {
                    lastnode->next = otherList.firstnode;
                    lastnode = otherList.lastnode;
                } else {
                    
                    firstnode = otherList.firstnode;
                    lastnode = otherList.lastnode;
                }

                otherList.firstnode = NULL;
                otherList.lastnode = NULL;
            }
    }
        void Reverse() {
            if (firstnode == NULL || firstnode->next == NULL) {
                return;
            }

            ListItem* prev = NULL;
            ListItem* current = firstnode;
            ListItem* nextNode = NULL;

            while (current != NULL) {
                nextNode = current->next;
                current->next = prev;
                prev = current;
                current = nextNode;
            }

            firstnode = prev;
        }
};


int main(){
   
    return 0;
}
