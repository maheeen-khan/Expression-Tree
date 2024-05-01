// Evaluate Postfix Expression

//#include <bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stack>

using namespace std;


int evaluatePostfix(string exp){

	stack<int> st;

	
	for (int i = 0; i < exp.size(); i++) {
		
		// If the scanned character is an operand push it to the stack.
		if (isdigit(exp[i])){
			st.push(exp[i] - '0');
		}
			

		// If the scanned character is an operator, pop two elements from stack apply the operator
		else {
			
			int val1 = st.top();
			st.pop();
			int val2 = st.top();
			st.pop();
			
			
			switch (exp[i]) {
			case '+':
				st.push(val2 + val1);
				break;
			case '-':
				st.push(val2 - val1);
				break;
			case '*':
				st.push(val2 * val1);
				break;
			case '/':
				st.push(val2 / val1);
				break;
			case '>':
				st.push(val2 > val1);
				break;
			case '<':
				st.push(val2 < val1);
				break;
			case '!':
				st.push(val2 != val1);
				break;
			case '&':
				st.push(val2 && val1);
				break;
			case '|':
				st.push(val2 || val1);
				break;
			}
		}
	}
	return st.top();
}

// Driver code
int main()
{
	string exp = "231*+";
	string exp2 = "1231-*+3<32!32+5<|&";

	// Function call
	cout << "postfix evaluation: " << evaluatePostfix(exp);
	cout<<"\n";
	cout << "postfix evaluation 2 : " << evaluatePostfix(exp2);
	return 0;
}

