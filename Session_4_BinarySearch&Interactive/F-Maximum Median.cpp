#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << " ";
    return out;
}

template <typename T = int>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void Ahmed()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
#endif
}

using ll = long long;
using ld = long double;
#define INF 1e18
#define all(x) (x).begin(), (x).end()
#define fixed(n) fixed << setprecision(n)
// #define ceil(n , m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define fill(vec, value) memset(vec, value, sizeof(vec));
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define endl '\n'

// Problem Link: https://codeforces.com/contest/1201/problem/C

// Start

ll n, k;

bool can(ll mid, vector<ll> a)
{
    ll curK = k;
    for (int i = n / 2; i < n; ++i)
    {
        if (mid >= a[i])
        {
            curK -= (mid - a[i]);
        }
        if (curK < 0)
            return false;
    }
    return true;
}

void solve()
{
    cin >> n >> k;
    vector<ll> a(n);
    cin >> a;
    sort(all(a));

    ll left = 0, right = 2e12, ans = a[n / 2];
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (can(mid, a))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << ans;
}

int main()
{
    // setIO("Bumble");
    Ahmed();
    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve();
        // cout << "Case " << tc << ": " << ans;
        // cout << "\n";
    }
    return 0;
}
