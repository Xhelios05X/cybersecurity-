#!/usr/bin/env python3
#This Python script allows bruteforcing Caesar Cipher
#Author: github/iamzielus

import sys

#Command execution: python3 filename charTable startPoint endPoint encodedString
#Note that starting point should be the code of the first char in range, not the one before
#Remember to use backslash before special characters
#For default ASCII table use "0" as an option

charTable = []
#Assign character table
if sys.argv[1] != "0":
    for x in sys.argv[1]:
       charTable.append(x)
else:
    charTable = [chr(n) for n in range(128)]

startPoint = int(sys.argv[2])
endPoint = int(sys.argv[3])
encodedString = sys.argv[4]

#Looping through shifts
for i in range(endPoint-startPoint):
    decodedString = str(i)+": "
    for letter in encodedString:
        if letter in charTable:
            #This "if" statement keeps decoded characters in range
            if charTable.index(letter) + i > endPoint :
                decodedString += charTable[startPoint+(charTable.index(letter)+i-endPoint)]
            else:
                decodedString += charTable[charTable.index(letter)+i]
    #Print decoded string
    print(decodedString)
