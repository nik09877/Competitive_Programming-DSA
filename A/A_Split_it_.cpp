#include <bits/stdc++.h>

#define debug(...) fprintf(stderr ,__VA_ARGS__)
#define __FILE(x)\
	freopen(#x".in" ,"r" ,stdin);\
	freopen(#x".out" ,"w" ,stdout)
#define LL long long

const int MX = 100 + 23;
const LL MOD = 998244353;

int read(){
	char k = getchar(); int x = 0;
	while(k < '0' || k > '9') k = getchar();
	while(k >= '0' && k <= '9') x = x * 10 + k - '0' ,k = getchar();
	return x;
}

char s[MX];
void solve(){
	int n = read() ,k = read();
	scanf("%s" ,s);
	int ok = 1;
	for(int i = 0 ; i < k ; ++i)
		ok = ok && s[i] == s[n - i - 1];
	puts(ok && k * 2 < n ? "YES" : "NO");
}

int main(){
	int T = read();
	for(int i = 1 ; i <= T ; ++i){
		solve();
	}
	return 0;
}