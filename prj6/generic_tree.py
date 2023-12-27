class Node:
    def __init__(self, data=None):
        self.next = None
        self.data = data
        self.previous = None


class Tree(Node):
    def __init__(self, data=10, **kwargs):
        super().__init__(**kwargs)
        self.data = data
        self.children = Node()

    def insert(self, data, root):
        first_child = root.children
        if root.children.data == None:
            new_node = Tree(data)
            root.children = new_node
            root.children.previous = root
        else:
            current = first_child
            while current.next != None:
                current = current.next
            new_node = Tree(data)
            current.next = new_node
            new_node.previous = current

    # def remove(self, data, root):
    #     while root.data != data:
    #         for i in len(root.children):
    #             self.remove(data, self.children[i])

    #     return root.data


sample = Tree(10)

sample.insert(5, sample)
sample.insert(7, sample)
sample.insert(40, sample)
sample.insert(60, sample)

sample.insert(100, sample.children)
sample.insert(200, sample.children)

print(sample.children.)
