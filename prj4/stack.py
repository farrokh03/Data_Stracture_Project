class stack:
    def __init__(self,size=5):
        self.size = size
        self.stack = [None for i in range(size)]
        self.indicator = -1
        self.flag = False    

    def stack_push(self,item):
        if (self.indicator == self.size):
            return 0
        
        else:
            self.indicator += 1
            self.stack[self.indicator] = item
            

    def stack_pop(self):
        if (self.indicator == -1):
            return 0 
        else:
            temp = self.stack[self.indicator]
            self.stack[self.indicator] = self.stack[self.indicator+1]
            self.indicator -= 1

            return temp
        
    def Is_empty(self):
        if (self.indicator == 0):
            self.flag = True

        else:
            self.flag = False

        return self.flag 
    
    def Is_full(self):
        if(self.indicator == self.size):
            self.flag = True

        else:
            self.flag = False

        return self.flag
    
    def stack_top(self):
        return self.stack[self.indicator]

    def stack_reverse(self):
        reverse_list = []
        if (self.indicator == 0):
            return 0
        else:
            for i in self.stack:
                reverse_list.insert(0,i)

            self.stack = reverse_list
            return self.stack