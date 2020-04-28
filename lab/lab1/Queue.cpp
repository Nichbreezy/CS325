#include <iostream>
#include<string>
#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;

#define SIZE 10 // define default capacity of the Queue
class Queue // Class for Queue
{

   char *arr;       // array to store Queue elements
   int capacity;   // maximum capacity of the Queue
   int front;       // front points to front element in the Queue (if any)
   int rear;       // rear points to last element in the Queue
   int count;       // current size of the Queue

public:
   Queue(int size = SIZE)   // constructor
   {
   arr = new char[size];
   capacity = size;
   front = 0;
   rear = -1;
   count = 0;
    }
   ~Queue()                 // destructor
   {
   delete arr;
    }


   void dequeue();
   void enqueue(char x);
   char cars();
   int size();
   bool isEmpty();
   bool isFull();
   double LittlesLaw(ifstream &,int);
};



void Queue::dequeue() // Utility function to remove front element from the Queue
{

   if (isEmpty())   // check for queue underflow
   {
       cout << "Program Terminated";
       exit(EXIT_FAILURE);
   }

   cout << "Removing " << arr[front] << '\n';

   front = (front + 1) % capacity;
   count--;
}


void Queue::enqueue(char item) // Utility function to add an item to the Queue
{
   if (isFull())  // check for queue overflow
   {
       cout << "OverFlow\nProgram Terminated\n";
       exit(EXIT_FAILURE);
   }

   cout << "Inserting " << item << '\n';

   rear = (rear + 1) % capacity;
   arr[rear] = item;
   count++;
}


char Queue::cars() // Utility function to return front element in the Queue
{
   if (isEmpty())
   {
       cout << "UnderFlow\nProgram Terminated\n";
       exit(EXIT_FAILURE);
   }
   return arr[front];
}


int Queue::size() // Utility function to return the size of the Queue
{
   return count;
}


bool Queue::isEmpty() // Utility function to check if the Queue is empty or not
{
   return (size() == 0);
}


bool Queue::isFull() // Utility function to check if the Queue is full or not
{
   return (size() == capacity);
}

double Queue::LittlesLaw(ifstream &inFile,int w)
{
map<char,int>mCharCount;
char ch;
int numberOfcharactersPerRead=0;
int totalNumberOfRead=0;
while (inFile.get(ch)) {
   // cout<<ch<<endl;

    enqueue(ch);

    char frontChar=cars();  //read
    mCharCount[frontChar]++; //increment read count of a character.

    if(mCharCount[frontChar]==w) //check number read count = w
    {
        dequeue();
    }

    totalNumberOfRead++;
    numberOfcharactersPerRead+=size();

}

while(!isEmpty())
   {
    char frontChar=cars(); //read
    mCharCount[frontChar]++; //increment read count of character.
    if(mCharCount[frontChar]==w)//check number read count = w
    {
        dequeue();

    }
    totalNumberOfRead++;
    numberOfcharactersPerRead+=size();
   }

return (numberOfcharactersPerRead/totalNumberOfRead); //return average.

}


// main function
int main()
{
   // create a Queue of capacity 5
   Queue q(26); //size of queue will the number of character in the file to prevent from overflow.



ifstream inFile("input.txt"); //open the required file.

//check the file is opened correctly.
if(inFile)
cout<<"file is successfully opened!!!\n";

//error display, when file is not opened.
if (!inFile) {
    cerr << "Unable to open file input.txt";
}
double average=q.LittlesLaw(inFile,3);
cout<<fixed<<setprecision(2)<<"Average Number of character in queue:"<<average<<endl;

   return 0;
}
