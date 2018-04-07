#include<bits/stdc++.h>

using namespace std;

char words[501][51];

int main() {
    int w;
    scanf("%d", &w);
    for (int i = 0; i < w; i++) {
        scanf("%s", &words[i][0]);
    }
    string line;
    getline(cin, line);
    getline(cin, line);
    stringstream ss(line);
    while (ss.good()) {
        string word;
        ss >> word;
        if (word != "") {
            bool found = false;
            for (int i = 0; i < w; i++) {
                if (word.compare(string(words[i])) == 0) {
                    found = true;
                }
            }
            if (!found) {
                printf("Incorrect");
                return 0;
            }
        }
    }
    printf("Correct");
    return 0;
}