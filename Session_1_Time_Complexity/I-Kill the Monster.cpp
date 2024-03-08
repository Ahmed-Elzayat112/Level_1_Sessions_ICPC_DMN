#include <bits/stdc++.h>

using namespace std;

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
ll MOD = 1e9 + 7;
const int maxn = 1e6 + 5;

// start from here
void solve()
{
    ll hc, dc, hm, dm, k, w, a;
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;

    for (int i = 0; i <= k; i++)
    {
        ll incH = hc + (i * a);
        ll incA = dc + ((k - i) * w);

        ll monhealth = ceil(ld(hm) / ld(incA));
        ll myhealth = ceil(ld(incH) / ld(dm));

        if (monhealth <= myhealth)
        {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
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
        //		cout << "Case " << tc << ": " << ans;
        cout << "\n";
    }
    return 0;
}
