//
// Created by Azazel on 20.09.2020. solved
//
/* Петя очень любит наблюдать за электронными часами. Он целыми днями смотрел на часы и считал, сколько раз встречается каждая цифра. Через несколько месяцев он научился по любому промежутку времени говорить, сколько раз на часах за это время встретится каждая цифра, и очень гордился этим.

Вася решил проверить Петю, но он не знает как решать эту задачу. Вася попросил вас помочь ему. Напишите программу, решающую эту задачу. 

 

ВХОДНЫЕ ДАННЫЕ
 

Первая и вторая строки входного файла содержат начало и конец промежутка времени соответственно. Начальное время не превосходит конечное. Время задается в формате hh : mm : ss (0 ≤ hh < 24, 0 ≤ mm < 60, 0 ≤ ss < 60). hh, mm, ss дополнены ведущими нулями до двух символов. Эти нули также учитываются при подсчете числа цифр. 

 

ВЫХОДНЫЕ ДАННЫЕ
 

Выходной файл должен содержать 10 строк. В i-той строке должно быть написано, сколько раз встречается цифра i - 1.

  ввод
23:59:58
23:59:59
  вывод
    0
    0
    2
    2
    0
    4
    0
    0
    1
    3
*/

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
