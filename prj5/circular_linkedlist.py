class Node():
    def __init__(self, data=None):
        self.data = data
        self.next = None


class CircularLinkedList():
    def __init__(self):
        self.last = None
        self.head = None

    def insert_at_end(self, data):
        newNode = Node(data)
        current = self.last
        if (current):
            newNode.next = current.next
            current.next = newNode
            self.last = newNode
        else:
            self.last = newNode

    def insert_at_beginning(self, data):
        newNode = Node(data)
        current = self.head
        if (current):
            self.last.next = newNode
            newNode.next = self.head
            self.head = newNode
        else:
            self.last = newNode
            self.head = newNode

    def display(self):
        current = self.head
        if (self.head):
            while (current != self.last):
                print(current.data)
                current = current.next
            print(current.data)
        else:
            print("List is empty!!")

    def remove_head(self):
        if (self.head):
            current = self.head
            self.last.next = current.next
            self.head = self.last.next
            return current.data
        else:
            print("List is empty")

    def list_size(self):
        counter = 0
        current = self.head
        while (current != self.last):
            counter += 1
            current = current.next
        return counter + 1

    def remove_end(self):
        current = self.head
        if (self.head):
            while (current != self.last):
                previous = current
                current = current.next
            removed_data = current.data
            self.last = previous
            previous.next = self.head
            return removed_data
        else:
            print("List is empty!!!")

    def insert_at_index(self, data, index):
        newNode = Node(data)
        position = 0
        current = self.head
        if (index > self.list_size()):
            return 0
        if (current):
            while (current and position < index):
                previous = current
                current = current.next
                position += 1
            if index == 0:
                self.insert_at_beginning(data)
            else:
                newNode.next = previous.next
                previous.next = newNode
        else:
            print("List is empty!!!")

# Finished sections ABOVE

    # Modify needed some cases index == 0 returns None
    def remove_at_index(self, index):
        current = self.head
        position = 0
        if (current):
            while (current and position < index):
                previous = current
                current = current.next
                position += 1
            if (index == 0):
                return self.remove_head
            elif (index == self.list_size()):
                self.remove_end
            else:
                previous.next = current.next
                return current.data

        else:
            print("list is empty")


# BUGS
