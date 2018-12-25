#!/usr/bin/env python3

import re

def convertToMeter(feet):
    meters = feet * 3.28084
    
    print(feet, " feet is ", meters, " meters")

def extractNumber(feetString):
    feet = ''
    i = 0
    
    while(str.isdigit(feetString[i])):
        feet += feetString[i]
        i += 1

    convertToMeter(int(feet))

def findFeet(sentence):
    ftRegex = re.compile('[0-9]+ ft')
    feetRegex = re.compile('[0-9]+ feet')
    
    ftMatch = ftRegex.search(sentence)
    feetMatch = feetRegex.search(sentence)
    
    if (ftMatch == None and feetMatch == None):
        return
    
    elif (ftMatch != None):
        extractNumber(ftMatch.group())
    
    else: #means feetMatch !=None
        extractNumber(feetMatch.group())

print('Hello this program converts any instance of # feet to # meters in a sentence')
print('Enter a sentence: ')
sentence = input() 

findFeet(sentence)
