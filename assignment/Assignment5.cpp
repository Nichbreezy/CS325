/* Nicholas Weekes
Cs 325
04/10/20
                        assignment 5
1). List and briefly define the possible states that define an instruction with execution with interrupts.
  * Instruction Address Calculation (IAC):
  - The address of the instruction which is to be executed is determined by this states. This stage is completed
  by adding a fixed value to the address of the previous Instruction.
  * instruction Fetch (IF):
  - The instruction stored in the memory location is read by the processor.
  * Instruction Operating Decoding (IOD):
  - The type of operation that is performed on the instruction determined along with the operand that is being used.
  * Operation Address Calculation (OAC):
  - This stage is used to identify the address of the operand or I/O device, if the operation involves reference to
  an operand in the memory.
  * Operand Fetch (OF):
  - The operation involves operand, fetches it from memory or read it from the I/O.
  * Data Operation (DO):
  - The operation indicated in the instructions is performed during this stage.
  * Operand Store (OS):
  - The result of the instruction cycle is written in memory  or put through I/O devices.

2). List and briefly define two approaches to dealing with multiple interrupts
  * First Approach
  - The first approach is to disconnect the interrupts when an intertupt is being
  processed in the processor. Because while an interruupt is being processed in the processor, the processor will
  simply ignore the new interrupt signal, this approach is referred as " disabled interrupt".
  The processor will check the interrupt once the processor has enabled interrupt.
  * Second approach
  - In the second approach, the interrupts are classified based on properties. The interrupt  with a high prority
  is allowed to cause a low priority interrupt handler to interrupt itself in the processor.

3). Write the following C++ functions for a memory module.
  * A void function named Initialize() that takes a fstream reference parameter and an int parameter
named ram. It rewrites the file referenced by ram with 100 rows of 32-character strings of zero.
  *A string function named Read() that takes a fstream reference parameter and an int parameter named
   ram and addr respectively. If addr is between 0 and 99 inclusively, the function returns the line of
   the file referenced by ram whose value equals addr; otherwise, it returns an empty string. The first
   line starts from 0.
  * A void function named Write() that takes a fstream reference parameter, a string parameter and an int
   parameter named ram, data and addr. If addr is between 0 and 99 inclusively, the function writes data
   on the line equal to addr of the file referenced by ram; otherwise, it does nothing.*/
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

//This function loops over 100 times and writes a string of 32 zeroes in each line
void Initialize(fstream &ram)
{
for(int i = 0; i < 100; i++) ram << "00000000000000000000000000000000\n";
}

string Read(fstream &ram, int addr)
{
string r;
int i = 0;

//setting the position of file pointer to the beginning
ram.seekg(0, ios::beg);

//If address is invalid return empty string
if(addr >= 100)
{
return "";
}

//Iterate over each line until required line is found. If found return it to main
while(ram >> r)
{
if(i == addr)
{
return r;
}
++i;
}
}

void Write(fstream &ram, string data, int addr)
{
//set the position of file pointer to the beginning
ram.seekg(0, ios::beg);

//If address is invalid return to main
if(addr >= 100)
{
return;
}

//Create a temporary file
fstream tempfile("temp.txt", ios::out);
int i = 0;
string r;

//append newline to the input data
data += '\n';

//Iterate over each line until required line is found
while(ram >> r)
{
//If line is found write data to the temp file
if(i == addr) tempfile << data;

//else write the contents of mem.txt to temporary file
r += '\n';
tempfile << r;
i++;
}

//close the two files
tempfile.close();
ram.close();

//remove mem.txt
remove("mem.txt");

//rename temp.txt to mem.txt
rename("temp.txt", "mem.txt");

//reopen mem.txt for further use
ram.open("mem.txt", ios::in | ios::app);
}

int main()
{
fstream f("mem.txt", ios::in | ios::out);
int choice, addr;
string s;
Initialize(f);

do
{
cout << "\n1. Read";
cout << "\n2. Write";
cout << "\n0. Exit";
cin >> choice;

switch(choice)
{
case 1:
cout << "\nEnter address: ";
cin >> addr;
s = Read(f, addr);
cout << "Data at address " << addr << ": " << s;
break;
case 2:
cout << "\nEnter address: ";
cin >> addr;
cout << "Enter new data: ";
cin >> s;
Write(f, s, addr);
cout << "\nWritten successfully!";
break;
case 0:
cout << "\nGoodbye!";
break;
default:
cout << "\nWrong choice!";
break;
}
}while(choice);

f.close();

return 0;
}
