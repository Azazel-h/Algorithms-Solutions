//
// Created by Azazel on 18.09.2020. solved
//

/*По заданной дате требуется определить, какое число будет послезавтра.
Напомним, что год является високосным, если его номер кратен 4, но не кратен 100, а также если он кратен 400.

ВХОДНЫЕ ДАННЫЕ
Дано число, месяц и год (год  – число в промежутке от 1 до 10000).

ВЫХОДНЫЕ ДАННЫЕ
Требуется вывести, какое число будет послезавтра, в формате входных данных.

ввод	    вывод
1 8 2009    3 8 2009
30 12 2009  1 1 2010
28 2 2008   1 3 2008
*/

#include <iostream>
#include <tuple>
using namespace std;

int DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int toDays(int d, int m, int y) {
    int days = 0;
    for (int i = 0; i < y; ++i) {
        if (isLeap(i)) {
            days += 366;
        } else {
            days += 365;
        }
    }

    if (isLeap(y)) {
        DAYS[1] = 29;
    }

    for (int i = 0; i < m-1; ++i) {
        days += DAYS[i];
    }
    days += d;
    return days;
}

tuple<int, int, int> toDate(int days) {
    int d = 0, m = 0, y = 0;

    while (days - 365 >= 0) {
        if (isLeap(y)) {
            days -= 366;
            ++y;
        } else {
            days -= 365;
            ++y;
        }
    }
    if (isLeap(y)) {
        DAYS[1] = 29;
    }
    int past = 0;
    for (int i = 0; i < 12; ++i) {
        if (days < past + DAYS[i]) {
            m = i + 1;
            d = days - past;
            break;
        } else {
            past += DAYS[i];
        }
    }

    return make_tuple(d, m, y);
}

int main() {
    int d1, m1, y1;
    cin >> d1 >> m1 >> y1;
    tuple <int, int, int> date = toDate(toDays(d1, m1, y1) + 2);
    cout << get<0>(date) << " " << get<1>(date) << " " << get<2>(date);
}
