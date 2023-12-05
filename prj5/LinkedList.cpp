#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insert_at_end(int data)
    {
        Node *newNode = new Node(data);
        if (this->head)
        {
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = NULL;
        }
        else
        {
            this->head = newNode;
            return;
        }
    }

    void insert_at_beginning(int data)
    {
        Node *newNode = new Node(data);
        Node *current = head;
        if (current)
        {
            newNode->next = current;
            this->head = newNode;
        }
        else
        {
            this->head = newNode;
            newNode->next = NULL;
        }
    }

    void print_list()
    {
        int index = 0;
        Node *current = head;
        if (current)
        {
            while (current != NULL)
            {
                cout << index << ") " << current->data << "\t";
                current = current->next;
                index++;
            }
        }
        else
        {
            cout << "Empty List!!!";
        }
    }

    int list_size()
    {
        int count = 0;
        Node *current = head;
        while (current->next != NULL)
        {
            count++;
            current = current->next;
        }

        return ++count;
    }

    void insert_at_index(int data, int index)
    {
        Node *newNode = new Node(data);
        Node *current = head;
        Node *previous;
        int position = 0;
        if (current)
        {
            while (current && position < index)
            {
                previous = current;
                current = current->next;
                position++;
            }

            if (index == 0)
            {
                this->insert_at_beginning(data);
            }
            else if (index >= this->list_size())
            {
                cout << "Index Out Of Range";
            }
            else
            {
                newNode->next = previous->next;
                previous->next = newNode;
            }
        }
        else
        {
            cout << "List Is Empty!!!";
        }
    }
};
