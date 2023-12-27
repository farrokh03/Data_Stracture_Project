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

    def remove(self, data):
        root = self
        child = root.children

        try:
            while child.data != data:
                child = child.next
        except:
            raise NotImplementedError

        if child.children.data != None:
            child.data = child.children.data
            child.children = child.children.next

        elif child.next == None:
            child.previous.next = None

        else:
            sibling = child.next
            root.children = sibling
