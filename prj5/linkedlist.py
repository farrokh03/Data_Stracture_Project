class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next


class LinkedList:

    def __init__(self):
        self.head = None

    def insert_at_end(self, data):
        newNode = Node(data)
        if (self.head):
            current = self.head
            while (current.next):
                current = current.next
            current.next = newNode
        else:
            self.head = newNode

    def insert_at_begin(self, data):

        newNode = Node(data)
        if (self.head):
            current = self.head
            newNode.next = current
            self.head = newNode
        else:
            self.head = newNode

    def remove_end(self):
        current = self.head
        while (current.next.next):
            current = current.next
        removed_data = current.next.data
        current.next = None
        return removed_data

    def remove_head(self):
        if (self.head is None):
            current = self.head
            temp_data = current.data
            return temp_data
        else:
            current = self.head
            temp_data = current.data
            self.head = current.next
            return temp_data

    def display(self):
        current = self.head
        while (current):
            print(current.data)
            current = current.next

    def list_size(self):
        counter = 0
        current = self.head
        while (current != None):
            current = current.next
            counter += 1
        return counter

    def remove_at_index(self, index):

        if (self.head) is None:
            return
        position = 0
        current = self.head
        while current and position < index:
            previous = current
            current = current.next
            position += 1

        if position < index:
            print("index out of range")
        elif index == 0:
            self.head = self.head.next
        else:
            previous.next = current.next

    def update_node(self, data, index):
        newNode = Node(data)
        position = 0
        if (self.head):
            current = self.head
            while (current and position < index):
                previous = current
                current = current.next
                position += 1

            if position < index:
                print("Index out of range")
            elif index == 0:
                self.head.data = data
            else:
                try:
                    newNode.next = current.next
                    previous.next = newNode
                except:
                    print("Index out of range")
        else:
            print("No node exists to update, add one and then try updating")

    def insert_at_index(self, data, index):
        newNode = Node(data)
        if (self.head):
            current = self.head
            position = 0
            while (current and position < index):
                previous = current
                current = current.next
                position += 1
            if index == 0:
                self.insert_at_begin(data)
            elif index == self.list_size() - 1:
                self.insert_at_end(data)
            else:
                previous.next = newNode
                newNode.next = current
        else:
            print("List is empty")

    def invert(self):
        previous = None
        current = self.head
        while (current.next != None):
            self.next = current.next
            current.next = previous
            previous = current
            current = self.next
        self.head = previous
        print(current.data)
        self.display()
# Finished sections ABOVE

    def concatenate(self, linked_list):
        local_linked_list = LinkedList()
        to_concatenate = linked_list.head
        current = self.head
        while (current):
            current = current.next
        current.next = to_concatenate
# BUGS
