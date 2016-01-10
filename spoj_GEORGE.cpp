#include <iostream>
#include <vector>
#include <set>
#include <limits>
using namespace std;
typedef vector<pair<int,int> > vii;
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define INF numeric_limits<int>::max()

vector<int> places(1000);
vector<int> ttrp[1001][1001]; //time to reach places 
vii graph[1001];
int streets[1001][1001];
int solve(int n,int m,int a,int b,int k,int g){
	set<pair<int,int> > active;
	int minDistance[1001];
	for(int i=0;i<=n;i++){
		minDistance[i]=INF;
	}
	minDistance[a]=k;
	active.insert(make_pair(k,a));
	while(!active.empty()){
		int current=active.begin()->second;
		minDistance[current]=active.begin()->first;
		active.erase(active.begin());
		if(current==b){
			break;
		}
		for(int i=0;i<graph[current].size();i++){
			int to=graph[current][i].first;
			if((ttrp[current][to].empty||minDistance[current]<ttrp[current][to][0])&&(ttrp[to][current].empty()||minDistance[current]<ttrp[to][current][0])){
				if(minDistance[to]>minDistance[current]+streets[current][to]){
					if(minDistance[to]!=INF){
						active.erase(make_pair(minDistance[to],to));
					}
					minDistance[to]=minDistance[current]+streets[current][to];
					active.insert(make_pair(minDistance[to],to));
				}
			}else{
				int stopT=0;
				if(!ttrp[current][to].empty()&&minDistance[current]>=ttrp[current][to][0]&&minDistance[current]<ttrp[current][to][0]+street[current][to]){
					stopT=ttrp[current][to][0]+streets[current][to];
				}else{
					stopT=ttrp[to][current][0]+streetsp[to][current];
				}
				stopT=max(minDistance[current])
			}
		}
	}
	return minDistance[b];
}
//int found[1001];
int main(){
	boost;
	int n,m,a,b,k,g;
	cin>>n>>m>>a>>b>>k>>g;

	for(int i=0;i<g;i++){
		cin>>places[i];
		//if(found[places[i]]) cout<<"yolo"<<places[i]<<endl;
		//found[places[i]]=1;
	}
	for(int i=0;i<m;i++){
		int from ,to,tim;
		cin>>from>>to>>tim;
		graph[from].push_back(make_pair(to,tim));
		graph[to].push_back(make_pair(from,tim));
		streets[from][to]=tim;
		streets[to][from]=tim;
	}
	int time=0;
	for(int i=1;i<g;i++){
		ttrp[places[i-1]][places[i]].push_back(time);
		time+=streets[places[i-1]][places[i]];
	}
	cout<<solve(n,m,a,b,k,g)-k<<endl;
	return 0;
}	