#include <bits/stdc++.h>

using namespace std;

vector<int> in;
vector<int> res;

int main() {
    int N;
    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        int num;
        scanf("%d", &num);
        in.push_back(num);
    }

    res.push_back(0);
    for (int i=1; i<N; i++) {
        if (in[i] > in[i-1]) {
            res.push_back(res.back());
        } else {
            int see = 0;
            for (int j=i-1; j>=0; j--) {
                if (in[j] > in[i]) {
                    see++;
                    break;
                } else {
                    see++;
                }
            }
            res.push_back(see);
        }
    }

    for (int i=0; i<N; i++) {
        printf("%d ", res[i]);
    }

    return 0;
}