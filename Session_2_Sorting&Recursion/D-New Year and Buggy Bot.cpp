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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> maze(n + 5, vector<char>(m + 5));

    vector<pair<int, int>> dir{{0, 1},
                               {0, -1},
                               {1, 0},
                               {-1, 0}};

    int x, y;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'S')
                x = i, y = j;
        }
    }
    string s;
    cin >> s;

    int ans = 0;
    sort(dir.begin(), dir.end());
    do
    {
        int sx = x, sy = y;
        bool valid = false;
        for (int i = 0; i < s.size(); ++i)
        {
            int k = s[i] - '0';
            sx += dir[k].first;
            sy += dir[k].second;

            if (sx >= n || sy >= m || sx < 0 || sy < 0 || maze[sx][sy] == '#')
                break;
            if (maze[sx][sy] == 'E')
            {
                valid = true;
                break;
            }
        }
        if (valid)
            ans++;
    } while (next_permutation(dir.begin(), dir.end()));

    cout << ans;
}

int main()
{
    //	setIO("Bumble");
    Ahmed();
    int t = 1;
    //	cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve();
        //		cout << "Case " << tc << ": " << ans;
        cout << "\n";
    }
    return 0;
}
