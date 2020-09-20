//
// Created by PickBas on 20.09.2020.
//

#include <iostream>
#include <cstdio>
#include <tuple>
#include <vector>

std::tuple <int, int, int> fromSec(int seconds) {
    int h = seconds / 3600;
    seconds %= 3600;
    int m = seconds / 60;
    seconds %= 60;
    int s = seconds;
    return std::make_tuple(h, m, s);
}

int toSec(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

void count(int first, int second) {
    std::vector<int> result(10);

    for (int i = first; i <= second; ++i) {
        std::tuple <int, int, int> current = fromSec(i);

        result[std::get<0>(current) % 10] += 1;
        result[std::get<0>(current) / 10 % 10] += 1;
        result[std::get<1>(current) % 10] += 1;
        result[std::get<1>(current) / 10 % 10] += 1;
        result[std::get<2>(current) % 10] += 1;
        result[std::get<2>(current) / 10 % 10] += 1;
    }

    for (const auto& i : result){
        std::cout << i << '\n';
    }


}

int main() {
    int h1, m1, s1;
    int h2, m2, s2;
    scanf("%d:%d:%d", &h1, &m1, &s1);
    scanf("%d:%d:%d", &h2, &m2, &s2);

    count(toSec(h1, m1, s1), toSec(h2, m2, s2));
    return 0;
}