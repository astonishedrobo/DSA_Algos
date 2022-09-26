#include <iostream>

using namespace std;

int main(void) {
    int count = 1;
    for (double i = 0.0; i < 0.000000001; i += 0.0000000001, count++) {
        cout << count << ": " << i << endl;
    }
}