//
// Created by Azazel on 29.09.2020.
//

/*
Даны три строки, состоящие из строчных латинских букв. С этими строками можно производить следующие операции: либо заменить один символ строки на два таких же символа (например, заменить символ «a» на «aa»), либо, наоборот, заменить два подряд идущих одинаковых символа на один такой же символ.
Необходимо при помощи этих операций сделать все три строки равными какой-то другой общей строке S либо определить, что это сделать невозможно. При этом нужно минимизировать общее количество операций.
ВХОДНЫЕ ДАННЫЕ
Программа получает на вход три строки, состоящие из строчных букв латинского алфавита. Длина каждой строки не превышает 100 символов.
ВЫХОДНЫЕ ДАННЫЕ
Если при помощи указанных операций возможно сделать все три строки равными, выведите такую строку S , что суммарное число операций, необходимых для преобразования всех трёх данных строк к строке S , будет минимальным. Если этого сделать нельзя, программа должна вывести одно слово IMPOSSIBLE (заглавными буквами).

 ввод	  вывод
 aaaza
 aazzaa   aazza
 azzza

 xy
 xxyy    IMPOSSIBLE
 yx

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    string first, second, third;
    vector <char> ch_arr1, ch_arr2, ch_arr3;
    vector <int> n_arr1, n_arr2, n_arr3;

    char prev = -1;
    int counter = 0;
    cin >> first >> second >> third;
    prev = first[0];
    for (int i = 0; i <= first.size(); ++i) {
        if (prev != first[i]) {
            ch_arr1.push_back(prev);
            n_arr1.push_back(counter);
            prev = first[i];
            counter = 0;
        }
        ++counter;
    }
    counter = 0;
    prev = second[0];
    for (int i = 0; i <= second.size(); ++i) {
        if (prev != second[i]) {
            ch_arr2.push_back(prev);
            n_arr2.push_back(counter);
            prev = second[i];
            counter = 0;
        }
        ++counter;
    }
    counter = 1;
    prev = third[0];
    for (int i = 0; i <= third.size(); ++i) {
        if (prev != third[i]) {
            ch_arr3.push_back(prev);
            n_arr3.push_back(counter);
            prev = third[i];
            counter = 0;
        }
        ++counter;
    }
    if (ch_arr1 == ch_arr2 && ch_arr2 == ch_arr3) {
        string answ = "";
        for (int i = 0; i < n_arr1.size(); ++i) {
            int sum = n_arr1[i] + n_arr2[i] + n_arr3[i];
            for (int k = 0; k < (sum / 3); ++k) {
                answ += ch_arr1[i];
            }
        }
        cout << answ;
    } else {
        cout << "IMPOSSIBLE";
    }
}