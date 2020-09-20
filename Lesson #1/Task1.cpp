//
// Created by Azazel on 17.09.2020.
//

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
    int cur_days, cur_hours, cur_minutes, n, space = 10081, answer = -1, new_min;
    cin >> cur_days >> cur_hours >> cur_minutes >> n;

    int days, hours, minutes;
    int c_min = toMinutes(cur_days, cur_hours, cur_minutes);

    for (int i = 0; i < n; ++i) {
        cin >> days >> hours >> minutes;
        if (days != 0) {
            new_min = toMinutes(days, hours, minutes);
            if (c_min <= new_min) {
                if (space > new_min - c_min) {
                    space = new_min - c_min;
                    answer = new_min;
                }
            }
        } else if (days == 0) {
            if (c_min <= toMinutes(cur_days, hours, minutes)) {
                new_min = toMinutes(cur_days, hours, minutes);
                if (space > new_min - c_min) {
                    space = new_min - c_min;
                    answer = new_min;
                }
            } else if (c_min <= toMinutes(cur_days + 1, hours, minutes)) {
                new_min = toMinutes(cur_days + 1, hours, minutes);
                if (space > new_min - c_min) {
                    space = new_min - c_min;
                    if (cur_days + 1 > 7) answer = toMinutes(1, hours, minutes);
                    else answer = new_min;
                }
            }
        }

    }
    tuple<int,int,int> ans = toDate(answer);
    cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans);
}
