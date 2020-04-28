#include <iostream>
#include <stack>

using namespace std;

class Stack
{
private:
    class Node
    {
    public:
        int A;
        Node *next;
    };

    Node *entryNode;
    Node *terminatedNode;
    int counter;

public:
    Stack()
    {
        entryNode = NULL;
        terminatedNode = NULL;
        counter = 0;
    }

    void push(int data)
    {
        Node *present = new Node;
        present->A = data;
        present->next = NULL;

        if (entryNode == NULL)
        {
            entryNode = pres;
            terminatedNode = present;
        }
        else
        {
            terminatedNode->next = present;
            terminatedNode = present;
        }
        counter++;
    }

    int pop()
    {
        if (!empty())
        {
            Node *Former = new Node;
            Node *present = entryNode;
            while (present->next != NULL)
            {
                Former = present;
                present = present->next;
            }
            int A = present->A;
            delete present;
            present = NULL;
            Former->next = NULL;
            terminatedNode = Former;
            counter--;
            return A;
        }
        return int();
    }

    bool empty()
    {
        return entryNode == NULL || counter == 0;
    }
};


string BaseConvert(int num, int base);

int main()
{
  int x,y;
  cin >> x;
  cin >> y;
    cout << BaseConvert( x, y) << "\n";

    return 0;
}

//Convert int -> base
string BaseConvert(int num, int base)
{
    if (base < 2 || base > 16)
        return "0";

    Stack NewValue; // implementation of the stack process
    string NewString = "";

    char hexVal[] = {'A', 'B', 'C', 'D', 'E', 'F'}; //For values greater than 10

    //Divide and record remainder to Stack
    while (num > 0)
    {
        NewValue.push((num % base));
        num = num / base;
    }

    //Populate Stack to String format
    while (!NewValue.empty())
    {
        int number = NewValue.pop();
        if (number > 9)
        {
            NewString += hexVal[number - 10];
        }
        else
        {
            NewString += '0' + number;
        }
    }

    return NewString;
}
