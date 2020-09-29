//
// Created by Azazel on 17.09.2020. solved
//

/* Будильник в сотовом телефоне можно настроить так, чтобы он звонил каждый день в одно и то же время, либо в указанное время в определенный день недели. Независимо можно настроить несколько будильников.

По информации о будильниках и текущему времени и дню недели определите, когда прозвонит очередной будильник.

ВХОДНЫЕ ДАННЫЕ
В первой строке вводятся три числа, задающие текущее время: день недели (от 1 до 7), часы и минуты.

Во второй строке вводится одно натуральное число N, не превосходящее 100 – количество будильников.

В следующих N строках вводятся описания N будильников. Описание каждого будильника состоит из трех чисел: дня недели (число от 1 до 7 для понедельника,  …, воскресенья, соответственно, 0 – если будильник должен звонить каждый день), часов (от 0 до 23), минут (от 0 до 59).

 

ВЫХОДНЫЕ ДАННЫЕ
Выведите  через пробел три числа, задающие день недели, часы и минуты, когда прозвонит ближайший будильник. 

2 10 20
2
1 23 15
0 10 10
- 3 10 10

7 1 1
3
7 0 59
7 23 59
7 1 1
- 7 1 1

*/

#include <iostream>
#include <tuple>
using namespace std;

int toMinutes(int days, int hours, int minutes) {
    return days * 24 * 60 + hours * 60 + minutes;
}

tuple<int, int, int> toDate(int minutes) {
    int days = minutes / (24 * 60);
    minutes %= 24 * 60;
    int hours = minutes / 60;
    minutes %= 60;
    tuple<int, int, int> ans = make_tuple(days, hours, minutes);
    return ans;
}

int main() {
    int cur_days, cur_hours, cur_min, n, space = 10081, space2 = 10081, answer = -1, answer2 = -1, new_minutes, next_week_min;
    cin >> cur_days >> cur_hours >> cur_min >> n;

    int days, hours, minutes;
    int current_minutes = toMinutes(cur_days, cur_hours, cur_min);

    for (int i = 0; i < n; ++i) {
        cin >> days >> hours >> minutes;
        new_minutes = toMinutes(days, hours, minutes);
        if (new_minutes >= current_minutes) {
            if (space > new_minutes - current_minutes) {
                space = new_minutes - current_minutes;
                answer = new_minutes;
            }
        } else if (new_minutes < current_minutes && days != 0) {
            if (space2 > new_minutes - current_minutes) {
                space2 = new_minutes - current_minutes;
                answer2 = new_minutes;
            }
        } else if (days == 0) {
            int i = 1;
            while (i <= 7) {
                new_minutes = toMinutes(i, hours, minutes);
                if (new_minutes >= current_minutes) {
                    if (space > new_minutes - current_minutes) {
                        space = new_minutes - current_minutes;
                        answer = new_minutes;
                    }
                } else {
                    if (space2 >= new_minutes - current_minutes) {
                        space2 = new_minutes - current_minutes;
                        answer2 = new_minutes;
                    }
                }
                ++i;
            }
        }
    }

    tuple<int,int,int> ans;
    if (answer != -1) ans = toDate(answer);
    else ans = toDate(answer2);
    cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans);
}
