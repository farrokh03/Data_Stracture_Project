class general_tree:
    def __init__(self, data):
        self.data = data
        self.child = None
        self.sibling = None 

    def insert(self, parent, value):
        new_node = general_tree(value)
        if parent.child is None:
            parent.child = new_node
        else:
            current = parent.child
            while current.sibling:
                current = current.sibling
            current.sibling = new_node

    def remove(self, value):
        if self.child is None:
            return

        if self.child.data == value:
            self.child = self.child.sibling
            return

        current = self.child
        while current.sibling and current.sibling.data != value:
            current = current.sibling

        if current.sibling:
            current.sibling = current.sibling.sibling