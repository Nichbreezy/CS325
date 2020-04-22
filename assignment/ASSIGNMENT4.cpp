/*1. Brieﬂy characterize Amdahl’s law and Little’s law.
 Amdahl's law is a specific formula that  is used to implement into the system to improve the Operating System.
 Whereas Little'sLaw play the part of managing the operations of the computer system*/
 /*2. CPI= (Instruction Count) (Cycles Per Second)/ (Number of Instructions consisted by the executed program)
 (IA)+(DT)+(FP)+(CT)/ (Number of instructioons executed by the program)
 (45000 x 1) + (32,000 x 2) + (15,000 x 2) + (8,000 x 2)/ (100,000)
 = (45,000) + (64,000) + (30,000) + (16,000)/ (100,000)
 = (155,000/ (100,000)
 = 1.55 => The CPI of the program
 TIME PROCESSOR = T = Ic * CPI * r
 r = constant cycle time
 r = 1/freq
 MIPS = Ic/ T * 10^6
 = Ic/ Ic * CPI * r * 10^6
 = 1/ CPI * 1/freq * 10^6
 = freq/(CPI *10^6
 MIPS = (40 *10^6)/(1.55 * 10^6)
 = 40/1.55
 =25.8 => The MIPS of the program
 T= Ic * CPI * 1/freq
 T= (100,000 * 1.55)/(40 * 10^6)
 T = 155,000/(40000000)
 = 0.003875
 = 3.875 ms => The Execution Time
 */

/*3. Write a C++ function that takes a numerical expression string whose operands are lowercase letters, and converts it from an inﬁx
expression string to postﬁx expression string. For instances, if the argument of the function call is ''a + b * c'', the function will
return ''a b c * +''. Furthermore, for the argument ''(a + b) * c'', it will return ''a b + c *''. If the numerical expression string
is in an invalid format, the function should return an empty string.*/


#include<iostream>
#include<stack>
#include<string>

using namespace std;

// Function to convert Infix expression to postfix

string InfixToPostfix(string expression);



// Function to verify whether an operator has higher precedence over other

int HasHigherPrecedence(char opt1, char opt2);



// Function to verify whether a character is operator symbol or not.

bool IsOperator(char C);



// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not.

bool IsOperand(char C);



int main()

{

	string expression;

	cout<<"Enter Infix Expression \n";

	getline(cin,expression);

	string postfix = InfixToPostfix(expression);

	cout<<"Output = "<<postfix<<"\n";

}



// Function to evaluate Postfix expression and return output

string InfixToPostfix(string expression)

{

	// Declaring a Stack from Standard template library in C++.

	stack<char> S;

	string postfix = ""; // Initialize postfix as empty string.

	for(int i = 0;i< expression.length();i++) {



		// Scanning each character from left.

		// If character is a delimitter, move on.

		if(expression[i] == ' ' || expression[i] == ',') continue;



		// If character is operator, pop two elements from stack, perform operation and push the result back.

		else if(IsOperator(expression[i]))

		{

			while(!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(),expression[i]))

			{

				postfix+= S.top();

				S.pop();

			}

			S.push(expression[i]);

		}

		// Else if character is an operand

		else if(IsOperand(expression[i]))

		{

			postfix +=expression[i];

		}



		else if (expression[i] == '(')

		{

			S.push(expression[i]);

		}



		else if(expression[i] == ')')

		{

			while(!S.empty() && S.top() !=  '(') {

				postfix += S.top();

				S.pop();

			}

			S.pop();

		}

	}



	while(!S.empty()) {

		postfix += S.top();

		S.pop();

	}



	return postfix;

}



// Function to verify whether a character is english letter or numeric digit.

// We are assuming in this solution that operand will be a single character

bool IsOperand(char C)

{

	if(C >= '0' && C <= '9') return true;

	if(C >= 'a' && C <= 'z') return true;

	if(C >= 'A' && C <= 'Z') return true;

	return false;

}



// Function to verify whether a character is operator symbol or not.

bool IsOperator(char C)

{

	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')

		return true;



	return false;

}



// Function to verify whether an operator is right associative or not.

int IsRightAssociative(char op)

{

	if(op == '$') return true;

	return false;

}



// Function to get weight of an operator. An operator with higher weight will have higher precedence.

int GetOperatorWeight(char op)

{

	int weight = -1;

	switch(op)

	{

	case '+':

	case '-':

		weight = 1;

	case '*':

	case '/':

		weight = 2;

	case '$':

		weight = 3;

	}

	return weight;

}



// Function to perform an operation and return output.

int HasHigherPrecedence(char op1, char op2)

{

	int op1Weight = GetOperatorWeight(op1);

	int op2Weight = GetOperatorWeight(op2);



	// If operators have equal precedence, return true if they are left associative.

	// return false, if right associative.

	// if operator is left-associative, left one should be given priority.

	if(op1Weight == op2Weight)

	{

		if(IsRightAssociative(op1)) return false;

		else return true;

	}

	return op1Weight > op2Weight ?  true: false;

}
