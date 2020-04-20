#include <iostream>

using namespace std;
int main() {
    cout << "AND Truth Table" << endl;
    cout << "A\tB\tAND" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << i << "\t" << j << "\t" << (i&j) << endl;
        }
    }
    return 0;
}

