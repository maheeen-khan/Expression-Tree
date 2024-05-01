//Program to convert Infix expression to Postfix expression.

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<stack>

using namespace std;

int precedence (char c) {
    if (c == '^') {
        return 3;
    }
    else if (c == '/' || c == '*') {
        return 2;
    }
    else if (c == '+' || c == '-') {
        return 1;
    }
    else {
        return 0;
    }
}

//Function check whether a character is an operand or not.
bool IsOperand(char C) 
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}

// Function to verify whether a character is operator or not. 
bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C == '^')
		return true;

	return false;
}


//Function for converting a infix expression to postfix expression
string infixToPostfix (string expression) {
	
    stack <char> st; 
    string postFix;

    for(int i = 0; i < expression.length(); i++) {
    	
        if (IsOperand(expression[i])) {
            postFix = postFix + expression[i];
        }
        
        else if (expression[i] == '(') {
            st.push('(');
        }
        
        else if (expression[i] == ')') {
            while(st.top() != '(') {
                postFix = postFix + st.top();
                st.pop();
            }
            st.pop();
        }
        else if(IsOperator(expression[i])) {
		 //means there is an operator
            while (!st.empty() && st.top() != '(' && precedence(expression[i]) <= precedence(st.top())) {
                postFix = postFix + st.top();
                st.pop();
            }
            st.push(expression[i]);
        }
        
    }

    while (!st.empty()) {
        postFix = postFix + st.top();
        st.pop();
    }

    return postFix;
}



int main(){

    string exp = "a+b*(c^d-e)^(f+g*h)-i";
  
	cout<<"Conversion from infix to postfix\n\n";
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	
    // Function call
    cout<<"Infix Expression is : "<<exp;
   
    cout<<"\n\nPostfix Expression is : "<<infixToPostfix(exp)<<"\n";
    
    return 0;
}
