from pty import fork
from wsgiref.handlers import format_date_time
from pyautogui import *
from time import sleep
import sys
import webbrowser as wb

#contact 
listcontacts = ["Fabian","Edulovers antidinamicos"]
message = "xupala gente"

def click_search_name(name):
    x1, y1 = [243,212]

    moveTo(x1, y1)
    click()
    typewrite(name, interval=0.2)
    sleep(2)
    press('enter')

def click_send_message(msg): 
    x3, y3 = [768,983] 
    moveTo(x3, y3) 
    click() 
    sleep(2) 
    typewrite(msg) 
    press('enter')

for name in listcontacts:
    try:
        click_search_name(name)
    except:
        print("Unable to locate search bar or name")

    try:
        click_send_message(message)
    except:
        print("Unable to locate message bar")