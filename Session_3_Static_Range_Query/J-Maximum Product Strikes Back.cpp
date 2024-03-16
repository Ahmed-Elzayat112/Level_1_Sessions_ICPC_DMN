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

// Problem Link: https://codeforces.com/contest/1660/problem/D

// Start
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v;

    vector<int> indexOfZeros = {-1};
    for (int i = 0; i < n; ++i)
    {
        if (v[i] == 0)
            indexOfZeros.push_back(i);
    }
    indexOfZeros.push_back(n);

    vector<int> freqOfTow(n + 1);
    for (int i = 0; i < n; ++i)
    {
        if (!i)
            freqOfTow[i] = (abs(v[i]) == 2);
        else
            freqOfTow[i] = freqOfTow[i - 1] + (abs(v[i]) == 2);
    }

    vector<pair<int, int>> ranges;
    for (int i = 1; i < indexOfZeros.size(); ++i)
    {
        int l = indexOfZeros[i - 1] + 1;
        int r = indexOfZeros[i] - 1;
        if (l == r + 1)
            continue;

        int ng = 0;
        for (int j = l; j <= r; ++j)
        {
            ng += (v[j] < 0);
        }

        if (ng % 2 == 0)
            ranges.emplace_back(l, r);
        else
        {
            ng = 0;
            for (int j = l; j <= r; ++j)
            {
                ng += (v[j] < 0);
                if (ng % 2 == 0)
                    ranges.emplace_back(l, j);
            }

            ng = 0;
            for (int j = r; j >= l; --j)
            {
                ng += (v[j] < 0);
                if (ng % 2 == 0)
                    ranges.emplace_back(j, r);
            }
        }
    }

    if (ranges.empty())
    {
        cout << "0 " << n;
        return;
    }

    int mx = INT_MIN, left, right;
    for (auto &[l, r] : ranges)
    {
        if (mx < freqOfTow[r] - freqOfTow[l] + (abs(v[l]) == 2))
        {
            mx = freqOfTow[r] - freqOfTow[l] + (abs(v[l]) == 2);
            left = l, right = n - r - 1;
        }
    }
    cout << left << " " << right;
}

int main()
{
    //setIO("Bumble");
    Ahmed();
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve();
        //	cout << "Case " << tc << ": " << ans;
        cout << "\n";
    }
    return 0;
}
