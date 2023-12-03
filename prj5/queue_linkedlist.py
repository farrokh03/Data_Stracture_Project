import linkedlist


class Queue:
    queue = linkedlist.LinkedList()

    def enqueue(self, data):
        self.queue.insert_at_end(data)

    def dequeue(self):
        return self.queue.remove_head()

    def front(self):
        return self.queue.head.data

    def size(self):
        return self.queue.list_size()

    def display(self):
        self.queue.display()
