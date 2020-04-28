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

3). /*Write the following C++ functions for a memory module.
  * A void function named Initialize() that takes a fstream reference parameter and an int parameter
named ram. It rewrites the file referenced by ram with 100 rows of 32-character strings of zero.
  *A string function named Read() that takes a fstream reference parameter and an int parameter named
   ram and addr respectively. If addr is between 0 and 99 inclusively, the function returns the line of
   the file referenced by ram whose value equals addr; otherwise, it returns an empty string. The first
   line starts from 0.
  * A void function named Write() that takes a fstream reference parameter, a string parameter and an int
   parameter named ram, data and addr. If addr is between 0 and 99 inclusively, the function writes data
   on the line equal to addr of the file referenced by ram; otherwise, it does nothing.
   */
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

void Initialize(fstream &ram)
{
for(int f = 0; f < 100; f++) ram << "00000000000000000000000000000000\n";
}

string Read(fstream &ram, int addr)
{
string r;
int f = 0;


ram.seekg(0, ios::beg);


  if(addr >= 100)
  {
return "";
  }

  while(ram >> r)
{
  if(f == addr)
{
  return r;
  }
++f;
  }
}

void Write(fstream &ram, string data, int addr)
{

ram.seekg(0, ios::beg);

if(addr >= 100)
{
return;
}

fstream tempfile("temp.txt", ios::out);
int f = 0;
string r;

data += '\n';
while(ram >> r)
{
if(f == addr) tempfile << data;
r += '\n';
tempfile << r;
f++;
}
tempfile.close();
ram.close();
remove("Architecture.txt");

rename("temp.txt", "Architecture.txt");
ram.open("Architecture.txt", ios::in | ios::app);
}
int main()
{
fstream f("Architecture.txt", ios::in | ios::out);
int Entry, addr;
string s;
Initialize(f);
do
{
cout << "\n1. Read/ leer";
cout << "\n2. Write/ Escribir";
cout << "\n3. Exit/ salida" << endl;
cout<< "Enter Desired Entry!!!" << endl;
cin >> Entry;

switch(Entry)
{
case 1:
cout << "\nEnter address: ";
cin >> addr;
s = Read(f, addr);
cout <<  "address data " << addr << ": " << s;
break;

case 2:
cout << "\nEnter address: ";
cin >> addr;
cout << "Enter new data: ";
cin >> s;
Write(f, s, addr);
cout << "\n Success!";
break;

case 3:
cout << "\nAdios!";
break;
default:
cout << "\nInvalid Entry!";
break;
}
}while(Entry);

f.close();
    //PAUSE;
return 0;
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
