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

    def delete(self, root, data):
        if root is None:
            return root
        else:

            if root.data > data:
                root.left = self.delete(root.left, data)
                return root
            elif root.data < data:
                root.right = self.delete(root.right, data)
                return root

            if root.left is None:
                temp = root.right
                del root
                return temp

            elif root.right is None:
                temp = root.left
                del root
                return temp

            else:
                parent = root

                successor = root.right
                while successor.left:
                    parent = successor
                    successor = successor.left

                if parent != root:
                    parent.left = successor.right
                else:
                    parent.right = successor.right

                root.data = successor.data

                del successor
                return root
