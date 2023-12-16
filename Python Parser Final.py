from tkinter import *
from tkinter import ttk
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
        
        self.label2 = Label(self.master, text = "Visualized tree: ")
        self.label2.grid(row = 5, column = 0)
        self.myTree = ttk.Treeview()
        self.myTree.grid(row = 5, column = 1)

        
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
            
            kw = re.match(r'if|else|int|float|print', line)
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

            string_lit = re.match(r'^"[A-z]+"$', line)
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
        print("end"," accept token from the list:"+inToken[1])
        inToken= output.pop(0) #this used something called "Mytokens", i think the equivalent is "output" in my code
    
    def multi(self):
        global inToken;
        if(inToken[0]=="<FLOAT_L, "):
            self.textparse.insert("end","float, " + inToken[1] + "\n")
            self.myTree.insert('op, =','end', text = "float, " + inToken[1])
            
            self.accept_token()
        elif(inToken[0]=="<INT_L, "):
            self.textparse.insert("end","int, " + inToken[1] + "\n")
            self.myTree.insert('op, =','end', text = "int, " + inToken[1])
            
            self.accept_token()
        
        if(inToken[1]=="*"):
            self.textparse.insert("end","op, " + inToken[1] + "\n")
            self.myTree.insert('op, =','end', text = "op, " + inToken[1])
            
            self.accept_token()
            self.multi()
        elif(inToken[1]=="+"):
            self.textparse.insert("end","op, " + inToken[1] + "\n")
            self.myTree.insert('op, =','end',text = "op, " + inToken[1])
            
            self.accept_token()
            self.multi()
        
                
    def math(self):
        global inToken
        self.multi()
        
            
    def print_exp(self):
        global inToken
        self.textparse.insert("end", "--print--" + "\n")
        self.myTree.insert('','end','--print--',text = '--print--')
        
        self.accept_token()
        self.textparse.insert("end", "sep, " + inToken[1] + "\n")
        self.myTree.insert('--print--','end',text = "sep, " + inToken[1])
        self.accept_token() #Removes quote token
        
        self.accept_token()
        self.textparse.insert("end", "STRING_L, " + inToken[1] + "\n")
        self.myTree.insert('--print--','end','string_l', text = "String")
        self.myTree.insert('string_l','end', text = inToken[1])
        
        self.accept_token() #Removes closing quote token
        
        self.accept_token()
        self.textparse.insert("end", "sep, " + inToken[1] + "\n")
        self.myTree.insert('--print--','end',text = "sep, " + inToken[1])
        
        self.accept_token()
        self.textparse.insert("end", "sep, " + inToken[1] + "\n")
        self.myTree.insert('--print--','end',text = "sep, " + inToken[1])
        
        
        
        
    def exp(self):
        
        global inToken;
        typeT = inToken[0]
        token = inToken[1]

        if(typeT=="<KW, "):
            self.textparse.insert("end", "--exp--"+ "\n") #Initial parent, this only occurs once in a line
            self.myTree.insert('', 'end', '--exp--', text = "--exp--")
            
            self.textparse.insert("end","exp has child: keyword, " + token + "\n")
            self.myTree.insert('--exp--','end',text = 'keyword, ' + token)
            
            self.accept_token()
            self.exp() #Recalls exp to move to next step, ID 
        elif(typeT=="<ID, "):
            self.textparse.insert("end","exp has child: identifier, "+ token + "\n")
            self.myTree.insert('--exp--','end',text = 'identifer, ' + token)
            
            self.accept_token()
            self.exp() #Recalls exp to move to next step, = op
        elif(inToken[1]=="="):
            self.textparse.insert("end","exp has child: operator, " + token + "\n")
            self.myTree.insert('--exp--','end', 'op, =', text = 'op, ' + token)
            
            self.textparse.insert("end","= op has children: " + "\n")
            self.accept_token()
            self.math()
        
    def comparison_exp(self):
        global inToken
        typeT = inToken[0]
        token = inToken[1]

        if(typeT=="<ID, "):
            self.textparse.insert("end", "comparsion has child: identifier, "+token+"\n")
            self.myTree.insert('--comparison--', 'end', text = 'identifier, ' + token)

            self.accept_token()
            self.comparison_exp()
        elif(token==">"):
            self.textparse.insert("end", "comparsion has child: operator, "+token+"\n")
            self.myTree.insert('--comparison--', 'end', text = 'operator, ' + token)

            self.accept_token()
            self.comparison_exp()
        else:
            self.if_exp()
        
    def if_exp(self):
        global inToken
        token = inToken[1]

        if(token=="if"):
            self.textparse.insert("end", "--if--"+ "\n")
            self.myTree.insert('', 'end', '--if--', text = "--if--")

            self.textparse.insert("end","if has child: keyword, " + token + "\n")
            self.myTree.insert('--if--','end',text = 'keyword, ' + token)

            self.accept_token()
            self.if_exp()
        elif(token=="("):
            self.textparse.insert("end","if has child: identifier, "+ token + "\n")
            self.myTree.insert('--if--','end',text = 'identifer, ' + token)

            self.accept_token()
            self.if_exp()
        elif(token==")"):
            self.textparse.insert("end","if has child: identifier, "+ token + "\n")
            self.myTree.insert('--if--','end',text = 'identifer, ' + token)

            self.accept_token()
            self.if_exp()
        elif(token==":"):
            self.textparse.insert("end","if has child: identifier, "+ token + "\n")
            self.myTree.insert('--if--','end',text = 'identifer, ' + token)

            self.accept_token()
            self.if_exp()
        else:
            self.textparse.insert("end", "--comparison--"+ "\n")
            self.myTree.insert('--if--', 'end', '--comparison--', text = "--comparison--")
            self.comparison_exp()
    
    def parser(self): #Directions say we can hardcode the parser to parse a math_line, then a math_line, then an if_line, then a print_line
        self.currentline #This checks if we're in the first, second, third, or fourth test case. It's updated by the "next line" widget
        
        global inToken
        inToken=output.pop(0)
        
        match self.currentline:
            case 1:
                self.exp()
            case 2:
                self.textparse.delete('1.0', END)
                self.myTree.delete(*self.myTree.get_children()) #wipes tree
                self.exp()
            case 3:
                self.textparse.delete('1.0', END)
                self.myTree.delete(*self.myTree.get_children()) #wipes tree
                self.if_exp()
            case 4:
                self.textparse.delete('1.0', END)
                self.myTree.delete(*self.myTree.get_children()) #wipes tree
                self.print_exp()
            case _:
                self.textparse.delete('1.0', END)
                self.myTree.delete(*self.myTree.get_children()) #wipes tree
                self.textparse.insert("All four test cases covered.")
        
        if(inToken[1]==";"):
            self.textparse.insert("end","\nparse tree building success!"+ "\n")
            return


    def quit(self):
        root.destroy()
    
if __name__ == '__main__':
 root = Tk()
 my_gui = myGUI(root)
 root.mainloop()
