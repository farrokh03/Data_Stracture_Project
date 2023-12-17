class Node:
    def __init__(self, next_node=None, data=None):
        self.next = next_node
        self.data = data


class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def insert_at_index(self, data, index):
        new_node = Node(data)
        if index == 0:
            new_node.next = self.head
            self.head = new_node
        else:
            current = self.head
            for _ in range(index - 1):
                current = current.next
            new_node.next = current.next
            current.next = new_node
        self.size += 1

    def insert_at_end(self, data):
        self.insert_at_index(data, self.size)

    def insert_to_beginning(self, data):
        self.insert_at_index(data, 0)

    def update_node(self, index, data):
        current = self.head
        for _ in range(index):
            current = current.next
        current.data = data

    def remove_data_at_index(self, index):
        if index == 0:
            data = self.head.data
            self.head = self.head.next
        else:
            current = self.head
            for _ in range(index - 1):
                current = current.next
            data = current.next.data
            current.next = current.next.next

        self.size -= 1
        return data

    def remove_node_at_begin(self):
        return self.remove_data_at_index(0)

    def remove_node_at_end(self):
        return self.remove_data_at_index(self.size - 1)

    def size_of_linked_list(self):
        return self.size

    def concatenate(self, list2):
        if not self.head:
            self.head = list2.head
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = list2.head

    def invert(self):
        prev = None
        current = self.head
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        self.head = prev


