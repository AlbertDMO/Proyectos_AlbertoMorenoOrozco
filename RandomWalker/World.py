'''
Created on Jan 15, 2015

@author: chewy
'''
'''
Created on Jan 15, 2015

@author: chewy
'''

from Walker import Walker
import random, pygame, sys
from pygame.locals import *

class World:

    RED = (255,0,0)
    WHITE = (255, 255, 255)
    BLUE =(0,0,220)
 
    def __init__(self, WINDOWWIDTH, WINDOWHEIGHT, FPS):
        self.WINDOWWIDTH = WINDOWWIDTH
        self.WINDOWHEIGHT = WINDOWHEIGHT
        self.FPS = FPS

    def setup(self):
        self.walker = Walker(self.WINDOWWIDTH, self.WINDOWHEIGHT)

    def draw(self, x, y):
        self.walker.display(self.DISPLAYSURF)
        self.walker.step(x, y)


    def start(self):

        self.setup()

        print "Inicio"
        
        
        global FPSCLOCK, DISPLAYSURF
        pygame.init()
        FPSCLOCK = pygame.time.Clock()
        self.DISPLAYSURF = pygame.display.set_mode((self.WINDOWWIDTH, self.WINDOWHEIGHT))

        x=random.randint(0, self.WINDOWWIDTH)
        y=random.randint(0, self.WINDOWHEIGHT)
        s= 10

        self.DISPLAYSURF.fill(World.WHITE)
        dibujarCuadro(self.DISPLAYSURF, x, y, s, World.RED)
        '''
            x=x
            y=y
            s=s
        '''
        while True:
        
            for event in pygame.event.get(): # event handling loop
                if event.type == QUIT or (event.type == KEYUP and event.key == K_ESCAPE):
                    pygame.quit()
                    sys.exit()
                elif event.type == MOUSEMOTION:
                    mousex, mousey = event.pos
                    print str(mousex)+","+str(mousey)
                elif event.type == MOUSEBUTTONUP:
                    print "CLick"
                    #print "Cuadro en "+str(x)+","+str(y)
                    mousex, mousey = event.pos
                    mouseClicked = True

            #self.DISPLAYSURF.fill(World.WHITE)
            self.draw(x, y)
        
            pygame.display.update()
            FPSCLOCK.tick(self.FPS)


def dibujarCuadro(display, izquierda, arriba, lado, color):
    pygame.draw.rect(display, color, (izquierda, arriba, lado, lado))


