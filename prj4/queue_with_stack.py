class queue_with_stack:
    def __init__(self,size):
        self.primary = [None for i in range(size)]
        self.secondery = [None for i in range(size)]
        self.indicator = 0
        self.size = size

    def enqueue(self,value):
         if (self.indicator == self.size - 1):
            return 0
         else :
            self.indicator += 1
            self.primary[self.indicator] = value
            self.from_primary_to_secondery()
            return self.secondery
        
    def dequeue(self):
        if (self.indicator == -1):
            return 0 
        
        else :
            self.primary[self.indicator] = self.primary[self.indicator + 1]
            self.from_primary_to_secondery()
            value = self.secondary[self.indicator]
            self.secondary[self.indicator] = None
            self.indicator -= 1
            return value
    
    def from_primary_to_secondery(self):
        
        revrse_indicator  = self.indicator
        counter = 0
        while revrse_indicator:
            if(self.primary[revrse_indicator]!= None):
                self.secondery[counter] =  self.primary[revrse_indicator]
                counter +=1
            revrse_indicator-=1