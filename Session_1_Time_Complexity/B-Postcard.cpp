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
	string s;
	cin >> s;
	int k;
	cin >> k;
 
	int q = 0 , star = 0 , sz = s.size();
	for ( auto i : s ) {
		if ( i == '*' ) star++;
		if ( i == '?' ) q++;
	}
 
	int remain = sz - q - star;
	if ( remain == k ) {
		for ( int i = 0 ; i < sz ; ++i ) {
			if ( s[i] != '*' && s[i] != '?' ) cout << s[i];
		}
		return;
	}
 
	if ( remain > k ) {
		int need = remain - k;
		if ( q + star < need ) cout << "Impossible";
		else {
			for ( int i = 0 ; i < sz ; ++i ) {
				if ( i < sz - 1 && s[i] != '*' && s[i] != '?' && need && ( s[i + 1] == '*' || s[i + 1] == '?' )) {
					need--;
					continue;
				}
				else if ( s[i] != '*' && s[i] != '?' ) cout << s[i];
			}
		}
		return;
	}
 
	if ( remain < k ) {
		if ( !star ) cout << "Impossible";
		else {
			int need = k - remain;
			for ( int i = 0 ; i < sz ; ++i ) {
				if(i < sz - 1 && s[i] != '*' && s[i] != '?' && s[i+1]=='*'){
					while (need){
						cout<<s[i];
						need--;
					}
				}
				if(s[i] != '*' && s[i] != '?') cout<<s[i];
			}
		}
	}
}


int main() {
//	setIO("Bumble");
	Ahmed();
	int t = 1;
//	cin >> t;
	for ( int tc = 1 ; tc <= t ; tc++ ) {
		solve();
//		cout << "Case " << tc << ": " << ans;
		cout << "\n";
	}
	return 0;
}

