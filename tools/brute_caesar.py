#!/usr/bin/env python3
#This Python script allows bruteforcing Caesar Cipher
#Author: github/iamzielus
#Ask for a string to decode
encodedString = input("What text to decode?")
print("============================")

#Looping through shifts
for i in range(94):
    decodedString = str(i)+": "
    for letter in encodedString:
        #This "if" statement keeps decoded characters in range 32-126
        if ord(letter)+i > 126 :
            decodedString += chr(31+(ord(letter)+i-125))
        else:
            decodedString += chr(ord(letter)+i)
    #Print decoded string
    print(decodedString)
