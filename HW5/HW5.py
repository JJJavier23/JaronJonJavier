from tkinter import *
import tkinter.messagebox
import re

def find_tokens(line):
    #having the patterns identified to go thru
    token_patterns = [
        (r'\bif\b', 'KEYWORD'),
        (r'\belse\b', 'KEYWORD'),
        (r'\bwhile\b', 'KEYWORD'),
        (r'\b\d+\b', 'LITERAL'),
        (r'\b[a-zA-Z_]\w*\b', 'ID'),
        (r'\+', 'OPERATOR'),
        (r'\-', 'OPERATOR'),
        (r'\*', 'OPERATOR'),
        (r'\/', 'OPERATOR'),
        (r'\(', 'SEPARATOR'),
        (r'\)', 'SEPARATOR'),
        (r'\{', 'SEPARATOR'),
        (r'\}', 'SEPARATOR'),
        (r'\;', 'SEPARATOR'),
        (r'\:', 'SEPARATOR'),
        (r'\=', 'OPERATOR'),
        (r'\s+', 'WHITESPACE'),
        (r'.', 'UNKNOWN')
    ]

    #while loop to identify tokens within a line
    tokens = []
    while line:
        matched = False
        for pattern, token_type in token_patterns:
            match = re.match(pattern, line)
            if match:
                token = match.group()
                tokens.append((token_type, token))
                line = line[len(token):].lstrip()
                matched = True
                break
        if not matched:
            raise ValueError("Unable to tokenize line: " + line)
    
    return tokens

class GUI:
    
    def __init__(self, root):
        # GUI title
        self.master = root
        self.master.title("Lexical Analyzer for TinyPie")
        self.master.geometry('1000x300')

        # Line Counter
        self.lines = []
        self.currentLine = 0

        # Source Code Input Label
        self.scLabel = Label(self.master, text="Source Code Input")
        self.scLabel.grid(row=0, column=0, sticky=E)

        # Source Textbox
        self.scText = Text(self.master, height=10, width=50)
        self.scText.grid(row=1, column=0, sticky=E)

        # Blank Space
        self.blank1 = Label(self.master, text="             ")
        self.blank1.grid(row=0, column=2, sticky=E)

        # Result Label
        self.scLabel = Label(self.master, text="Result")
        self.scLabel.grid(row=0, column=3, sticky=E)

        # Output Textbox
        self.outText = Text(self.master, height=10, width=50)
        self.outText.grid(row=1, column=3, sticky=E)

        # Blank Space
        self.blank2 = Label(self.master, text="   ")
        self.blank2.grid(row=3, column=0, sticky=E)

        # Next Line Button
        self.nlButton = Button(self.master, text="Next Line", command=self.lexer)
        self.nlButton.grid(row=4, column=0, sticky=E)

        # Quit Button
        self.quitButton = Button(self.master, text="Quit")
        self.quitButton.grid(row=4, column=3, sticky=E)

        # Line Number
        self.numDisplay = Label(self.master, text="Current Processing Line: "+ str(self.currentLine))
        self.numDisplay.grid(row=3, column=0, sticky=E)

    def lexer(self):
        current = self.scText.get("{}.0".format(self.currentLine+1), "{}.end".format(self.currentLine+1))
        self.lines.append(current)
        # Call the token finding function here to get <type, token> pairs for the current line
        tokens = find_tokens(current)
        processed = "Processed Line {}: {}".format(self.currentLine + 1, current.strip())
        self.outText.insert(END, processed + "\n")
        
        # Display the <type, token> pairs in the right-side text box
        for token in tokens:
            self.outText.insert(END, f"<{token[0]}, {token[1]}>")
        self.outText.insert(END, "\n")
        
        self.outText.see(END)
        self.currentLine += 1
        self.numDisplay.config(text="Line Number: {}".format(self.currentLine))

        if int(self.currentLine) > len(self.lines):
            tkinter.messagebox.showinfo("Lexer Done")
            self.nlButton.config(state=DISABLED)

if __name__ == '__main__':
    myTkRoot = Tk()
    my_gui = GUI(myTkRoot)
    myTkRoot.mainloop()
