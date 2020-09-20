#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int c[10];
int main()

{
    string a, b;
    cin >> a >> b;
    int s = ((a[0] - '0') * 10 + (a[1] - '0')) * 3600 + ((a[3] - '0') * 10 + (a[4] - '0')) * 60 + ((a[6] - '0') * 10 + (a[7] - '0'));
    int s1 = ((b[0] - '0') * 10 + (b[1] - '0')) * 3600 + ((b[3] - '0') * 10 + (b[4] - '0')) * 60 + ((b[6] - '0') * 10 + (b[7] - '0'));

    for (int i = s; i <= s1; i++)
    {
        c[i / 36000]++;
        c[(i / 3600) % 10]++;
        c[((i - (i / 3600)*3600) / 60)/10]++;
        c[((i - (i / 3600) * 3600) / 60) % 10]++;
        c[(i - (60 * (i / 60)))/10]++;
        c[(i - (60 * (i / 60))) % 10]++;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << c[i] << endl;
    }
    return 0;

}


