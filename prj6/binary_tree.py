class Node:
    def __init__(self, data=None):
        self.data = data
        self.right = None
        self.left = None

    def insert(self, data):
        if self.data:
            if self.data < data:
                if self.right == None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
            elif self.data > data:
                if self.left == None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            else:
                self.data = data
        else:
            print("Root Data has not been inserted")

    def sum_values(self, node):
        if node == None:
            return 0
        return node.data + self.sum_values(node.left) + self.sum_values(node.right)

    def in_order_display(self):
        if self.left:
            self.left.in_order_display()
        print(self.data)
        if self.right:
            self.right.in_order_display()

    def search(self, data, node):
        if node == None:
            return None
        elif data == node.data:
            return node.data
        elif data < node.data:
            return self.search(data, node.left)
        elif data > node.data:
            return self.search(data, node.right)
        else:
            return None

    def pre_order_display(self):
        print(self.data)
        if self.left:
            self.left.pre_order_display()
        if self.right:
            self.right.pre_order_display()

    def post_order_display(self):
        if self.left:
            self.left.post_order_display()
        if self.right:
            self.right.post_order_display()
        print(self.data)

    def delete(self, data):
        if self.data:
            if self.data > data:
                self.left.delete(data)
            elif self.data < data:
                self.right.delete(data)
            else:
                if self.right:
                    pass
        else:
            return self


root = Node(10)


root.insert(4)
root.insert(24)

root.insert(55)
root.insert(1)

root.insert(99)


root.delete(1)
root.in_order_display()
