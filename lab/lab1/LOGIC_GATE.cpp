// This is a program for the logic Gates, NOT, NAND, AND, OR, XOR, NOR
#include<iostream>

using namespace std;

// The AND GATE function class

class AND{
  public:
 static bool operation(bool A, bool B){
 //returning true if both operands are true
if ( A ==true && B ==true){
 return true;
}
  return false;
 }
};
//The OR GATE function class
class OR{
  public:
  static bool operation(bool A, bool B){
    //returning if either one or both is true
    if (A == true || B == true){
      return true;
    }
    return false;
  }
};

//The NAND GATE function class
class NAND{
 public:
static bool operation(bool A, bool B){
  // Negation of the AND operation and provides a return
if ( A==true && B==true){
  return false;
}
return true;
  }
};

//The XOR GATE function class

class XOR{
public:
  static bool operation(bool A, bool B){
    //return true if either one is true
    if (!A == true ^ B == true){
      return true;
    }
    return false;
  }
};

//class for representing NOT gate
class NOT{
 public:
 static bool operation(bool A){
    //simply negating the operand
  if(A = true)
  return false;
}
};

//The NOR GATE function CLASS

class NOR{
  public:
 static bool operation(bool A, bool B){
//negating the result of OR operation and returning it
if (A == true || B == true){
      return false;
    }
    return true;
  }
};
int main( ){
//cout<<bool;

 // 2 element boolean array
 bool values[]={true, false};
 //looping through each pair of boolean 
for(int k=0;k<2;k++){
for(int h=0;h<2;h++){
//testing AND::operation()
cout<<values[k]<<" AND "<<values[h]<<": "<<AND::operation(values[k],values[h])<<endl;
 }
 }
cout<<endl;
 for(int k=0;k<2;k++){
for(int h=0;h<2;h++){
 cout<<values[k]<<" OR "<<values[h]<<": "<<OR::operation(values[k],values[h])<<endl;
 }
}
cout<<endl;
//testing NAND
for(int k=0;k<2;k++){
for(int h=0;h<2;h++){
cout<<values[k]<<" NAND "<<values[h]<<": "<<NAND::operation(values[k],values[h])<<endl;
}
}
cout<<endl;
//testing XOR
for(int k=0;k<2;k++){
 for(int h=0;h<2;h++){
cout<<values[k]<<" XOR "<<values[h]<<": "<<XOR::operation(values[k],values[h])<<endl;
}

                }

                cout<<endl;

               

                //NOR GATE FUNCTION

                for(int k=0;k<2;k++){

                                for(int h=0;h<2;h++){

                                                cout<<values[k]<<" NOR "<<values[h]<<": "<<NOR::operation(values[k],values[h])<<endl;

                                }

                }

                cout<<endl;

               

                //NOT GATE function 

                cout<<"NOT "<<true<<" = "<<NOT::operation(true)<<endl;

                cout<<"NOT "<<false<<" = "<<NOT::operation(false)<<endl;

                return 0;

}


