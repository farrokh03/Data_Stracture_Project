from linked_list import linked_list


class array_with_linked_list:

    def append_to_list(self,data):
        linked_list.insert_at_end(data)

    def insert_to_list(self,data,index):
        linked_list.insert_at_index(data,index)

    def del_from_list(self,index):
        linked_list.remove_data_at_index(index)

    def reverse_list(self):
        linked_list.invert()

    def len_list(self):
        linked_list.size_of_linked_list()
        