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

// Problem Link: https://codeforces.com/contest/1473/problem/D

// Start
void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> pref(n + 1), prefMx(n + 1), prefxMn(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        pref[i] += pref[i - 1] + (s[i - 1] == '-' ? -1 : 1);
        prefMx[i] = max(pref[i], prefMx[i - 1]);
        prefxMn[i] = min(pref[i], prefxMn[i - 1]);
    }

    vector<int> suffix(n + 1), suffixMx(n + 1), suffixMn(n + 1);
    for (int i = n - 1; i >= 0; --i)
    {
        suffix[i] += suffix[i + 1] + (s[i] == '-' ? -1 : 1);
        suffixMx[i] = max(0, suffixMx[i + 1] + (s[i] == '-' ? -1 : 1));
        suffixMn[i] = min(0, suffixMn[i + 1] + (s[i] == '-' ? -1 : 1));
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        int mx = max(prefMx[l], pref[l] + suffixMx[r]);
        int mn = min(prefxMn[l], pref[l] + suffixMn[r]);

        cout << mx - mn + 1 << endl;
    }
}

int main()
{
    //	setIO("Bumble");
    Ahmed();
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve();
        //	cout << "Case " << tc << ": " << ans;
        // cout << "\n";
    }
    return 0;
}
