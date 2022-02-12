/**
 *    problem: UVa 12108 Extraordinarily Tired Students
 *    author: RobinHood3082
**/
#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using pii = pair <int, int>;
using pll = pair <ll, ll>;

#define FIO() ios_base::sync_with_stdio(0);cin.tie(NULL);

int main() {
    FIO();

    int kase = 0;
    while (true) {
        int n; cin >> n;
        if (n == 0) break;

        cout << "Case " << ++kase << ": ";
        int a[n], b[n], c[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }

        vector <int> cur(n);
        bool ok = true;
        for (int i = 0; i < n; i++) {
            cur[i] = c[i];
            if (c[i] > a[i]) ok = false;
        }

        if (ok) {
            cout << 1 << '\n';
            continue;
        }

        int ans = -1;
        int mx = 1e6;
        for (int t = 2; t <= mx; t++) {
            int asleep = 0;
            for (int i = 0; i < n; i++) {
                if (cur[i] > a[i]) asleep++;
            }

            int awake = n - asleep;
            for (int i = 0; i < n; i++) {
                cur[i]++;
                if (cur[i] > a[i] + b[i]) {
                    cur[i] = 1;
                    continue;
                }

                if (cur[i] != 1 + a[i]) continue;

                if (asleep <= awake) cur[i] = 1;
            }

            awake = 0;
            for (int i = 0; i < n; i++) {
                if (cur[i] <= a[i]) awake++;
            }

            if (awake == n) {
                ans = t;
                break;
            }
        }

        cout << ans << '\n';
    }
}
