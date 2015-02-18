class MinStack:
	def __init__(self):
		self.A = []
		self.minS = []
	# @param x, an integer
	# @return an integer
	#
	def push(self, x):
		n = len(self.A)
		if n==0:
			self.minS.append(x);
		else:
			lastmin = self.minS[-1]
			if x <= lastmin:
				self.minS.append(x)
		self.A.append(x)	
		

	# @return nothing
	def pop(self):
		if self.A.pop() == self.minS[-1]:
			self.minS.pop()
		

	# @return an integer
	def top(self):
		return self.A[-1]
		

	# @return an integer
	def getMin(self):
		return self.minS[-1]


a = MinStack()
a.push(1)
a.push(2)
print(a.top())






		