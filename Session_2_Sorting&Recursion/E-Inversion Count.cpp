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
ll merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right)
{
    ll invCount = 0;
    int l = left, r = mid, k = l;

    while (l < mid && r <= right)
    {
        if (arr[l] <= arr[r])
        {
            temp[k++] = arr[l++];
        }
        else
        {
            temp[k++] = arr[r++];
            invCount += (mid - l);
        }
    }
    while (l < mid)
        temp[k++] = arr[l++];
    while (r <= right)
        temp[k++] = arr[r++];

    for (int i = left; i <= right; ++i)
    {
        arr[i] = temp[i];
    }

    return invCount;
}

ll mergeSort(vector<int> &arr, vector<int> &temp, int left, int right)
{
    int mid;
    ll invCount = 0;
    if (right > left)
    {
        mid = (left + right) / 2;
        invCount += mergeSort(arr, temp, left, mid);
        invCount += mergeSort(arr, temp, mid + 1, right);

        invCount += merge(arr, temp, left, mid + 1, right);
    }

    return invCount;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), temp(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << mergeSort(arr, temp, 0, n - 1);
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
