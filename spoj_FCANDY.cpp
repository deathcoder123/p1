#include <iostream>
#include <vector> 
using namespace std;
inline int abs(int a){return ((a>=0)?a:(-a)) ;}
typedef vector<pair<int,int> > vii;
vii candy;
int dp[101][50001]={0};
int solve(int n,int maxV){
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=maxV;j>=0;j--){
			if(dp[i-1][j]==1){
				int amount = candy[i-1].second, calorie=candy[i-1].first;
				for(int k=(amount%2)*calorie;k<=amount*calorie;k+=2*calorie){
					if(j+k>maxV){
						break;
					}
					if(dp[i-1][j+k]==1){
						dp[i][j+k]=1;
						break;
					}
					//cout<<i<<"  +"<<j<<" "<<j+k<<endl;
					dp[i][j+k]=1;
				}
				for(int k=(amount%2)*calorie;k<=amount*calorie;k+=2*calorie){
					if(abs(j-k)>maxV){
						break;
					}
					if(dp[i-1][abs(j-k)]==1){
						dp[i][abs(j-k)]=1;
						break;
					}
					//cout<<i<<" -"<<j<<" "<<abs(j-k)<<endl;
					dp[i][abs(j-k)]=1;
				}
			}
		}
	}
	int ans=5;
	for(int i=0;i<=maxV;i++){
		if(dp[n][i]==1){

			ans=i;
			break;
		}
	}
	return ans;
}
int main(){
	int n,k,c,maxV=-1;
	cin>>n;
	for(int i=0;i<n;i++){
		int amount,calorie;
		cin>>amount>>calorie;
		maxV=max(maxV,calorie);
		candy.push_back(make_pair(calorie,amount));
	}
	//cout<<abs(-maxV)<<abs(maxV)<<endl;
	cout<<solve(n,205)<<endl;
	return 0;
}