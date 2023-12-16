from tkinter import *
import re

class myGUI:
    def __init__(self, root):
        self.currentline = 0
        self.master = root
        self.master.title("A Very Pristine Lexical Analyzer")
        self.label = Label(self.master, text="Source Code Input:")
        self.label.grid(row=0, column=0, sticky=W)
        
        self.textin = Text(self.master, bd=4)
        self.textin.grid(row=1, column=0, sticky=W)
        self.label = Label(self.master, text="Lexical analyzed result:")
        self.label.grid(row=0, column=1, sticky=W)
    
        self.textout = Text(self.master, bd=4)
        self.textout.grid(row=1, column=1, sticky=W)

        self.textparse = Text(self.master, bd=4)
        self.textparse.grid(row=1, column=2, sticky=W)
        self.label = Label(self.master, text="Parse Tree:")
        self.label.grid(row=0, column=2, sticky=W)
        
        self.label = Label(self.master, text="Current line:")
        self.label.grid(row=2, column=0, sticky=W)
        
        self.button = Button(self.master, text="Next Line", command=self.next_line)
        self.button.grid(row=3, column=0, sticky=W)
        
        self.quitbutton = Button(self.master, text = "Quit", command = self.quit)
        self.quitbutton.grid(row=3, column = 3,sticky = W)

    def next_line(self):
        self.currentline += 1
        
        # Makes it so you can't use nextline if there is no text on the next line
        if self.textin.get(f"{self.currentline}.0") == "":
            self.currentline -= 1
            return
        
        line = self.textin.get(f"{self.currentline}.0", f"{self.currentline}.end")
        print(line)
        lexed_line = self.lex_line(line)
        self.parser()
        print(lexed_line)
        self.textout.insert(f"{self.currentline}.0", lexed_line + "\n")
        self.currentlinelabel = Label(self.master, text = self.currentline)
        self.currentlinelabel.grid(row = 2, column =1, sticky = W)
    
    def lex_line(self, line): #lex_line returns output, a list of tokens stored as string tuples

        global output
        output = [] #After lex_line is done running, output will have a list of tokens stored as tuples of strings. One token tuple will have the format of
                        #token[0] == "<token_type, "
                        #token[1] == "token"
                        #token[2] == ">"

                        #token[1] could be "+" or "int" or whatever, it holds a character or word from the source code

        while line:

            line = line.lstrip()

            kw = re.match(r'if|else|int|float', line)
            if kw != None:
                output.append(("<KW, ", kw.group(), ">"))
                line = line[len(kw.group()):]
        
            operator = re.match(r'[=+>*]', line)
            if operator != None:
                output.append(("<OP, ", operator.group(), ">"))
                line = line[len(operator.group()):]
                
            id = re.match(r'[A-z]+\d*', line)
            if id != None:
                output.append(("<ID, ", id.group(), ">"))
                line = line[len(id.group()):]
                
            float_lit = re.match(r'\d+\.\d+', line)
            if float_lit != None:
                output.append(("<FLOAT_L, ", float_lit.group(), ">"))
                line = line[len(float_lit.group()):]
                
            int_lit = re.match(r'\d+', line)
            if int_lit != None:
                output.append(("<INT_L, ", int_lit.group(), ">"))
                line = line[len(int_lit.group()):]
            
            string_lit = re.match(r'[A-z]+', line)
            if string_lit != None:
                output.append(("<STRING_L, ", string_lit.group(), ">"))
                line = line[len(string_lit.group()):]
            
            sep = re.match(r'[():";]', line)
            if sep != None:
                output.append(("<SEP, ", sep.group(), ">"))
                line = line[len(sep.group()):]
            
            

        stringout = ""
        for x in output:
            stringout += x[0] + x[1] + x[2] + " " 
        return stringout



    def accept_token(self): #I changed accept_token to take the next token from the lexer's output list
        global inToken
        print(" accept token from the list:"+inToken[1])
        inToken= output.pop(0) #this used something called "Mytokens", i think the equivalent is "output" in my code

    def multi(self):
        self.textparse.insert("end","\n----parent node exp, finding children nodes:")
        global inToken;
        if(inToken[0]=="<FLOAT_L, "):
            self.textparse.insert("end","child node (internal): float")
            self.textparse.insert("end"," float has child node (token):"+inToken[1])
            self.accept_token()
        elif(inToken[0]=="<INT_L, "):
            self.textparse.insert("end","child node (internal): int")
            self.textparse.insert("end"," int has child node (token):"+inToken[1])
            self.accept_token()
            if(inToken[1]=="*"):
                self.textparse.insert("end","child node (token):"+inToken[1])
                self.accept_token()
                self.textparse.insert("end","child node (internal): math")
            else:
                self.textparse.insert("end","error, you need + after the int in the math")
            self.multi()

    def math(self):
        global inToken
        self.multi()
        if(inToken[1]=="+"):
            self.accept_token()
        elif(inToken[1]=="("):
            self.accept_token()
        elif(inToken[1]==")"):
            self.accept_token()

    def comparison_exp(self):
        global inToken

        if(inToken[1]=="*"):
            self.multi()
        elif(inToken[1]=="+"):
            self.math()

    def if_exp(self):
        print("\n----parent node exp, finding children nodes:")
        global inToken;
        typeT = inToken[0]
        token = inToken[1]
        
        if(typeT=="<ID, "):
            print("child node (internal): identifier")
            print(" identifier has child node (token):"+token)
            self.accept_token()
        elif(typeT=="<KW, "):
            print("child node (internal): keyword")
            print(" keyword has child node (token):"+token)
            self.accept_token()
        elif(inToken[1]=="="):
            print("child node (token):"+inToken[1])
            self.accept_token()
        elif(inToken[1]=="if"):
            print("child node (internal): identifier")
            print(" identifier has child node (token):"+token)
            self.accept_token()
        else:
            print("expect = as the second element of the expression!")
            return
        print("Child node (internal): math")
        self.comparison_exp()

    def parser(self): #Directions say we can hardcode the parser to parse a math_line, then a math_line, then an if_line, then a print_line
        global inToken
        inToken=output.pop(0)
        self.if_exp()
        if(inToken[1]==";"):
            print("\nparse tree building success!")
        return
        
        
    def quit(self):
        root.destroy()

if __name__ == '__main__':
    root = Tk()
    my_gui = myGUI(root)
    root.mainloop()
