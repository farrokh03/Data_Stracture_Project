from linked_list import linked_list

class queue:
    def enqueue(self,data):
        linked_list.insert_at_end(data)

    def dequeue(self):
        linked_list.remove_node_at_begin()      