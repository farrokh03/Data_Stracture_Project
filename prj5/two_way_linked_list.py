class Node:
    def __init__(self, data):
        self.data = data
        self.prev_node = None
        self.next_node = None


class two_way_linked_list:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def insert_at_index(self, index, data):
        new_node = Node(data)

        if index == 0:
            if not self.head:
                self.head = new_node
                self.tail = new_node
            else:
                new_node.next_node = self.head
                self.head.prev_node = new_node
                self.head = new_node
        elif index == self.size:
            new_node.prev_node = self.tail
            self.tail.next_node = new_node
            self.tail = new_node
        else:
            current = self.head
            for _ in range(index - 1):
                current = current.next_node
            new_node.next_node = current.next_node
            new_node.prev_node = current
            current.next_node.prev_node = new_node
            current.next_node = new_node

        self.size += 1

    def insert_at_begin( self,data):
        self.insert_at_index(0,data)


    def insert_at_end(self,data):
        self.insert_at_index(self.size,data)

    def update_node(self, index, data):
        current = self.head
        for _ in range(index):
            current = current.next_node
        current.data = data

    def remove_node_at_index(self, index):

        if self.size == 1:
            data = self.head.data
            self.head = None
            self.tail = None
        elif index == 0:
            data = self.head.data
            self.head = self.head.next_node
            self.head.prev_node = None
        elif index == self.size - 1:
            data = self.tail.data
            self.tail = self.tail.prev_node
            self.tail.next_node = None
        else:
            current = self.head
            for _ in range(index):
                current = current.next_node
            data = current.data
            current.prev_node.next_node = current.next_node
            current.next_node.prev_node = current.prev_node

        self.size -= 1
        return data
    
    def remove_node_at_begin(self):
        return self.remove_node_at_index(0)
    
    def remove_node_at_end(self):
        return self.remove_node_at_index(self.size - 1)
    

    def size_of_list(self):
        return self.size
    

    def invert(self):
        current = self.head
        while current:
            current.prev_node, current.next_node = current.next_node, current.prev_node
            current = current.prev_node
        self.head, self.tail = self.tail, self.head

    def concatenate(self, linked_list):

        if not self.head:
            self.head = linked_list.head
            self.tail = linked_list.tail
        else:
            self.tail.next_node = linked_list.head
            linked_list.head.prev_node = self.tail
            self.tail = linked_list.tail

        self.size += linked_list.size

