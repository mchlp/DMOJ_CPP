#include <bits/stdc++.h>

using namespace std;

int main() {

    int x1, y1, x2, y2, x3, y3;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);

    int m = min(pow(x1-x2, 2)+ pow(y1-y2, 2), min(pow(x2-x3, 2)+ pow(y2-y3, 2), pow(x1-x3, 2)+ pow(y1-y3, 2)));
    printf("%d", m);

}