/*
Nicholas Weekes
CS 325
05/05/20
Lab 9
*/
/*
For this lab, your objective is to complete the following task.

􏰀 Write a string C++ function named Product() that takes two string parameters. If both parameters represent binary numbers, the function will return a string that is equal to their product using Booth’s algorithm. Assume the maximum length of the binary numbers is equal to the maximum length of the two parameters. Remember the numbers are written in twos complement which implies the most significant bit is a sign bit.
*/
#include<iostream>
#include<string>

using namespace std;

void sum(int ac[], int x[], int qrn)
{
int i, c = 0;

for (i = 0; i < qrn; i++) {
ac[i] = ac[i] + x[i] + c;

if (ac[i] > 1) {
ac[i] = ac[i] % 2;
c = 1;
}
else
c = 0;
}
}

void Findcompliment(int a[], int n)
{
int i;
int x[8] = { 0};
x[0] = 1;

for (i = 0; i < n; i++) {
a[i] = (a[i] + 1) % 2;
}
sum(a, x, n);
}

void shiftRight(int ac[], int qr[], int& qn, int qrn)
{
int temp, i;
temp = ac[0];
qn = qr[0];

cout << "\t\tshiftRight\t";

for (i = 0; i < qrn - 1; i++) {
ac[i] = ac[i + 1];
qr[i] = qr[i + 1];
}
qr[qrn - 1] = temp;
}

void show(int ac[], int qr[], int qrn)
{
int i;

// accumulator content
for (i = qrn - 1; i >= 0; i--)
cout << ac[i];
cout << "\t";

// multiplier content
for (i = qrn - 1; i >= 0; i--)
cout << qr[i];
}
void Product(int br[], int qr[], int mt[], int qrn, int sc)
{
int qn = 0, ac[10] = { 0 };
int temp = 0;
cout << "qn\tq[n+1]\t\tBR\t\tAC\tQR\t\tsc\n";
cout << "\t\t\tinitial\t\t";

show(ac, qr, qrn);
cout << "\t\t" << sc << "\n";

while (sc != 0) {
cout << qr[0] << "\t" << qn;

if ((qn + qr[0]) == 1)
{
if (temp == 0) {

sum(ac, mt, qrn);
cout << "\t\tA = A - BR\t";

for (int i = qrn - 1; i >= 0; i--)
cout << ac[i];
temp = 1;
}

else if (temp == 1)
{
sum(ac, br, qrn);
cout << "\t\tA = A + BR\t";

for (int i = qrn - 1; i >= 0; i--)
cout << ac[i];
temp = 0;
}
cout << "\n\t";
shiftRight(ac, qr, qn, qrn);
}

else if (qn - qr[0] == 0)
shiftRight(ac, qr, qn, qrn);

show(ac, qr, qrn);

cout << "\t";

sc--;
cout << "\t" << sc << "\n";
}
}

int main(int argc, char** arg)
{

int mt[10], sc;
int brn, qrn;

brn = 4;
int br[] = { 1, 0, 1, 0 };
for (int i = brn - 1; i >= 0; i--)
mt[i] = br[i];

reverse(br, br + brn);

Findcompliment(mt, brn);
qrn = 4;
sc = qrn;
int qr[] = { 1, 1, 0, 1 };
reverse(qr, qr + qrn);

Product(br, qr, mt, qrn, sc);

cout << endl
<< "Result = ";

for (int i = qrn - 1; i >= 0; i--)
cout << qr[i];
}