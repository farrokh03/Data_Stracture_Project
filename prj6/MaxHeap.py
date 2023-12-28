class MaxHeap:
    def __init__(self):
        self.heap_array = list()
        self.order = 0

    def insert(self, data):
        self.heap_array.append(data)
        self.order += 1
        self.heap_insert_order(len(self.heap_array) - 1)

    def heap_insert_order(self, order):
        parent = int((order - 1) / 2)

        if self.heap_array[parent] > 0:
            if self.heap_array[order] > self.heap_array[parent]:
                self.heap_array[order], self.heap_array[parent] = self.heap_array[parent], self.heap_array[order]

                self.heap_insert_order(parent)

    def remove(self, data):
        pass

    def heap_remove_order(self, order, root_index):
        left_child = (2 * order) + 1
        right_child = (2 * order) + 2

        root = root_index

        pass

    def display(self):
        print(self.heap_array)


sample = MaxHeap()


sample.insert(40)
sample.insert(30)
sample.insert(24)
sample.insert(10)
sample.insert(20)
sample.insert(5)
sample.insert(3)


sample.display()
