import re

def lexer(inputStr):
    tokens = []
    while inputStr:
        keyword = re.match(r'int|if|else|while', inputStr)
        if keyword:
            tokens.append(('Keyword', keyword.group()))
            inputStr = inputStr[len(keyword.group()):]

        op = re.match(r'[=+>*]', inputStr)
        if op:
            tokens.append(('Operator', op.group()))
            inputStr = inputStr[len(op.group()):]

        Id = re.match(r'[_a-zA-Z][_a-zA-Z0-9]*', inputStr)
        if Id:
            tokens.append(('Identifier', Id.group()))
            inputStr = inputStr[len(Id.group()):]

        literal = re.match(r'[0-9]+', inputStr)
        if literal:
            tokens.append(('Literal', literal.group()))
            inputStr = inputStr[len(literal.group()):]

        separators = re.match(r'[;():""]', inputStr)
        if separators:
            tokens.append(('Separators', separators.group()))
            inputStr = inputStr[len(separators.group()):]

        inputStr = inputStr.lstrip()

    return tokens

def testLexer():
    sample = [
        "int A1=5",
        "if(x>0)",
        "while(x>=10)",
        ]

    for line in sample:
        tokenList = lexer(line)
        cout = ', '.join([f"<{token[0]}, {token[1]}>" for token in tokenList])
        print(f"Test input string: {line}")
        print(f"Output <type, token> list: [{cout}]\n")

if __name__ == '__main__':
    testLexer()
