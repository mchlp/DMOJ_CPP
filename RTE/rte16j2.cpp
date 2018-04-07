#include<bits/stdc++.h>

using namespace std;

vector<int> blue;
vector<int> green;
vector<int> pink;

int main() {

    int N;
    scanf("%d\n", &N);
    while (N--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string token;
        ss >> token;
        if (token == "NEXT") {
            if (!blue.empty()) {
                sort(blue.begin(), blue.end());
                printf("BLUE %d\n", blue[0]);
                blue.erase(blue.begin());
                if (pink.size() > 1000) {
                    blue.erase(blue.begin() + 1000, blue.end());
                }
            } else {
                if (!pink.empty()) {
                    sort(pink.begin(), pink.end());
                    printf("PINK %d\n", pink[0]);
                    pink.erase(pink.begin());
                    if (pink.size() > 1000) {
                        pink.erase(pink.begin()+1000, pink.end());
                    }
                } else {
                    sort(green.begin(), green.end());
                    printf("GREEN %d\n", green[0]);
                    green.erase(green.begin());
                    if (green.size() > 1000) {
                        green.erase(green.begin()+1000, green.end());
                    }
                }
            }
        } else {
            ss >> token;
            if (token == "PINK") {
                ss >> token;
                int s = atoi(token.c_str());
                if (find(pink.begin(), pink.end(), s) == pink.end()) {
                    pink.push_back(s);
                }
            } else if (token == "BLUE") {
                ss >> token;
                int s = atoi(token.c_str());
                if (find(blue.begin(), blue.end(), s) == blue.end()) {
                    blue.push_back(s);
                }
            } else if (token == "GREEN") {
                ss >> token;
                int s = atoi(token.c_str());
                if (find(green.begin(), green.end(), s) == green.end()) {
                    green.push_back(s);
                }
            }
        }
    }

    return 0;
}