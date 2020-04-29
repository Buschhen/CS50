from sys import argv , exit
from csv import reader, DictReader

#check if command is used correctly
if len(argv) < 3:
    print("Usage: python dna.py data.csv sequence.txt")

#get dna file ready to be used
dna = open(argv[2], "r")
dnafile = dna.read()
#make array with all dnasequences
with open(argv[1], newline='') as file:
    dnaseq = reader(file)
    row1 = next(dnaseq)
    row1.pop(0)
#make a dictionary to store the counts
sequences = {}

#init dictionary
for item in row1:
    sequences[item] = 0

#for every sequence in dictionary search the dnafile
for STR in sequences:
    l = len(STR)
    #init vars at 1 because the loop starts with the second time the sequence matches
    tempMax = 1
    temp = 1
    for i in range(len(dnafile)):
        temp = 1
        #check dnafile with index with lenght of sequence if it fits the sequence
        if dnafile[i:i+l] == STR:
            while dnafile[i - l:i] == dnafile[i:i + l]:
                temp += 1
                i += l
        #if temp is larger than tempMax then save temp in tempMax
        if temp > tempMax:
            tempMax = temp
    # save the the max repetition in the dictionary
    sequences[STR] = tempMax

#open database file to check how is the person we are looking for
with open(argv[1], newline="") as database:
    data = DictReader(database)
    for person in data:
        match = 0
        for dna in sequences:
            #compare if the number of repetiton in the sequences matches
            if sequences[dna] == int(person[dna]):
                match += 1
        #Person with were all sequences match is the searched person
        if match == len(sequences):
            print(person['name'])
            exit()
    #if nobody matches the sequences
    print("No match")
