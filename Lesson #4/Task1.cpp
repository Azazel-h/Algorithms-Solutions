//
// Created by Azazel on 09.10.2020. solved
//

/* В этой задаче Вася готовится к олимпиаде. Учитель дал ему N (1 ≤ N ≤ 100) задач для тренировки. Для каждой из этих задач известно, каким умением ai нужно обладать для её решения. Это означает, что если текущее умение Васи больше либо равно заданного умения для задачи, то он может ее решить. Кроме того, после решения i-й задачи Васино умение увеличивается на число bi.
Исходное умение Васи равно A. Решать данные учителем задачи он может в произвольном порядке. Какое максимальное количество задач он сможет решить, если выберет самый лучший порядок их решения?

ВХОДНЫЕ ДАННЫЕ
Сначала вводятся два целых числа N, A (1 ≤ N ≤ 100, 0 ≤ A ≤ 100) — количество задач и исходное умение. Далее идут N пар целых чисел ai, bi (1 ≤ ai ≤ 100, 1 ≤ bi ≤ 100) — соответственно сколько умения нужно для решения i-й задачи и сколько умения прибавится после её решения.

ВЫХОДНЫЕ ДАННЫЕ
Выведите одно число — максимальное количество задач, которое Вася может решить.
ввод	вывод
3 2
3 1      3
2 1
1 1

4 1
1 10
21 5     3
1 10
100 100
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, skill, input1, input2;
    cin >> n >> skill;
    vector <pair<int, int>> arr;
    for (int i = 0; i < n; ++i) {
        cin >> input1 >> input2;
        arr.emplace_back(input1, input2);
    }
    sort(arr.begin(), arr.end());
    int i = 0;
    int answ = 0;
    while (skill >= arr[i].first && i < arr.size()) {
        skill += arr[i].second;
        ++answ;
        ++i;
    }
    cout << answ;
    return 0;
}
