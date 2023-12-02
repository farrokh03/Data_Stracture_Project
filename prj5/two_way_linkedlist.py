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

# Finished Methods Above

    def remove_at_index(self, index):
        pass

    def update_at_index(self, data, index):
        pass

    def insert_at_index(self, data, index):
        pass

    def invert(self):
        pass

    def concatenate(self):
        pass


sample = TwoWayLinkedList()


sample.insert_at_end(4)
sample.insert_at_end(2)
sample.insert_at_end(1232)
sample.insert_at_end(123212312)
sample.insert_at_begin(2444)


print("Size is :", sample.list_size())
sample.display()

# Bugs
# If deleting continues with remove_end method until one node remain previous.next will be None
