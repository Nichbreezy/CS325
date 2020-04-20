/* A simple circuit consists of the use of NOT-gates,
 AND-gates and OR-gates. It can be written as an infix
arithmetic expression where the NOT-gate, AND-gate,
and OR-gate are represented by the symbols !, & and
| respectively. Write a string function named ToPostFix()
that takes a string parameter. Given that the parameter
rep- resents an infix circuit expression, the function
returns the expression written in postfix. The operands
of the expressions should be represented by lowercase
letters. If the expression is invalid (incorrect syntax),
the function should return an empty string. Recall, the
NOT-gate is a unary operator and the AND-gate and OR-gate
are binary operators. The NOT-gate has higher precedence
than both the AND-gate and OR-gate, but the AND-gate and
 OR-gate has the same precedence. Later expression are
 evaluated from left to right and parenetheses are valid in
 infix expressions. For instances, the call ToPostFix
 ('!a & b | !(c & a)') willreturn'a! b&ca&! |'
 */
 #include<bits/stdc++.h>

using namespace std;



//  to verify whether a given char is operator or not.

bool IsGivenOperator(char A)

{

    if(A == '!' || A == '&' || A == '|')

        return true;

    return false;

}

// find the precedence of given operators ie !,|,&

int precedence(char a)

{

    if(a == '!')

    return 2;

    else if(a == '&' || a == '|')

    return 1;

    else

    return -1;

}



//to convert to postfix expression having not,and,or gate operators

string ToPostFix(string expression)

{

    // declare the required variables

    stack<char> temp_stack;

    // to check if a stack is almost empty

    temp_stack.push('X');

    int length = expression.length();

    string postfix;



    // iterate through the given expression

    for(int i = 0; i < length; i++)

    {

        // if the expression has space or comma in between then we have to ignore it

        if(expression[i] == ' ' || expression[i] == ',')

             // do nothing

            continue;



        // if the char is an operand, add it to postfix string.

        else if((expression[i] >= 'a' && expression[i] <= 'z'))

             postfix+=expression[i];



        // if the char is an ( , push it to the stack.

        else if(expression[i] == '(')

            temp_stack.push('(');



        // if the character is an  ) , pop from stack and push to postfix string until an ( is encountered.

        else if(expression[i] == ')')

        {

            while(temp_stack.top() != 'X' && temp_stack.top() != '(')

            {

                char c = temp_stack.top();

                temp_stack.pop();

                postfix += c;

            }

            if(temp_stack.top() == '(')

            {

                char c = temp_stack.top();

                temp_stack.pop();

            }

        }



        //if the char is an operator

        else if(IsGivenOperator(expression[i])) {

            while(temp_stack.top() != 'X' && precedence(expression[i]) <= precedence(temp_stack.top()))

            {

                char c = temp_stack.top();

                temp_stack.pop();

                postfix += c;

            }

            temp_stack.push(expression[i]);

        }

        // if the char has higher case,some other operator,etc

        else

        {

            return "";

        }

    }

    // pop all the remaining operators from the stack

    while(temp_stack.top() != 'X')

    {

        char c = temp_stack.top();

        temp_stack.pop();

        postfix += c;

    }



    return postfix;

}

// executing the main function

int main()

{

    string expression = "";

    cout<<"Enter the expression to be converted to post-fix : ";

    // taking input the whole expression

    getline(cin,expression);

    string postfix = ToPostFix(expression);

    if(postfix == "")

        cout<<"Invalid Expression"<<endl;

    cout << postfix << endl;

    return 0;

}
