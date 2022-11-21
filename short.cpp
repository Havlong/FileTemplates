#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#include <map>

using namespace std;

template<typename T> void read(T &x) { cin >> x; }
template<typename T, typename... Types>
void read(T &x, Types &... rest) { cin >> x; read(rest...); }
#define int long long
#define make(t, ...) t __VA_ARGS__; read(__VA_ARGS__)

const int M7 = 1000000007;
const int INF = (M7 * M7);

void solve() {
    make(int, a, b);
    cout << a + b << endl;
}

int32_t main(signed argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (argc > 1 && (string) argv[1] == "local") {
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);

        solve();
        while (cin.peek() != EOF) {
            if (isspace(cin.peek())) {
                cin.get();
            } else {
                cout << "\n\n";
                solve();
            }
        }
    } else {
        solve();
    }
}
