#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define FOR(i, n) for (signed i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define VI vector<int>
#define VII vector<VI>
#define PII pair<int, int>
#define PPII pair<int, PII>
#define make(type, x) type x; cin >> x;
#define makev(x, n) VI x(n); FOR(p, n) cin >> x[p]

void solve() {

}

signed main(signed argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (argc > 1 && (string) argv[1] == "local") {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        solve();
        while (cin.peek() != EOF) {
            if (isspace(cin.peek()))
                cin.get();
            else {
                cout << '\n';
                solve();
            }
        }
    } else {
        solve();
    }
}
