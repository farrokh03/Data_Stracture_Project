class CircularQueue():

	def __init__(self, size): 
		self.size = size		
		self.queue = [None for i in range(size)] 
		self.front = self.rear = -1
		self.flag = False

	def enqueue(self, data):				
		if ((self.rear + 1) % self.size == self.front): 
			return None
			
		elif (self.front == -1): 
			self.front = 0
			self.rear = 0
			self.queue[self.rear] = data
		else:
			
			self.rear = (self.rear + 1) % self.size 
			self.queue[self.rear] = data
			
	def dequeue(self):
		if (self.front == -1): 
			return 0
			
		elif (self.front == self.rear): 
			temp=self.queue[self.front]
			self.queue.pop(self.front)
			return temp
		else:
			temp = self.queue[self.front]
			self.queue.pop(self.front)

			return temp

	def queue_peak (self):#checked
		if(self.front == self.rear):
			return 0
		else:
			return self.queue[self.front]
	
	def reverse_queue(self):
		reverse_array = []

		for i in self.queue:
   			 reverse_array.insert(0,i) 
		self.queue = reverse_array
		self.front, self.rear = self.rear, self.front 
		return self.queue
		
	def Is_full(self):
		if (self.size == len(self.queue)):
			self.flag = True
		else:
			self.flag = False

		return self.flag
	
	def Is_empty(self):
		if(self.rear == self.front):
			self.flag = True

		else:
			self.flag = False

		return self.flag