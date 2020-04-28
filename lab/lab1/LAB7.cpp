/*
Nicholas Weekes
04/23//20
Lab 7
*/

/*
Write a string C++ function named BaseSquareConvertion()
 that takes a string parameter and an int parameter named
num and base respectively. If base is between 2 and 8
inclusively and num is a vaild number in base base,
return the string conversion of num to the base that
is equal to the square of the base; otherwise, return '0'.
For bases over 16, write to a file named “digits.txt” the
digits of the base. The number num can have a fractional portion.
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool CurrentBase(string num, int base) {
	//Bases are are at base 16, (Hexadecimal)
	if (base > 16)
		return false;

	/* If base is less than or equal to 10, then all
	digits should be from 0 to 9.*/
	else if (base <= 10) {
		for (int b = 0; b < num.length(); b++)
			if (!(num[b] >= '0' and
				num[b] < ('0' + base)))
				return false;
	}

	/* If base is less than or equal to 16, then all
	digits should be from 0 to 9 or from 'A'*/
	else {
		for (int b = 0; b < num.length(); b++) {
			if (!((num[b] >= '0' && num[b] < ('0' + base)) ||
				(num[b] >= 'A' && num[b] < ('A' + base - 10))))
    }
    }}
				string BinaryBaseConverter(string num, int base) {
				if (!CurrentBase(num, base) || base < 2 || base > 8) {
					return "0";
				}
				int new_base = pow(base, 2);
				// Convert num to new_base value
			}
			int main() {
				// std::ofstream std;
        fstream fs;
					fs.open("digits.txt", ios::out | ios::in);
				if (!fs)
				{
					std::cout << "Can not access the file requested." << std::endl;
					return 1;
				}
				fs << "Bazinga!!"<< endl;
				fs.close()

					return 0;
			}
