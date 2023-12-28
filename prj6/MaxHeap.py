class MaxHeap:
    def __init__(self):
        self.heap_array = list()
        self.size = 0

    def insert(self, data):
        self.heap_array.append(data)
        self.size += 1
        self.heap_insert_order(len(self.heap_array) - 1)

    def heap_insert_order(self, size):
        parent = int((size - 1) / 2)

        if self.heap_array[parent] > 0:
            if self.heap_array[size] > self.heap_array[parent]:
                self.heap_array[size], self.heap_array[parent] = self.heap_array[parent], self.heap_array[size]

                self.heap_insert_order(parent)

    def remove_root(self):
        if self.size == 0:
            print("Heap is Empty!!")
        else:
            max_value = self.heap_array[0]

            self.heap_array[0] = self.heap_array[self.size - 1]
            self.heap_array.pop()
            self.size -= 1

            self.remove_root_order(0)

    def remove_root_order(self, root_index):
        largest = root_index

        left_child = (2 * root_index) + 1
        right_child = (2 * root_index) + 2

        if left_child < self.size and self.heap_array[left_child] > self.heap_array[largest]:
            largest = left_child

        if right_child < self.size and self.heap_array[right_child] > self.heap_array[largest]:
            largest = right_child

        if largest != root_index:
            self.heap_array[root_index], self.heap_array[largest] = self.heap_array[largest], self.heap_array[root_index]
            self.remove_root_order(largest)
