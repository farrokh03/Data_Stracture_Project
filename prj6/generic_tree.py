class Tree:
    def __init__(self, data=10):
        self.data = data
        self.children = []
        self.root = None

    def insert(self, data):
        if self:
            self.children.append(Tree(data))
        else:
            if self.root == None:
                self.root = Tree(data)

    def remove(self, data):
        pass
