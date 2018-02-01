import random, pygame, sys
from pygame.locals import *

class Walker:

	DEFAULT_COLOR = (0, 0, 0)
	DEFAULT_SIZE = 10

	def __init__(self, width, high):
		self.x = width/2
		self.y = high/2
		self.r = Walker.DEFAULT_SIZE
		self.color = Walker.DEFAULT_COLOR

	def display(self, display):
		#pygame.draw.circle(display, self.color, (self.x, self.y), self.r)
		pygame.draw.line(display, self.color, (self.x, self.y), (self.x, self.y))

	def step(self, cuadrox, cuadroy):
		
		difX = cuadrox - self.x #diferencia de meta con punto actual en x
		difY = cuadroy - self.y #diferencia de meta con punto actual en y
		
		stepx = random.randint(0,9)
		stepy = random.randint(0,9)
		
		if difX == 0 and difY == 0:
			print "\nEl \"Walker\" encontro la meta\n"
			pygame.quit()
			sys.exit()
		else:
			if difX > 0:
				if stepx > 3:
					stepx = 1
				elif stepx < 2:
					stepx = -1
				else:
					stepx = 0
			elif difX < 0:
				if stepx > 3:
					stepx = -1
				elif stepx < 2:
					stepx = 1
				else:
					stepx = 0
			else:
				stepx = random.randint(0,2)-1

			if difY > 0:
				if stepy > 3:
					stepy = 1
				elif stepy < 2:
					stepy = -1
				else:
					stepy = 0
			elif difY < 0:
				if stepy > 3:
					stepy = -1
				elif stepy < 2:
					stepy = 1
				else:
					stepy = 0
			else:
				stepx = random.randint(0,2)-1
			
			self.x = self.x + stepx
			self.y = self.y + stepy
		
		"""
		stepx = random.randint(0,2)-1
		stepy = random.randint(0,2)-1
		
		self.x = self.x + stepx
		self.y = self.y + stepy
		"""

		'''
		choice = random.randint(0, 4)

		if choice == 3s:
			self.y=self.y-1
		elif choice == 0:
			self.x=self.x+1
		elif choice == 2:
			self.y=self.y+1
		else:
			self.x=self.x-1
		'''
		

