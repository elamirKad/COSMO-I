from plan_rec import plan_recognize as pr
from plan_rec import plan_loadimg as li
import pygame
planet = ""
planets = []
pygame.mixer.init()
pygame.mixer.music.load("audio/hello.mp3")
pygame.mixer.music.play()

def sayplanet(planet):
    if (planet == "mars"):
            pygame.mixer.music.load("audio/mars.mp3")
            pygame.mixer.music.play()
    elif (planet == "earth"):
            pygame.mixer.music.load("audio/earth.mp3")
            pygame.mixer.music.play()
    elif (planet == "sun"):
            pygame.mixer.music.load("audio/sun.mp3")
            pygame.mixer.music.play()
    elif (planet == "scan"):
            pygame.mixer.music.load("audio/scan.mp3")
            pygame.mixer.music.play()

while (True):
    inp = input("Planet Scan - ps, Voice Control - vc, Claviature Control - cc Load Image - li: ")
    if(inp == "ps"):
        sayplanet("scan")
        planet = pr()
        print(planet)
        sayplanet(planet)
        
    elif(inp == "li"):
        inp = input("Enter: ")
        sayplanet("scan")
        planet = li(inp)
        print(planet)
        sayplanet(planet)
    
