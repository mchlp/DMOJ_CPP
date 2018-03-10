#include <bits/stdc++.h>

using namespace std;

int tree[10001];
int view[10001];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    //freopen("DATA31.txt", "r", stdin);

    for(int N=0; N<10; N++) {

        memset(tree, 0, sizeof(tree));
        memset(view, 0, sizeof(view));

        int num;
        cin >> num;

        for (int i=0; i<num; i++) {
            cin >> tree[i];
        }

        for (int i=0; i<num-1; i++) {

            int curH = tree[i];
            double slope = -1 * INFINITY;

            for (int j=i+1; j<num; j++) {
                int visH = tree[j];
                double curSlope = (double)(visH-curH)/(double)(j-i);
                if (curSlope > slope) {
                    view[i]++;
                    view[j]++;
                    slope = curSlope;
                }
            }
        }

        int maxM = 0;
        int maxV = 0;
        for (int i=0; i<num; i++) {
            if (view[i] > maxV) {
                maxM = i;
                maxV = view[i];
            }
        }
        printf("%d\n", maxM+1);
    }

    return 0;
}
