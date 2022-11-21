#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <utility>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <functional>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <bitset>
#include <chrono>
#include <random>
#include <complex>
#include <regex>
#include <valarray>

using namespace std;

#define int long long
#define double long double

//region TEMPLATE
//@formatter:off
template<typename T> void read(T &x) { cin >> x; }
template<typename T, typename ... Ts> void read(T &x, Ts &... rest) { cin >> x; read(rest...); }
template<typename Iterator>
string join(Iterator b, Iterator e, const string &sep = " ", const string &pref = "", const string &post = "") {
    stringstream builder;
    builder << pref;
    if (b != e) {
        Iterator it = b;
        builder << *it;
        for (++it; it != e; ++it) {
            builder << sep << *it;
        }
    }
    builder << post;
    return builder.str();
}
template<typename T>
string join(initializer_list<T> list, const string &sep = " ", const string &pref = "", const string &post = "")
{ return join(list.begin(), list.end(), sep, pref, post); }
#define make(t, ...) t __VA_ARGS__; read(__VA_ARGS__)
const int E5 = 100000, E6 = 10 * E5, E7 = 10 * E6, E8 = 10 * E7, E9 = 10 * E8;
const int M7 = E9 + 7, M9 = E9 + 9, MFFT = 998244353;
auto &Instant = chrono::steady_clock::now;
#define Date Instant().time_since_epoch
#define seconds(time) chrono::duration_cast<chrono::seconds>(time).count()
#define millis(time) chrono::duration_cast<chrono::milliseconds>(time).count()
mt19937_64 rnd(static_cast<unsigned>(millis(Date())));
long long callMeasuring(const function<void()> &block) { auto before = Instant(); block(); return millis(Instant() - before); }
//@formatter:on
//endregion

const int INF = (M7 * M7);

void solve() {
    make(int, a, b, c);
    cout << join({a, b, c}, "+") << " = " << a + b + c << "\n";
}

int32_t main(signed argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (argc > 1 && (string) argv[1] == "local") {
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);

        int time = callMeasuring(::solve);
        cout << '\n' << time << " ms";
        while (cin.peek() != EOF) {
            if (isspace(cin.peek())) {
                cin.get();
            } else {
                cout << "\n\n";
                time = callMeasuring(::solve);
                cout << '\n' << time << " ms";
            }
        }
    } else {
        solve();
    }
}
