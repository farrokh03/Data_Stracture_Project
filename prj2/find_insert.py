class ArrayReplica():
    
    array = list()
    def __init__(self, size):
        self.array = [None] * size
        self.counter

    def insert(self, value ,index):
        self.array[index] = value
        self.counter += 1


    def find(self,item):
        finder_counter = 0
        for i in self.array:
            
            if i == item:
                return finder_counter;
        finder_counter +=1
        return -1