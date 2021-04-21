#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7,p=1e9+7; vector<int>v[N];
int t,n,m,k,s[4],f[N],fl[N],len[N]; long long deg[N];
struct edg{int u,v;}ed[N];
inline int read(){
	int num=0; char g=getchar(); while(g<48||57<g) g=getchar();
	while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar(); return num;
}
inline long long pows(long long u,int v){
	if(v<0) return 0;
	long long ans=1; while(v>0) {if(v&1) ans=ans*u%p; v=v>>1,u=u*u%p;} return ans;
}
namespace sub1{
	void main(){
		cout<<m*pows(2,n-2)%p<<endl; return;
	}
}
namespace sub2{
	void main(){
		long long c=m,q=0; c=c*(m-1)/2;
		for(int i=1;i<=n;i++) q=(q+deg[i]*(deg[i]-1)/2); c=(c-q)%p,q%=p;
		cout<<(m*pows(2,n-2)+2*q*pows(2,n-3)+2*c*pows(2,n-4))%p<<endl;
	}
}
namespace sub3{
	inline bool cmp(int a,int b){
		if(deg[a]==deg[b]) return a<b; return deg[a]<deg[b];
	}
	inline int getans(){
		for(int i=1;i<=n;i++) v[i].clear(),len[i]=0; int sum=0;
		for(int i=1;i<=m;i++) v[min(f[ed[i].u],f[ed[i].v])].push_back(max(f[ed[i].u],f[ed[i].v])),len[min(f[ed[i].u],f[ed[i].v])]++;
		for(int i=1;i<=n;i++){
			for(int c=0;c<len[i];c++) fl[v[i][c]]^=1;
			for(int c=0;c<len[i];c++){
				int x=v[i][c];
				for(int d=0;d<len[x];d++) if(fl[v[x][d]]) sum++;
			}
			for(int c=0;c<len[i];c++) fl[v[i][c]]^=1;
		}
		return sum;
	}	
	void main(){
		for(int i=1;i<=n;i++) f[i]=i; sort(f+1,f+n+1,cmp);
		long long c=m,q=0,ch[6]={0,0,0,0,0,0}; ch[4]=m,c=c*(m-1)/2,ch[4]=ch[4]*(m-1)*(m-2)/6;
		for(int i=1;i<=n;i++) q=(q+deg[i]*(deg[i]-1)/2); c=(c-q)%p,q%=p;
		for(int i=1;i<=m;i++) ch[5]=(ch[5]+(deg[ed[i].u]-1)*(deg[ed[i].v]-1))%p;
		for(int i=1;i<=n;i++) ch[3]=(ch[3]+deg[i]*(deg[i]-1)/2*(m-deg[i]))%p;
		for(int i=1;i<=n;i++) ch[2]=(ch[2]+deg[i]*(deg[i]-1)*(deg[i]-2)/6)%p; ch[1]=getans();
		ch[5]=(ch[5]-ch[1]*3)%p;
		ch[3]=(ch[3]-ch[5]*2-ch[1]*3)%p;
		ch[4]=(ch[4]-ch[1]-ch[2]-ch[3]-ch[5])%p;	
		cout<<(m*pows(2,n-2)%p+6*q*pows(2,n-3)%p+6*c*pows(2,n-4)%p+6*ch[1]*pows(2,n-3)%p+6*ch[2]*pows(2,n-4)%p+6*ch[3]*pows(2,n-5)%p+6*ch[4]*pows(2,n-6)%p+6*ch[5]*pows(2,n-4)%p)%p<<endl;
	}
}
int main(){
	s[1]=1,s[2]=4,s[3]=6;
	t=read();
	while(t--){
		n=read(),m=read(),k=read();
		for(int i=1;i<=n;i++) deg[i]=0;
		for(int i=1;i<=m;i++) ed[i].u=read(),ed[i].v=read(),deg[ed[i].u]++,deg[ed[i].v]++;
		if(k==1) sub1::main();
		if(k==2) sub2::main();
		if(k==3) sub3::main();
	}
	return 0;
}