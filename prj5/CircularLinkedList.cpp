#include<iostream>
using namespace std;




class CircularLinkedList{

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
        int size = 0;

    public:
    // Constructor to initialize pointers
        CircularLinkedList() {
            firstnode = NULL;
            lastnode = NULL;
            newnode = NULL;
            temp = NULL;
        }
        int SizeofList() {
            return size;
        }
        void display(){
            temp = firstnode ;
            for(int i = 1 ; i<= size ; i++ ){
                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }

        void InsertAtEnd(int value) {
            newnode = new ListItem;
            if( size == 0 ) {
                size++;
                newnode->data = value;
                newnode->next = newnode;
                firstnode = newnode;
                lastnode = newnode;
            } else {
                size++;
                lastnode->next = newnode;
                newnode->next = firstnode; 
                newnode->data = value;
                lastnode = newnode;
                
            }
        }  
        void InsertAtBegin(int value) {
            newnode = new ListItem;
            if( size == 0 ){
                size++;
                newnode->data = value;
                newnode->next = newnode;
                firstnode = newnode ;
                lastnode = newnode ;
            } else {
                size++;
                newnode->data = value ;
                newnode->next = firstnode;
                firstnode = newnode;
                lastnode->next = firstnode ;
            }
        }
        void InsertAtIndex(int index , int value) {
            newnode = new ListItem;
            size++;
            temp = firstnode;
            for(int i=1 ; i<index-1;i++){

                temp = temp->next;
            }
            newnode->data = value;
            newnode->next = temp->next;
            temp->next = newnode;
        }
        ~CircularLinkedList() {
            temp = firstnode;
            while (temp != lastnode) {
                ListItem* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
        }
        void RemoveNodeAtIndex(int index) {
            size--;
            temp = firstnode;
            if(index == 1 ) {
                firstnode = temp->next ;
                temp->next = NULL;

            } else {
                for(int i=1 ; i<index-1;i++){

                    temp = temp->next;
                }
                ListItem* current = temp->next;
                temp->next = current->next;
                current->next = NULL ;
                delete current;
            }    
        }
          int RemoveNodeAtEnd() {
            int deleted;
            if (SizeofList() == 0) {
                cout << "List is empty"<< endl;
            } else if (SizeofList() == 1) {
                size--;
                delete temp;
                deleted = lastnode->data;    
                firstnode = lastnode = NULL;
            } else {
                size--;
                temp = firstnode;
                while (temp->next != lastnode) {
                    temp = temp->next;
                }
                deleted = lastnode->data;
                temp->next = firstnode;
                lastnode->next = NULL;
                lastnode = temp;
            }
            return deleted;
        }
        int  RemoveNodeAtBegin() {
            int deleted;

            if (SizeofList() == 0) {
                cout << "List is empty. Cannot remove from the end." << endl;
            } else if (SizeofList() == 1) {
                size--;
                delete temp;
                 deleted=firstnode->data;
                firstnode = lastnode = NULL;
                
            } else {
               size--;
               temp = firstnode;
               temp = temp->next;
                deleted = firstnode->data ;
               firstnode->next = NULL;
               firstnode = temp;
               
            }
            return deleted;
        }
        void UpdateNode(int value , int index) {
            temp = firstnode;
            for(int i = 1 ; i<index ; i++ ){
                temp = temp->next; 
            }
            temp->data = value;
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

            temp = firstnode;
            firstnode = lastnode;
            lastnode = temp;
        }
        void Concatenate(CircularLinkedList& otherList) {
            size = size+otherList.SizeofList();
            if (otherList.firstnode != NULL) {
                if (firstnode != NULL) {
                    lastnode->next = otherList.firstnode;
                    lastnode = otherList.lastnode;
                    lastnode->next = firstnode;
                } else {
                    
                    firstnode = otherList.firstnode;
                    lastnode = otherList.lastnode;
                    lastnode->next = firstnode;
                }

                otherList.firstnode = NULL;
                otherList.lastnode = NULL;
            }
        }


        
        
};        
int main(){
    CircularLinkedList obj;
    CircularLinkedList obj2;

    obj.InsertAtEnd(1);
    obj.InsertAtEnd(2);
    obj.InsertAtEnd(3);
    cout<<endl<<"first list:"<<endl;
    obj.display();


    obj2.InsertAtEnd(4);
    obj2.InsertAtEnd(5);
    obj2.InsertAtEnd(6);
    cout<<endl<<"second list:"<<endl;
    obj2.display();
    cout<<endl<<"after concatenet:"<<endl;
    obj.Concatenate(obj2);
    obj.display();
    

    return 0;
}