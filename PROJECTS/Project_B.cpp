/*You will be creating a twos complement divisor function. It will accept two binary strings as parameters where the first parameter is the dividend and the second parameter is the divisor. And it will return a binary string which will be the length of 2n where the most significant n bits (characters) represent the quotient and the least significant n bits (characters) represent the remainder with n being the length of the longest string parameter.
 The list below wil be instructions and constraints for your function that you must adhere to.
  • The remainder portion of the solution must be an unsigned binary number between 0 and one minus the divisor inclusively.
  • You must to define a bool function that verifies that both string parameters are binary strings. Your divide function must call this function at the beginning of its definition. And if this function returns false, the divide function must return '0'.
  • You must define a bool function(s) that comapares two binary strings. It (or they) must be called in the divide function whenever a comparison is needed.
  • You must define a function that perform both addition and subtraction of two binary strings (either unsigned or twos complement). The function must accept two binary string parameters and a bool parameter which indicates if the function is performing addition or subtraction. Last, it will return the result of the operation as a binary string. Your divide function must call this function whenever it is performing addition or subtraction.
  • The use of STL library classes are prohibited.
  */
#include <iostream>
#include<string>
using namespace std;

bool Binary(string N)
{
for(int i=0;i<N.length();i+=1)
{

if(N[i]!='0' && N[i]!='1')
{
return false;
}

}
return true;
}

bool Greater(string F1,string F2)
{
int l1=F1.length();
int l2=F2.length();
string temp="";
if(l1<l2)
{
for(int i=0;i<l2-l1;i+=1)
temp=temp+'0';
F1=temp+F1;
}
if(l1>l2)
{
for(int i=0;i<l1-l2;i+=1)
temp=temp+'0';
F2=temp+F2;
}
for(int i=0;i<F1.size();i+=1)
{
if(F1[i]=='1' && F2[i]=='0')
{
return true;
}

if(F1[i]=='0' && F2[i]=='1')
{
return false;
}

}
return false;
}
string addition(string F1,string F2)
{
int carry=0;
int a=0;
string N="";
for(int i=0;i<F1.length();i+=1)
{
N=N+'0';
}
for(int i=F1.length()-1;i>=0;i-=1)
{
if(F1[i]=='0')
a+=0;

else
a+=1;
if(F2[i]=='0')
a+=0;
else
a+=1;
a+=carry;
if(a>1)
{
N[i]=(char)((int)'0'+(a%2));
carry=a/2;
}
else if(a==1)
{
N[i]='1';
carry=0;
}
else
{
N[i]='0';
carry=0;
}
a=0;
}
return N;
}
string c2cal(string N)
{
string ad1="";
for(int i=0;i<N.length();i+=1)
{
ad1=ad1+'0';
if(N[i]=='0')
N[i]='1';
else
N[i]='0';
}
ad1[N.length()-1]='1';
return addition(N,ad1);
}
string subtract(string F1,string F2)
{
string c2F2=c2cal(F2);
string N=addition(F1,c2F2);
return N;
}
string divide(string F1,string F2)
{
string ns=F1;
int cnt=0;
while(Greater(ns,F2))
{
ns=subtract(ns,F2);
cnt+=1;
}
string N="";
for(int i=0;i<F2.length();i+=1)
N=N+'0';
int o=F2.length()-1;
while (cnt > 0)
{
if(cnt%2==0)
N[o]='0';
else
N[o]='1';
cnt=cnt/2;
o-=1;
}
N=N+ns;
return N;
}

int main()
{
string s1=" ";
cout <<"Your first binary is: " << s1<< endl;
cin >> s1;
string s2=" ";
cout <<"Your second binary is: " << s2<< endl;
cin >> s2;
cout << "Wah-La!!!, your Quotient is: "<<s1<<"/"<<s2<<"="<<divide(s1, s2)<<endl;
}
