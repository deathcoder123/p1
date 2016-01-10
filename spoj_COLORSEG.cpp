#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include <string>
#include <map>
using namespace std;

#define MOD 1000003
#define INF numeric_limits< int>::max()
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define FOR(i,a) for(int i=0;i<a;i++)
#define mp(a,b) make_pair(a,b)

typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<int> vi;

vi C[110];
int dp[55][55][55][55]; 

int gcd(int a,int b){
	while(b!=0){
		int temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}
void run(){
	for(int i=2;i<=105;i++){
		for(int j=2;j<=i-1;j++){
			if(gcd(i,j)==1){
				C[i].push_back(j);
				C[j].push_back(i);
			}
		}
	}
}
int done[55];
void run2(int m){
	int n=50;
	
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++)
			dp[m-1][1][i][j]=1;
		}
		for(int i=2;i<n;i++){
			for(int j=0;j<m;j++){
				for(int k=0;k<m;k++){
					int current=j+k+2;
					for(int l=0;l<C[current].size();l++){
						//cout<<i<<" "<<j<<" "<<k<<" "<<C[current][l]<<" "<<dp[i-2][C[current][l]-j-2]<<endl;
						if(C[current][l]-k-1>m ) continue;
						if(C[current][l]>k+1) dp[m-1][i][j][k]=(dp[m-1][i][j][k]+dp[m-1][i-1][k][C[current][l]-k-2] )%MOD;
					}
				}
			}
		}
	done[m]=1;
}
int solve(int n,int m){
	int ans=0;
	FOR(i,m) FOR(j,m) ans=(ans+dp[m-1][n-1][i][j])%MOD;
	return ans;
}
int main(){
	boost;
	run();
	int t,n,m,c=0;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int ans;
		if(done[m]){
			ans=solve(n,m);
		}else{
			run2(m);
			ans=solve(n,m);
		}
		cout<<"Case "<<c+1<<": "<<ans<<endl;
		c++;
	}
	return 0;
}
