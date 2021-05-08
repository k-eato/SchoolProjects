import re
import pandas as pd
import Functions as Func

filename = input("Enter input file name: ")             # get file name from user
file = pd.read_csv(filename, sep="\n", header=None)     # read in file line by line
outputFile= open("tokens.txt","w")                      # setup tokens.txt as the list of tokens to be generated
comment = re.compile(r'\t*\S*\t*//', re.ASCII)
tokenList = ["Token:", "Lexeme:"]                       # store the tokens and their respective lexemes here


# split each file line into strings by spacing
for i in range(0, file.size):
    item = file[0][i]
    line = str.split(str(item),sep=" ")
    for j in range(0, len(line)):
        word = str(line[j])
        if comment.match(word):
            Func.CompareLexeme(tokenList,word[:word.index("//")])       # remove comments but keep anything before them
            break
        else:
            Func.CompareLexeme(tokenList,word)                          # process string to see which token it matches


# format output file so tokens appear on left and lexemes form column to the right
for k in range(0,len(tokenList)):
    tokenList[k] = tokenList[k].ljust(18, ' ')
    if k%2 == 0:
        outputFile.writelines(tokenList[k] + "\t")
    else:
        outputFile.writelines(tokenList[k] + "\n")