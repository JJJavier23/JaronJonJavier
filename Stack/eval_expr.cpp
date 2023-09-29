/**
 * Implementation of the functions to evaluate arithmetic expressions
 * The implementation should use the Stack data structure
 */
// You must complete the TODO parts and then complete LinkedList.cpp. Delete
// "TODO" after you are done. You should always comments to each function to
// describe its PURPOSE and PARAMETERS
#include "eval_expr.h"
#include "stack.h"

/**
 * @brief Evaluate a postfix expression
 * @param postfix_expr The input expression in the postfix format.
 * @param result gets the evaluated value of the expression (by reference).
 * @return true if expression is a valid postfix expression and evaluation is
 * done without error, otherwise false.
 */
bool evalPostfixExpr(string postfix_expr, float &result) {
  // TODO: Add your code here
  Stack<double> s;
  for (int i = 0; postfix_expr[i] != '\0'; i++) {
    if (postfix_expr[i] >= '0' && postfix_expr[i] <= '9') {
      // cout << postfix_expr[i] << endl;
      double t = postfix_expr[i] - '0';
      s.push(t);
    } else if (postfix_expr[i] == '+' || postfix_expr[i] == '-' ||
               postfix_expr[i] == '*' || postfix_expr[i] == '/') {
      if (s.isEmpty()) {
        // cout << "Not enough operands" << endl;
        return false;
      }
      double b;
      s.pop(b);

      if (s.isEmpty()) {
        // cout << "Not enough operands" << endl;
        return false;
      }
      double a;
      s.pop(a);

      double answer;
      switch (postfix_expr[i]) {
      case '+':
        answer = a + b;
        break;
      case '-':
        answer = a - b;
        break;
      case '*':
        answer = a * b;
        break;
      case '/':
        if (b == 0) {
          return 0;
        } else {
          answer = a / b;
        }
        break;
      }

      s.push(answer);
    } else {
      // cout << "invalid item" << endl;
      return false;
    }
  }
  double total;
  s.pop(total);

  if (!s.isEmpty()) {
    // cout << "Too many operands" << endl;
    return false;
  }
  result = total;

  return result;
}

/**
 * @brief Convert an infix expression to an equivalent postfix expression
 * @param infix_expr The input expression in the infix format.
 * @return the converted postfix expression. If the input infix expression is
 * invalid, return an empty string "";
 */
string convertInfixToPostfix(string infix_expr) {
  // TODO: Add your code here
  Stack<char> s;

  string result = "";
  char x;

  for (int i = 0; infix_expr[i] != '\0'; i++) {
    char c = infix_expr[i];

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9')) {
      result += c;
    } else if (c == '(') {
      s.push(c);
    } else if (c == ')') {
      while (s.top() != '(') {
        result += s.top();
        s.pop(x);
      }
      s.pop(x);
    } else if (infix_expr[i] == '+' || infix_expr[i] == '-' ||
               infix_expr[i] == '*' || infix_expr[i] == '/') {

      int a, d;
      char b;

      b = s.top();

      switch (c) {
      case '^':
        a = 3;
        break;
      case '/':
      case '*':
        a = 2;
        break;
      case '-':
      case '+':
        a = 1;
        break;
      default:
        a = -1;
        break;
      }

      switch (b) {
      case '^':
        d = 3;
        break;
      case '/':
      case '*':
        d = 2;
        break;
      case '-':
      case '+':
        d = 1;
        break;
      default:
        d = -1;
        break;
      }

      while (!s.isEmpty() && a <= d) {
        result += s.top();
        s.pop(x);
      }
      s.push(c);
    } else {
      result = "Invalid item";
      return result;
    }
  }

  while (!s.isEmpty()) {
    result += s.top();
    s.pop(x);
  }

  return result;
}

/**
 * @brief Evaluate an infix expression. It's converted to a postfix expression
 * first and then evaluated
 * @param infix_expr The input expression in the infix format.
 * @param result gets the evaluated value of the expression (by reference).
 * @return true if expression is valid and evaluation is done without error,
 * otherwise false.
 */
bool evalInfixExpr(string infix_expr, float &result) {
  // TODO: Add your code here
  Stack<char> ch;
  Stack<double> s;
  double x;
  double answer;
  char t;

  for (int i = 0; infix_expr[i] != '\0'; i++) {
    char c = infix_expr[i];

    if (c == '(') {
      ch.push(c);
    } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
               (c >= '0' && c <= '9')) {
      double r = infix_expr[i] - '0';
      s.push(r); 
    } else if (c == ')') {
      while (!ch.isEmpty() && ch.top() != '(') {
        double n2 = s.top();
        s.pop(x);

        if(s.isEmpty()){
            return false;
        }

        double n1 = s.top();
        s.pop(x);

        char o = ch.top();
        ch.pop(t);

        switch (o) {
        case '+':
          answer = n1 + n2;
          break;
        case '-':
          answer = n1 - n2;
          break;
        case '*':
          answer = n1 * n2;
          break;
        case '/':
          if (n2 == 0) {
            answer = 0;
          } else {
            answer = n1 / n2;
          }
          break;
        }

        s.push(answer);
      }
      if (!ch.isEmpty()) {
        ch.pop(t);
      }
    } else if(infix_expr[i] == '+' || infix_expr[i] == '-' ||
               infix_expr[i] == '*' || infix_expr[i] == '/'){

      int y, z;
      char w;

      w = ch.top();

      switch (c) {
      case '/':
      case '*':
        y = 2;
        break;
      case '+':
      case '-':
        y = 1;
        break;
      default:
        y = -1;
      }

      switch (w) {
      case '/':
      case '*':
        z = 2;
        break;
      case '+':
      case '-':
        z = 1;
        break;
      default:
        z = -1;
      }

      while (!ch.isEmpty() && y <= z) {
        double n2 = s.top();
        s.pop(x);

        if(s.isEmpty()){
            return false;
        }

        double n1 = s.top();
        s.pop(x);

        char o = ch.top();
        ch.pop(t);

        switch (o) {
        case '+':
          answer = n1 + n2;
          break;
        case '-':
          answer = n1 - n2;
          break;
        case '*':
          answer = n1 * n2;
          break;
        case '/':
          if (n2 == 0) {
            answer = 0;
          } else {
            answer = n1 / n2;
          }
          break;
        }

        s.push(answer);
      }
      ch.push(c);
    }else{
        return false;
    }
  }

  while (!ch.isEmpty()) {
    double n2 = s.top();
    s.pop(x);

    if(s.isEmpty()){
        return false;
    }

    double n1 = s.top();
    s.pop(x);

    char o = ch.top();
    ch.pop(t);

    switch (o) {
    case '+':
      answer = n1 + n2;
      break;
    case '-':
      answer = n1 - n2;
      break;
    case '*':
      answer = n1 * n2;
      break;
    case '/':
      if (n2 == 0) {
        answer = 0;
      } else {
        answer = n1 / n2;
      }
      break;
    }

    s.push(answer);
  }

  s.pop(x);

  if(!s.isEmpty() || !ch.isEmpty()){
    return false;
  }

  result = x;

  return result;
}