'''
Created on Jan 15, 2015

@author: chewy
'''
'''
Created on Jan 15, 2015

@author: chewy
'''

from World import World

WINDOWWIDTH = 800
WINDOWHEIGHT = 600
FPS = 20


def main():
    world = World(WINDOWWIDTH, WINDOWHEIGHT, FPS)

    world.start()



if __name__ == '__main__':
    main()
