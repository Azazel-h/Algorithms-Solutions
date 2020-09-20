//
// Created by Azazel on 20.09.2020.
//

#include <cstdio>
#include <iostream>
#include <tuple>

using namespace std;

int ans[10] = {0};

tuple <int, int, int> fromSec(int seconds) {
    int h = seconds / 3600;
    seconds %= 3600;
    int m = seconds / 60;
    seconds %= 60;
    int s = seconds;
    return make_tuple(h, m, s);
}

int toSec(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

void count(int first, int second) {
    for (int i = first; i <= second; ++i) {
        tuple<int, int, int> nums = fromSec(i);
        int h = get<0>(nums);
        int m = get<1>(nums);
        int s = get<2>(nums);
        ++ans[h / 10];
        ++ans[h % 10];
        ++ans[m / 10];
        ++ans[m % 10];
        ++ans[s / 10];
        ++ans[s % 10];
    }
}


int main() {
    int h1, m1, s1;
    int h2, m2, s2;
    scanf("%d:%d:%d", &h1, &m1, &s1);
    scanf("%d:%d:%d", &h2, &m2, &s2);
    int sec1 = toSec(h1, m1, s1);
    int sec2 = toSec(h2, m2, s2);

    if (sec1 <= sec2) {
        count(sec1, sec2);
    } else {
        count(sec1, 86399);
        count(0, sec2);
    }
    for (int i = 0; i < 10; ++i) {
        cout << ans[i] << endl;
    }
}