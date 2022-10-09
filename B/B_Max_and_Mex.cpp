#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ch() getchar()
#define pc(x) putchar(x)
using namespace std;
template<typename T>void read(T&x){
	static char c;static int f;
	for(c=ch(),f=1;c<'0'||c>'9';c=ch())if(c=='-')f=-f;
	for(x=0;c>='0'&&c<='9';c=ch())x=x*10+(c&15);x*=f;
}
template<typename T>void write(T x){
	static char q[65];int cnt=0;
	if(x<0)pc('-'),x=-x;
	q[++cnt]=x%10,x/=10;
	while(x)
		q[++cnt]=x%10,x/=10;
	while(cnt)pc(q[cnt--]+'0');
}
const int maxn=100005;
int vis[maxn],a[maxn];
int main(){
	int T;read(T);
	while(T--){
		int n,k,MEX=0,MAX=0;
		read(n),read(k);
		for(int i=1;i<=n;++i){
			read(a[i]);
			if(a[i]<=n)vis[a[i]]=true;
			MAX=max(MAX,a[i]);
		}
		while(vis[MEX])++MEX;
		for(int i=1;i<=n;++i){
			if(a[i]<=n)vis[a[i]]=false;
		}
		int MCX=(MEX+1+MAX)/2;
		if(MCX>MAX)write(n+k);
		else{
			int ok=false;
			for(int i=1;i<=n;++i)
				ok|=(a[i]==MCX);
			write(n+((k>0)&&!ok));
		}
		pc('\n');
	}
	return 0;
}