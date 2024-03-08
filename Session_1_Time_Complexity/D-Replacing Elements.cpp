#include<bits/stdc++.h>

using namespace std;


void setIO(string s) {
	freopen(( s + ".in" ).c_str() , "r" , stdin);
	freopen(( s + ".out" ).c_str() , "w" , stdout);
}

void Ahmed() {
	ios_base::sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("in.txt" , "r" , stdin) , freopen("out.txt" , "w" , stdout);
#endif
}


using ll = long long;
using ld = long double;
#define INF 1e18
#define all(x) (x).begin(), (x).end()
#define fixed(n) fixed << setprecision(n)
//#define ceil(n , m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define fill(vec , value) memset(vec, value, sizeof(vec));
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define endl '\n'
ll MOD = 1e9 + 7;
const int maxn = 1e6 + 5;


// start from here
void solve() {
	int n,d;
	cin>>n>>d;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
	sort(all(v)); // all() is defined above
	int c=0;
	for(auto i:v){
		if(i>d) c=1;
	}
	if(v[0]+v[1]<=d || c==0) cout<<"YES";
	else cout<<"NO";
}


int main() {
//	setIO("Bumble");
	Ahmed();
	int t = 1;
	cin >> t;
	for ( int tc = 1 ; tc <= t ; tc++ ) {
		solve();
//		cout << "Case " << tc << ": " << ans;
		cout << "\n";
	}
	return 0;
}

