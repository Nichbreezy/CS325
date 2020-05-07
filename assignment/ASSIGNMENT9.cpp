/*

Nicholas Weekes
5/4/2020
CS 325
ASSIGNMENT 9
Write the product of each of the following two unsigned 8-bit binary numbers
a. 11001110 and 00110011 
	206 x 51 = 10506
	11001110 x 00110011 = 010100100001010

b. 11011011 and 11100110
	219 x 230 = 50370
	11011011 x 11100110 = 01100010011000010
	
2. Prove that the multiplication of two n-digit numbers in base B gives a product of no more than 2n digits.
- The largest number of "n" binary will be 2n-1. Thus, the largest product will therefore be " (2^n-1) = 2^n+1 + 1). The value will lie betwee 2^n-1 & 2^2n, Therfore, it has 2^n digits. 

3. Write a string C++ function named UnsignedPartialSum() that takes two string parameters and an int parameter. If both string parameters represent binary numbers and the int parameter is equal to a positive number less than or equal to the length of the longest string parameter, the function should return a binary string whose length is equal to two times the length of the maximum length of the two string parameters whose value is equal to the sum of the product of the first string parameter times the element of the second string whose position is equal to the int parameter shifted to the left the int parameter minus one places and zero; otherwise, the function returns an empty string. For instances, if '1101101' and '10111' are the string parameters and 3 is equal to the int parameter, the function would return '00000110110100'.
*/
	#include <iostream>
	#include<string>
	using namespace std;

		string unsignedPartialSum(string, string, int);

		int main()
		{
		cout << unsignedPartialSum("1101101", "10111", 3);
	}

	string unsignedPartialSum(string firstBinary, string secondBinary, int some_number) {
		//Length of the binaries.
		int length_firstBinary = firstBinary.length();
		int length_secondBinary = secondBinary.length();

		//Checks if the binaries are actually binary.
		for (int i = 0; i != length_firstBinary; i++) {
			if (firstBinary[i] != '0' && firstBinary[i] != '1') {
				return "First string is not a binary number.";
			}
		}
		for (int i = 0; i != length_secondBinary; i++) {
			if (secondBinary[i] != '0' && secondBinary[i] != '1') {
				return "Second string is not a binary number.";
			}
		}

		//Finds out and assigns the binaries with the longest length.
		int longestBinary;
		if (length_firstBinary > length_secondBinary) {
			longestBinary = length_firstBinary;
		}
		else {
			longestBinary = length_secondBinary;
		}
		
		//Where the magic happens.
		if (some_number > 0 && some_number <= longestBinary) {
			//Converting binary to decimal
			int converted_firstBinary = 0;
			cout << firstBinary << endl;
			for (int i = 0; i < length_firstBinary; i++) {
				if (firstBinary[i] == '1') {
					converted_firstBinary += pow(2, length_firstBinary - 1 - i);
				}
			}
			int dec_returnValue = converted_firstBinary * pow(2, some_number-1);
			
			//Convert back to binary.
			char buffer[20];
			_itoa_s(dec_returnValue, buffer, 2);
			//buffer to string
			string bin_returnValue = buffer;

			//Adds 0's until equal to two times the length of the maximum length
			int loopstop = length_firstBinary * 2 - bin_returnValue.length();
			for (int i = 0; i != loopstop; i++) {
				bin_returnValue = "0" + bin_returnValue;
			}
			return bin_returnValue;
			
		}
		else {
			return "";
		}
	}
	
