class MinHeap:

    def __init__(self):
        self.heap_array = list()
        self.size = 0

    def insert(self, data):
        self.heap_array.append(data)
        size = len(self.heap_array) - 1
        while size > 0 and self.heap_array[size] < self.heap_array[self.parent(size)]:
            self.swap()
            size = self.parent(size)

    def swap(self):
        self.heap_array[self.size], self.heap_array[self.parent(
            self.size)] = self.heap_array[self.parent(self.size)], self.heap_array[self.size]

    def parent(self, index):
        return (index - 1) // 2

    def left_child(self, index):
        return (2 * index) + 1

    def right_child(self, index):
        return (2 * index) + 2

    def delete(self):
        pass

    def min_heap_order(self, index):
        left = self.left_child(index)
        right = self.right_child(index)
        smallest = index
        if left < len(self.heap_array) and self.heap_array[left] < self.heap_array[index]:
            smallest = left
        if right < len(self.heap_array) and self.heap_array[right] < self.heap_array[smallest]:
            smallest = right
        if smallest != index:
            self.heap_array[index], self.heap_array[smallest] = self.heap_array[smallest], self.heap_array[index]
            self.min_heap_order(smallest)

    def min_data(self):
        if len(self.heap_array) == 0:
            print("Heap is Empty!!")
        return self.heap_array[0]

    def min(self):
        if len(self.heap_array) == 0:
            print("Heap is Empty!!")
        min_val = self.heap_array[0]
        last_val = self.heap_array.pop()
        if len(self.heap_array) > 0:
            self.heap_array[0] = last_val
            self.min_heap_order(0)
        return min_val

    def display(self):
        print(self.heap_array)
