/*
Write a bool function named EvaluateCircuit()
that takes a string parameter and a bool array
parameter. Given that the string parameter is
an postfix circuit expression and the bool array
is the values of the operands of the circuit
expression such that each letter corresponds
to the index that is one less than its position
in the alphabet, the function returns the evaluation
of the expression with the given value from the array.
The array can have at most 26 values and the operands
of the expression must be lowercase letters. If the
expression is invalid. the function should return false.
*/
// Example program
#include <iostream>
#include <string>
#include<stack>
using namespace std;

int main()
{
   stack<char>st;
   bool result;
   for(int i=0;i<len;i++){
       if(postfix[i] == ' ')
           continue;

       else if(postfix[i] >= 'a' && postfix[i] <= 'z'){
           st.push(postfix[i]);
       }

       else if(postfix[i] == '!'){
           if(st.empty()){
               // invalid expression
               return false;
           }
           if(st.top() == 'r')
               result = !(result);

           else{
               result = !(value[st.top()-97]);
               st.pop();
               st.push('r');
           }
       }

       else if(postfix[i] == '&'){
           char ch1,ch2;
           if(st.empty()){
               // invalid expression
               return false;
           }
           else{
               ch1 = st.top();
               st.pop();
           }

           if(st.empty()){
               // invalid expression
               return false;
           }
           else{
               ch2 = st.top();
               st.pop();
           }

           if(ch1 == 'r'){
               result = result & value[ch2-97];
               st.push('r');
           }

           else if(ch2 == 'r'){
               result = (value[ch1-97] & result);
               st.push('r');
           }
           else{
               result = (value[ch1-97] & value[ch2-97]);
               st.push('r');
           }
       }

       else if(postfix[i] == '|'){
           char ch1,ch2;
           if(st.empty()){
               // invalid expression
               return false;
           }
           else{
               ch1 = st.top();
               st.pop();
           }

           if(st.empty()){
               // invalid expression
               return false;
           }
           else{
               ch2 = st.top();
               st.pop();
           }

           if(ch1 == 'r'){
               result = result & value[ch2-97];
               st.push('r');
           }

           else if(ch2 == 'r'){
               result = (value[ch1-97] & result);
               st.push('r');
           }
           else{
               result = (value[ch1-97] & value[ch2-97]);
               st.push('r');
           }
       }
   }
   return result;
}

//main function PROGRAM EXECUTION STARTS HERE
int main(){

   // value array
   bool value[] = {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true};
   string exp = "!a & b | !(c & a)";
   // Part 1
   string result=ToPostFix(exp);
   cout<<result<<endl;


   // Part2
   bool boolResult = EvaluateCircuit(result,value);
   cout<<boolResult<<endl;
   return 0;
}
