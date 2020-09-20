#include <iostream>

using namespace std;

long long md, mh, mm, allt;
int mins;

int gettime(int d, int h, int m) {
    int nowt = d * 1440 + h * 60 + m;
    return (nowt - allt + mins) % mins;
}

int main() {
    cin >> md >> mh >> mm;
    md--;
    allt = md * 1440 + mh * 60 + mm;
    int n;
    cin >> n;
    mins = 1440 * 7;
    int d, h, m;
    int mint = mins, thist;
    for (int i = 0; i < n; i++) {
        cin >> d >> h >> m;
        d--;
        if (d == -1) {
            thist = min(gettime((md + 1) % 7, h, m), gettime(md, h, m));
        } else {
            thist = gettime(d, h, m);
        }
        mint = min(mint, thist);
    }
    mm = mm + mint;
    mh = mh + mm / 60;
    mm = mm % 60;
    md = md + mh / 24;
    mh = mh % 24;
    md = md % 7;
    md++;
    cout << md << ' ' << mh << ' ' << mm;
}