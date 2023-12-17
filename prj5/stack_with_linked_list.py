from linked_list import linked_list

class stack: 
    def push_to_stack(self,data):
        linked_list.insert_at_end(data)


    def pop_the_stack(self):
        linked_list.remove_node_at_end()

    