//
// Created by Azazel on 09.10.2020. solved
//
/* После затянувшегося совещания директор фирмы решил заказать такси, чтобы развезти сотрудников по домам. Он заказал N машин — ровно столько, сколько у него сотрудников. Однако когда они подъехали, оказалось, что у каждого водителя такси свой тариф за 1 километр.
Директор знает, какому сотруднику сколько километров от работы до дома (к сожалению, все сотрудники живут в разных направлениях, поэтому нельзя отправить двух сотрудников на одной машине). Теперь директор хочет определить, какой из сотрудников на каком такси должен поехать домой, чтобы суммарные затраты на такси (а их несет фирма) были минимальны.

ВХОДНЫЕ ДАННЫЕ
Сначала во входном файле записано натуральное число N (1≤N≤1000) — количество сотрудников компании (совпадающее с количеством вызванных машин такси). Далее записано N чисел, задающих расстояния в километрах от работы до домов сотрудников компании (первое число — для первого сотрудника, второе — для второго и т.д.). Все расстояния — положительные целые числа, не превышающие 1000. Далее записано еще Nчисел — тарифы за проезд одного километра в такси (первое число — в первой машине такси, второе — во второй и т.д.). Тарифы выражаются положительными целыми числами, не превышающими 10000.

ВЫХОДНЫЕ ДАННЫЕ
В выходной файл выведите N чисел. Первое число — номер такси, в которое должен сесть первый сотрудник, второе число — номер такси, в которое должен сесть второй и т.д., чтобы суммарные затраты на такси были минимальны. Если вариантов рассадки сотрудников, при которых затраты минимальны, несколько, выведите любой из них.
ввод	    вывод
3
10 20 30    1 3 2
50 20 30

5
10 20 1 30 30   5 1 3 2 4
3 3 3 2 3

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    int n;
    cin >> n;
    vector <pair<int, int>> cars;
    vector <pair<int, int>> distances;
    vector <pair<int, int>> answ;
    int input;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        distances.push_back(make_pair(input, i + 1));
    }
    for (int i = 0; i < n; ++i) {
        cin >> input;
        cars.push_back(make_pair(input, i + 1));
    }
    sort(cars.begin(), cars.end());
    sort(distances.begin(), distances.end(), greater<pair<int, int>>());
    for (int i = 0; i < n; ++i) {
        answ.emplace_back(make_pair(distances[i].second, cars[i].second));
    }
    sort(answ.begin(), answ.end());
    for (auto &i : answ) {
        cout << i.second << " ";
    }
}