import re


# Token definitions
integer = re.compile('\A[0-9]+\Z')
boolean = re.compile('true|false')
float = re.compile('\A[0-9]*[.]?[0-9]*\Z')
identifier = re.compile('[a-zA-Z][a-zA-Z0-9]*')
UnaryOpers = re.compile('\A[-!]')
EqualOpers = re.compile('\S*(==|!=)\S*')
AddOpers = re.compile('\S*[+-]\S*')
RelationOpers = re.compile('\S*(<|<=|>|>=)\S*')
MultOpers = re.compile('\S*[*/%]\S*')
AndOper = re.compile('\S*&&\S*')
OrOper = re.compile('\S*(\|\|)\S*')
Comma = re.compile('\S*,\S*')
Vartype = re.compile('\A(int|bool|float|char)\Z')
OpenParen = re.compile('\S*[(]\S*')
CloseParen = re.compile('\S*[)]\S*')
OpenCurly = re.compile('\S*{\S*')
CloseCurly = re.compile('\S*}\S*')
OpenSquare = re.compile('\S*\[\S*')
CloseSquare = re.compile('\S*]\S*')
IfStatement = re.compile('\Aif\Z')
ElseStatement = re.compile('\Aelse\Z')
Main = re.compile('\Amain\Z')
WhileStatement = re.compile('\Awhile\Z')
Assignment = re.compile('\S*=\S*')
Semicolon = re.compile('\S*;\S*')


# Split lexeme into pieces to isolate a particular token
def SplitLexeme(tokens,lexeme, symbol):
    terms = lexeme.split(symbol)
    count = len(terms)
    newTerms = []
    newTerms.append(terms[0])
    for i in range(1,count):
        newTerms.append(symbol)
        newTerms.append(terms[i])
    for eachTerm in newTerms:
        CompareLexeme(tokens,eachTerm)  # compare new list of lexemes for matches, continuing the cycle of breaking them down as needed

# compare the passed lexeme to the tokens to find a match
# call split function if needed or add to list if it matches the token perfectly
def CompareLexeme(tokenList,lexeme):
    lexeme = re.sub('\t', '', lexeme)
    inserted = False
    if lexeme == "":
        return
    elif Vartype.match(lexeme):
        tokenList.append("VARTYPE")
    elif OrOper.match(lexeme):
        if lexeme == "||":
            tokenList.append("OR")
        else:
            inserted = True
            SplitLexeme(tokenList,lexeme,"||")
    elif AndOper.match(lexeme):
        if lexeme == "&&":
            tokenList.append("AND")
        else:
            inserted = True
            SplitLexeme(tokenList,lexeme, "&&")
    elif Comma.match(lexeme):
        if lexeme == ",":
            tokenList.append("COMMA")
        else:
            inserted = True
            SplitLexeme(tokenList,lexeme, ",")
    elif Semicolon.match(lexeme):
        if lexeme == ";":
            tokenList.append("SEMICOLON")
        else:
            inserted = True
            SplitLexeme(tokenList,lexeme, ";")
    elif OpenParen.match(lexeme):
        if lexeme == "(":
            tokenList.append("OPENPAREN")
        else:
            inserted = True
            SplitLexeme(tokenList,lexeme, "(")
    elif OpenCurly.match(lexeme):
        if lexeme == "{":
            tokenList.append("OPENCURLYBR")
        else:
            inserted = True
            SplitLexeme(tokenList,lexeme, "{")
    elif OpenSquare.match(lexeme):
        if lexeme == "[":
            tokenList.append("OPENSQUAREBR")
        else:
            inserted = True
            SplitLexeme(tokenList,lexeme, "[")
    elif CloseParen.match(lexeme):
        if lexeme == ")":
            tokenList.append("CLOSEPAREN")
        else:
            inserted = True
            SplitLexeme(tokenList,lexeme, ")")
    elif CloseCurly.match(lexeme):
        if lexeme == "}":
            tokenList.append("CLOSECURLYBR")
        else:
            inserted = True
            SplitLexeme(tokenList,lexeme, "}")
    elif CloseSquare.match(lexeme):
        if lexeme == "]":
            tokenList.append("CLOSESQUAREBR")
        else:
            inserted = True
            SplitLexeme(tokenList,lexeme, "]")
    elif IfStatement.match(lexeme):
        tokenList.append("IF")
    elif EqualOpers.match(lexeme):
        if lexeme == "==" or lexeme == "!=":
            tokenList.append("EQUAL_OPERS")
        else:
            inserted = True
            if lexeme.__contains__("!="):
                SplitLexeme(tokenList, lexeme, "!=")
            elif lexeme.__contains__("=="):
                SplitLexeme(tokenList, lexeme, "==")
    elif UnaryOpers.match(lexeme) and not (tokenList[-1] == "]" or identifier.match(tokenList[-1])):
        tokenList.append("UNARY_OPERS")
        tokenList.append(lexeme[0])
        lexeme = lexeme[1:]
        if identifier.match(lexeme):
            tokenList.append("IDENTIFIER")
        elif integer.match(lexeme):
            tokenList.append("INTEGER")
        elif boolean.match(lexeme):
            tokenList.append("BOOLEAN")
        elif float.match(lexeme):
            tokenList.append("FLOAT")
    elif AddOpers.match(lexeme):
        if lexeme == "+" or lexeme == "-":
            tokenList.append("ADD_OPERS")
        else:
            inserted = True
            if lexeme.__contains__("+"):
                SplitLexeme(tokenList,lexeme, "+")
            elif lexeme.__contains__("-"):
                SplitLexeme(tokenList,lexeme, "-")
    elif MultOpers.match(lexeme):
        if lexeme == "*" or lexeme == "/" or lexeme == "%":
            tokenList.append("MULT_OPERS")
        else:
            inserted = True
            if lexeme.__contains__("*"):
                SplitLexeme(tokenList,lexeme, "*")
            elif lexeme.__contains__("/"):
                SplitLexeme(tokenList,lexeme, "/")
            elif lexeme.__contains__("%"):
                SplitLexeme(tokenList,lexeme, "%")
    elif RelationOpers.match(lexeme):
        if lexeme == "<" or lexeme == ">" or lexeme == "<=" or lexeme == ">=":
            tokenList.append("RELATION_OPERS")
        else:
            inserted = True
            if lexeme.__contains__("<="):
                SplitLexeme(tokenList,lexeme, "<=")
            elif lexeme.__contains__(">="):
                SplitLexeme(tokenList,lexeme, ">=")
            elif lexeme.__contains__("<"):
                SplitLexeme(tokenList,lexeme, "<")
            elif lexeme.__contains__(">"):
                SplitLexeme(tokenList,lexeme, ">")
    elif ElseStatement.match(lexeme):
        tokenList.append("ELSE")
    elif Assignment.match(lexeme):
        if lexeme == "=":
            tokenList.append("ASSIGNMENT")
        else:
            inserted = True
            SplitLexeme(tokenList,lexeme, "=")
    elif WhileStatement.match(lexeme):
        tokenList.append("WHILELOOP")
    elif Main.match(lexeme):
        tokenList.append("MAIN")
    elif integer.match(lexeme):
        tokenList.append("INTEGER")
    elif boolean.match(lexeme):
        tokenList.append("BOOLEAN")
    elif float.match(lexeme):
        tokenList.append("FLOAT")
    elif identifier.match(lexeme):
        tokenList.append("IDENTIFIER")
    else:
        tokenList.append("!!ERROR: UNKNOWN!!")      # error token to handle input that is not recognizable in clite
    if inserted is False:
        tokenList.append(lexeme)