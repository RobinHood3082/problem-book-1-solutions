/**
 *    problem: UVa 253 Cube painting
 *    author: RobinHood3082
**/
#include <bits/stdc++.h>

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using pii = pair <int, int>;
using pll = pair <ll, ll>;

#define FIO() ios_base::sync_with_stdio(0);cin.tie(NULL);

void rotate_h(string& s) {
    char c = s[2];
    s[2] = s[4];
    s[4] = s[3];
    s[3] = s[1];
    s[1] = c;
}

void rotate_v(string& s) {
    char c = s[0];
    s[0] = s[3];
    s[3] = s[5];
    s[5] = s[2];
    s[2] = c;
}

void rotate_a(string& s) {
    char c = s[1];
    s[1] = s[5];
    s[5] = s[4];
    s[4] = s[0];
    s[0] = c;
}

int main() {
    FIO();

    string s;
    while (cin >> s) {
        string s1 = s.substr(0, 6), s2 = s.substr(6, 6);

        bool ok = false;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {

                    string t = s1;
                    int p = i;
                    while (p--) rotate_h(t);

                    p = j;
                    while (p--) rotate_v(t);

                    p = k;
                    while (p--) rotate_a(t);

                    if (t == s2) {
                        ok = true;
                        break;
                    }
                }

                if (ok) break;
            }

            if (ok) break;
        }

        if (ok) cout << "TRUE\n";
        else cout << "FALSE\n";
    }
}
