#include <iostream>
using namespace std;

int month(int k, int y)
{
    if (k == 2) return 28 + (y % 400 == 0 || y % 4 == 0 && y % 100 != 0);
    return 28 + ((k + k / 8) & 1) + (2 % k) + (1 / k) * 2;
}

int main()
{
    int d, m, y;
    cin >> d >> m >> y;
    d += 2;
    if (d > month(m, y))
    {
        d -= month(m, y);
        ++m;
    }
    if (m == 13)
    {
        m = 1;
        ++y;
    }
    cout << d << " " << m << " " << y;
    return 0;
}

