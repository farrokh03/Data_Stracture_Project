class Node():
    def __init__(self, data):
        self.data = data
        self.next = None
        self.previous = None


class TwoWayLinkedList():
    def __init__(self):
        self.head = None

    def insert_at_end(self, data):
        newNode = Node(data)
        current = self.head
        if (current):
            while (current.next):
                current = current.next
            current.next = newNode
            newNode.previous = current
        else:
            self.head = newNode

    def insert_at_begin(self, data):
        newNode = Node(data)
        current = self.head
        if (current):
            current.previous = newNode
            newNode.next = current
            self.head = newNode
        else:
            self.head = newNode

    def display(self):
        current = self.head
        while (current):
            print(current.data)
            current = current.next

    def list_size(self):
        counter = 0
        current = self.head
        while (current):
            current = current.next
            counter += 1
        return counter

    def remove_end(self):
        current = self.head
        previous = None
        if (current):
            while (current.next != None):
                previous = current
                current = current.next
            previous.next = None
        else:
            print("List is Empty!!!")

    def remove_head(self):
        current = self.head
        if (current):
            self.head = current.next
        else:
            print("List is Empty!!!")

    def remove_until_index(self, index):
        current = self.head
        position = 0
        if (current):
            while (current and position < index):
                previous = current
                current = current.next
                position += 1
            if (position < index):
                print("index out of range")
            elif index == 0:
                self.remove_head()
            elif index == self.list_size():
                return 0
            else:
                removed_data = current.data
                current.previous = None
                previous.next = current
                self.head = current
                current = current.next
                return removed_data
        else:
            print("Empty List!!")

    def remove_at_index(self, index):
        current = self.head
        position = 0
        if (current == None):
            return 0
        else:
            print()
        while current and position < index:
            previous = current
            current = current.next
            position += 1

        if index == 0:
            return self.remove_head()
        elif position < index:
            print("index out of range")
        elif (index == self.list_size() - 1):
            self.remove_end()
        else:
            removed_data = current.data
            previous.next = current.next
            current.next = None
            return removed_data

    def update_at_index(self, data, index):
        pass

    def insert_at_index(self, data, index):
        newNode = Node(data)
        current = self.head
        position = 0
        while current and position < index:
            previous = current
            current = current.next
            position += 1

        if (index == 0):
            self.insert_at_begin()
        elif (index == self.list_size()):
            self.insert_at_end()
        elif (position < index):
            print("Index out of range!!")
        else:
            current.previous = newNode
            newNode.next = current
            newNode.previous = previous
            previous.next = newNode

# Finished Methods Above

    def invert(self):
        pass

    def concatenate(self):
        pass
