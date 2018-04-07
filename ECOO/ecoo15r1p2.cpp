#include<bits/stdc++.h>

using namespace std;

char words[10000][100];

int main() {

    //freopen("DATA21.txt", "r", stdin);

    int N = 10;
    while (N--) {

        string line;
        int maxlen;
        scanf("%d\n", &maxlen);
        getline(cin, line);

        int nwords = 0;
        stringstream ssin(line);
        while (ssin.good()) {
            ssin >> words[nwords];
            if (words[nwords] != "") {
                nwords++;
            }
        }

        int curlen = 0;
        bool nl = true;

        for (int i = 0; i < nwords; i++) {
            string curWord = words[i];
            if (curWord.length() > maxlen) {
                if (!nl) {
                    printf("\n");
                }
                int start = 0;
                int end = maxlen - 1;
                int last;
                while (start < curWord.length()) {
                    bool broke = false;
                    for (int j = start; j <= end; j++) {
                        last = j;
                        if (j >= curWord.length()) {
                            broke = true;
                            break;
                        }
                        printf("%c", words[i][j]);
                    }
                    if (last >= curWord.length() || last >= curWord.length() - 1 && i == nwords - 2) {
                        broke = true;
                    }
                    if (!broke) {
                        start = end + 1;
                        end = start + maxlen - 1;
                        printf("\n");
                    }
                    if (broke) {
                        printf(" ");
                        break;
                    }
                }
                curlen = last - start;
                curlen++;
                nl = true;
            } else if (curlen + curWord.length() <= maxlen) {
                printf("%s", words[i]);
                curlen += curWord.length();
                if (curlen < maxlen) {
                    printf(" ");
                    curlen++;
                    nl = false;
                } else {
                    if (i != nwords - 2) {
                        printf("\n");
                    }
                    nl = true;
                    curlen = 0;
                }
            } else {
                printf("\n");
                printf("%s ", words[i]);
                curlen = curWord.length() + 1;
                nl = false;
            }
        }
        printf("\n=====\n");
    }
    return 0;
}