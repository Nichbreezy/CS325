/* Nicholas Weekes
Cs 325
Asignment 8

1). Represent the following values in both sign-magnitude and twos complement using 16-bits
a. 874  => two Complement = 0000001101101010 
b. −110 => two Complement = 1111111110010010 
c. 2139 => two Complement = 0000100001011011 
 d. −88 => two Complement = 1111111110101000 
*/
/*
2). Find the following differences using twos complement arithmetic:
a. 101011 => 43 
 - 101010 => 42 
 = 000001 => 1 
 
b. 11101100 => 236 
 - 101100 => 44
 = 11000000 => 192

c. 111100001111 => 3855
 - 110001110011 => 3187
 = 01010011100 => 668
d. 11001011 => 203
 - 11101000 => 232
 = 11100101 => -29
*/
/*
3). Write a bool C++ function named UnsignedAddition() that takes three
 bool array parameters. Given that all arrays are of size 32 and they
 represent unsigned Boolean numbers, the function assigns the sum of the
  first two parameters to the last parameter. And then, if there is no
   overflow, it returns true; otherwise, it returns false.
*/
#include<iostream>
using namespace std;
bool UnsignedAddition(bool first[32],bool second[32],bool result[32])
{
  bool carry=0;
  for(int i=31;i>=0;i--)
  {
     //now find integer sum of all three components
     int k=(int)first[i];
     k+=(int)second[i];
     k+=(int)carry;
     if(k==3)
     {
        result[i]=1;
        carry=1;
     }
     else if(k==2)
     {
        result[i]=0;
        carry=1;
     }
     else if(k==1)
     {
        result[i]=1;
        carry=0;
     }
     else
     {
        result[i]=0;
        carry=0;
     }
  }
  // this will carry will be 1 if there is overflow
  return !carry;
}
void printNum(bool arr[32])
{
  cout<<"\n";
  for(int i=0;i<32;i++)
  {
     cout<<(int)arr[i];
  }
  cout<<"\n";
}
int main()
{
  bool first[32]={0};
  bool second[32]={0};
  second[14]=1;
  bool result[32];
  bool res=UnsignedAddition(first,second,result);
  cout<<"\nfirst num is:";
  printNum(first);
  cout<<"\nsecond num is :";
  printNum(second);
  cout<<"\n no overflow :"<<res<<"\n";
  cout<<"sum is:";
  printNum(result);
}