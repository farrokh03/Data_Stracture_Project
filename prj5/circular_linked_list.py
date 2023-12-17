class Node:
    def __init__(self, data):
        self.data = data
        self.next_node = None


class CircularLinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def insert_at_index(self, index, data):
        new_node = Node(data)
        if index == 0:
            if not self.head:
                new_node.next_node = new_node
                self.head = new_node
            else:
                new_node.next_node = self.head
                current = self.head
                while current.next_node != self.head:
                    current = current.next_node
                current.next_node = new_node
                self.head = new_node
        else:
            current = self.head
            for _ in range(index - 1):
                current = current.next_node
            new_node.next_node = current.next_node
            current.next_node = new_node

        self.size += 1

    def insert_at_begin(self, data):
        self.insert_at_index(0, data)

    def insert_at_end(self, data):
        self.insert_at_index(self.size, data)

    def update_node(self, index, data):
        current = self.head
        for _ in range(index):
            current = current.next_node
        current.data = data

    def remove_node_at_index(self, index):
        if self.size == 1:
            data = self.head.data
            self.head = None
        else:
            current = self.head
            for _ in range(index - 1):
                current = current.next_node
            data = current.next_node.data
            current.next_node = current.next_node.next_node

        self.size -= 1
        return data

    def remove_node_at_begin(self):
        return self.remove_node_at_index(0)

    def remove_node_at_end(self):
        return self.remove_node_at_index(self.size - 1)

    def size_of_list(self):
        return self.size

    def concatenate(self, other_list):
        if not other_list.head:
            return

        if not self.head:
            self.head = other_list.head
        else:
            current = self.head
            while current.next_node and current.next_node != self.head:
                current = current.next_node
            current.next_node = other_list.head

            current = other_list.head
            while current.next_node and current.next_node != other_list.head:
                current = current.next_node
            current.next_node = self.head
        
    def invert(self):
        if not self.head:
            return
        prev = None
        current = self.head
        next_node = None
        while True:
            next_node = current.next_node
            current.next_node = prev
            prev = current
            current = next_node
            if current == self.head:
                break
        self.head = prev