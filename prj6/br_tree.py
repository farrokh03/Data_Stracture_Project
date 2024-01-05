class RedBlackTreeNode:
    def __init__(self, value, color="Red"):
        self.value = value
        self.color = color
        self.parent = None
        self.left = None
        self.right = None

class RedBlackTree:
    def __init__(self):
        self.root = None

    def insert(self, value):
        new_node = RedBlackTreeNode(value)
        self._insert(new_node)

    def _insert(self, new_node):
        y = None
        x = self.root

        while x is not None:
            y = x
            if new_node.value < x.value:
                x = x.left
            else:
                x = x.right

        new_node.parent = y

        if y is None:
            self.root = new_node
        elif new_node.value < y.value:
            y.left = new_node
        else:
            y.right = new_node

        new_node.left = None
        new_node.right = None
        new_node.color = "Red"
        self._insert_fixup(new_node)

    def _insert_fixup(self, z):
        while z.parent is not None and z.parent.color == "Red":
            if z.parent == z.parent.parent.left:
                y = z.parent.parent.right
                if y is not None and y.color == "Red":
                    z.parent.color = "Black"
                    y.color = "Black"
                    z.parent.parent.color = "Red"
                    z = z.parent.parent
                else:
                    if z == z.parent.right:
                        z = z.parent
                        self._left_rotate(z)

                    z.parent.color = "Black"
                    z.parent.parent.color = "Red"
                    self._right_rotate(z.parent.parent)
            else:
                y = z.parent.parent.left
                if y is not None and y.color == "Red":
                    z.parent.color = "Black"
                    y.color = "Black"
                    z.parent.parent.color = "Red"
                    z = z.parent.parent
                else:
                    if z == z.parent.left:
                        z = z.parent
                        self._right_rotate(z)

                    z.parent.color = "Black"
                    z.parent.parent.color = "Red"
                    self._left_rotate(z.parent.parent)

        self.root.color = "Black"

    def _left_rotate(self, x):
        y = x.right
        x.right = y.left

        if y.left is not None:
            y.left.parent = x

        y.parent = x.parent

        if x.parent is None:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y

        y.left = x
        x.parent = y

    def _right_rotate(self, y):
        x = y.left
        y.left = x.right

        if x.right is not None:
            x.right.parent = y

        x.parent = y.parent

        if y.parent is None:
            self.root = x
        elif y == y.parent.left:
            y.parent.left = x
        else:
            y.parent.right = x

        x.right = y
        y.parent = x

    def remove(self, value):
        node_to_remove = self._find_node(self.root, value)

        if node_to_remove is None:
            return

        self._remove(node_to_remove)

    def _remove(self, node):
        y = node
        y_original_color = y.color
        if node.left is None:
            x = node.right
            self._transplant(node, node.right)
        elif node.right is None:
            x = node.left
            self._transplant(node, node.left)
        else:
            y = self._tree_minimum(node.right)
            y_original_color = y.color
            x = y.right
            if y.parent == node:
                if x is not None:
                    x.parent = y
            else:
                self._transplant(y, y.right)
                y.right = node.right
                y.right.parent = y

            self._transplant(node, y)
            y.left = node.left
            y.left.parent = y
            y.color = node.color

        if y_original_color == "Black":
            self._remove_fixup(x)
    def _transplant(self, u, v):
        if u.parent is None:
            self.root = v
        elif u == u.parent.left:
            u.parent.left = v
        else:
            u.parent.right = v

        if v is not None:
            v.parent = u.parent

    def _remove_fixup(self, x):
        if x is None:
            return
        while x != self.root and (x is None or (x.parent is not None and x.parent.color == "Black")):
            if x == x.parent.left:
                w = x.parent.right
                if w is not None and w.color == "Red":
                    w.color = "Black"
                    x.parent.color = "Red"
                    self._left_rotate(x.parent)
                    w = x.parent.right

                if (w is None or w.left is None or w.left.color == "Black") and (w is None or w.right is None or w.right.color == "Black"):
                    if w is not None:
                        w.color = "Red"
                    x = x.parent
                else:
                    if w is None or w.right is None or w.right.color == "Black":
                        if w.left is not None:
                            w.left.color = "Black"
                        if w is not None:
                            w.color = "Red"
                        self._right_rotate(w)
                        w = x.parent.right

                    if w is not None:
                        w.color = x.parent.color
                    if x.parent is not None:
                        x.parent.color = "Black"
                    if w.right is not None:
                        w.right.color = "Black"
                    self._left_rotate(x.parent)
                    x = self.root

            else:
                w = x.parent.left
                if w is not None and w.color == "Red":
                    w.color = "Black"
                    x.parent.color = "Red"
                    self._right_rotate(x.parent)
                    w = x.parent.left

                if (w is None or w.right is None or w.right.color == "Black") and (w is None or w.left is None or w.left.color == "Black"):
                    if w is not None:
                        w.color = "Red"
                    x = x.parent
                else:
                    if w is None or w.left is None or w.left.color == "Black":
                        if w.right is not None:
                            w.right.color = "Black"
                        if w is not None:
                            w.color = "Red"
                        self._left_rotate(w)
                        w = x.parent.left

                    if w is not None:
                        w.color = x.parent.color
                    if x.parent is not None:
                        x.parent.color = "Black"
                    if w.left is not None:
                        w.left.color = "Black"
                    self._right_rotate(x.parent)
                    x = self.root

        if x is not None:
            x.color = "Black"
    def _tree_minimum(self, node):
        while node.left is not None:
            node = node.left
        return node

    def _find_node(self, node, value):
        if node is None:
            return None

        if node.value == value:
            return node
        left_result = self._find_node(node.left, value)
        right_result = self._find_node(node.right, value)

        return left_result or right_result