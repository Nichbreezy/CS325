/*
1). Convert the following binary numbers to their decimal equivalents:
a. 11100.011 => (16)+(8)+(4)+(1/4)+(1/8) = 28.375
b. 110011.10011 => (32)+(16)+(2)+(1)+(1/2)+(1/16)+(1/32)= 51.59375
c. 1010101010.1 => (512)+(128)+(32)+(8)+(2)+(1/2) = .682.5
d. 0.1101101 => (1/2)+(1/4)+(1/16)+(1/32)+(1/128) = .8515625
*/

/*
2). Convert the following hexadecimal numbers to their decimal equivalents:
a. F.4
=>(15x16^0) + (4x16^-1)
=> 15 + .25 = 15.25
b. D3.E
=>(4x16^1)+(3x16^0)+(5x16^-1)
=> (64)+(3)+(.3125)= 67.3125
c. 1111.1
=>(1x16^3)+(1x16^2)+(1x16^1)+(1x16^0)+(1x16^-1)
=> (4096)+(256)+(16)+(1)+(.0625)= 4369.0625
d. 888.8
=>(8x16^2)+(8x16^1)+(8x16^0)+(8x16^-1)
=> (2048)+(128)+(8)+(8/16)= 2184.5
*/
/*
Write a string C++ function named BinaryFraction() that takes a double
parameter. If the parameter is between 0 and 1 exclusively, the function
returns the binary representation of the parameter as a string to at most 30
decimal places; otherwise, it returns '0'.
*/
#include<iostream>
#include<string>
using namespace std;

string binaryFraction(double n) { // string prameter
    if (n >= 1 || n <= 0) // check to verify if the number is between 1 & 0
        return "INVALID";

    string answer;
    answer.append(".");
    if (n == 1)
        return "1";
    if (n == 0)
        return "0";
    while (n > 0)
    {
        if (answer.length() >= 31) // limit of the decimal length to 31 max!!
            return "0";
        double b = n * 2; // multiple n by 2 to verify if its 1 or 0
        if (b >= 1)
        {
            answer.append("1");
            n = b - 1;
        }
        else
        {
            answer.append("0");
            n = b;
        }
    }
    return answer;
}
int main() { //DRIVER
    double num;
    cout << "Enter your desired decimal number" << endl;
    cin >> num;
    string result = binaryFraction(num);
    cout << "The binary is:" << result << endl;
}
