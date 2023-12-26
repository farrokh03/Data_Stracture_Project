class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None


class HashTable:
    def __init__(self, capacity=10):
        self.size = 0
        self.capacity = capacity
        self.table = [None] * capacity

    def hash_func(self, key):
        return hash(key) % self.capacity

    def insert(self, key, value):
        index = self.hash_func(key)

        if not self.table[index]:
            self.table[index] = Node(key, value)
            self.size += 1
        else:
            current = self.table[index]

            while current:
                if current.key == key:
                    current.value = value
                    return
                current = current.next

            new_node = Node(key, value)
            new_node.next = self.table[index]
            self.table[index] = new_node
            self.size += 1

    def remove(self, key):
        index = self.hash_func(key)

        current = self.table[index]
        previous = None

        try:
            while current:
                if current.key == key:
                    if previous:
                        previous.next = current.next
                    else:
                        self.table[index] = current.next

                    self.size -= 1
                    return
                previous = current
                current = current.next
        except:
            raise KeyError(key)

    def table_size(self):
        return self.size

    def search(self, key):
        index = self.hash_func(key)
        current = self.table[index]

        try:
            while current:
                if current.key == key:
                    return current.value

                current = current.next

        except:
            raise KeyError(key)

    def has_table(self, key):
        index = self.hash_func(key)
        return index
