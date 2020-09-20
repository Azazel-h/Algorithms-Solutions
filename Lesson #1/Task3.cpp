//
// Created by Azazel on 17.09.2020.
//

#include <iostream>
using namespace std;

int main() {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int n, m = 0;
    cin >> n;
    while (n - days[m] > 0) {
        n -= days[m];
        ++m;
    }
    cout << n << " " << m + 1;
}