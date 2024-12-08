#include <iostream>
using namespace std;

int main() {
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    int dx, dy;
    dx = (x > w / 2) ? w - x : x;
    dy = (y > h / 2) ? h - y : y;

    int result = (dx < dy) ? dx : dy;
    cout << result << endl;
    return 0;
}