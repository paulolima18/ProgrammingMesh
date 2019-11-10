import pygame
import random

#Vars
height = 600
width = 1000
fps = 60
lenght = 60
colors={'red':(128,0,0),'black':(0,0,0),'white':(255,255,255),'green':(0,155,0),'blue':(0,0,155),'yellow':(255,170,0),'darkblue':(51,102,204),'darkgreen':(51,102,0),
'violet':(102,0,102),'brown':(77,38,0),'pink':(255,204,255)}

pygame.init()
gdisplay = pygame.display.set_mode((width,height))
pygame.display.update()
gdisplay.fill(colors['black'])
pygame.display.update()
clock = pygame.time.Clock()
font = pygame.font.SysFont('Impact',50)
smallfont = pygame.font.SysFont('Impact',30)

def block(y):
    pygame.draw.rect(gdisplay,colors['white'],[lenght,y,10,lenght])

def bot(y):
    pygame.draw.rect(gdisplay,colors['white'],[width-lenght,y,10,lenght])

def ball(x,y):
    #get ball(circle)
    pygame.draw.rect(gdisplay,colors['white'],[x,y,lenght/3,lenght/3])

def text_objects(text,color,size):
    text_surface = size.render(text,True,color)
    return text_surface, text_surface.get_rect()

def msm(msg,color,change):
    text1,text2 = text_objects(msg,color,font)
    text2.center = width/2 , height/2+change
    gdisplay.blit(text1,text2)
    clock.tick(5)

def score(goal,x,y):
    text = smallfont.render(str(goal), True, colors['white'])
    gdisplay.blit(text,(x,y))

def wall(x,y,sx,sy):
    pygame.draw.rect(gdisplay,colors['black'],[x,y,sx,sy])

def introg():

    gdisplay.fill(colors['black'])
    msm('(3)',colors['white'],0)
    pygame.display.update()
    intro = True
    val = 0
    while intro:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_3:
                    val = 3
                    return val

def gameloop(n):
    exitg = False
    overg = False
    y_lead, boty_lead = height/2 , height/2
    ychange ,botychange = 0 , -5
    x = width/2
    xchange = -5
    yball = height/2
    yballchange = -5
    goal1,goal2 = 0,0

    while not exitg:
        while overg:
            gdisplay.fill(colors['black'])
            msm('Replay (R)',colors['white'],0)
            pygame.display.update()
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    quit()
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_q:
                        exitg = True
                        overg = False
                    if event.key == pygame.K_r:
                        gameloop(introg())

            #if event.key == pygame.K_RIGHT:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                extig = True
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_s:
                    ychange = 5
                if event.key == pygame.K_w:
                    ychange = -5
                if event.key == pygame.K_UP:
                    botychange = -5
                if event.key == pygame.K_DOWN:
                    botychange = 5
                if event.key == pygame.K_q:
                    exitg = True
        if y_lead == lenght:
            ychange = 5
        if y_lead == height-2*lenght:
            ychange = -5

        if x>width:
            goal1 = goal1+1
            x , yball = width/2,height/2
            if goal1 == n:
                overg = True
        if x<0:
            goal2 = goal2+1
            x , yball = width/2,height/2
            if goal2 == n:
                overg = True

        if boty_lead == lenght:
            botychange = 5
        if boty_lead == height-2*lenght:
            botychange = -5

        if lenght+10 >= x and lenght <= x+lenght/3:
            if yball+lenght/3 >= y_lead and yball <= y_lead+lenght:
                xchange = 5
        if width-lenght-10 <= x and width-lenght >= x-lenght/3:
            if yball+lenght/3 >= boty_lead and yball <= boty_lead+lenght:
                xchange = -5

        if yball == lenght:
            yballchange = 5
        if yball+lenght/3 == height-lenght:
            yballchange = -5

        y_lead = y_lead + ychange
        boty_lead = boty_lead + botychange
        x = x + xchange
        yball = yball + yballchange

        gdisplay.fill(colors['black'])
        wall(0,0,width,lenght)
        wall(0,height-lenght,width,height-2*lenght)
        score(goal1,width/2-lenght,10)
        score(goal2,width/2+lenght,10)
        score('|',width/2,10)
        block(y_lead)
        bot(boty_lead)
        ball(x,yball)
        pygame.display.update()
        clock.tick(fps)

    pygame.quit()
    quit()
gameloop(introg())
