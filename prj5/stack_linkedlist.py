import linkedlist


class StackReplica:
    stack = linkedlist.LinkedList()

    def push(self, data):
        self.stack.insert_at_end(data)

    def display(self):
        self.stack.display()

    def pop(self):
        return self.stack.remove_end()

    # Above methods done
    def peek(self):
        pass
