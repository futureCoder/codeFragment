#include <iostream>
int clp2(int x) {
    x = x - 1U;
    x = x | (x >> 1U);
    x = x | (x >> 2U);
    x = x | (x >> 4U);
    x = x | (x >> 8U);
    x = x | (x >> 16U);
    return (x + 1U);
}

int main() {
    for(int i = 8; i < 20; ++i) {
        cout << clp2(i) << endl;
    }
}