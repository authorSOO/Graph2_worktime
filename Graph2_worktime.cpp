#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
	int n;
	cin>>n;
	int work[10001];
	vector<int> a[10001];
	int cnt[10001];
	int d[10001];
	memset(d,0,sizeof(d));
	memset(cnt,0,sizeof(cnt));
	
	for(int i=1;i<=n;i++){
		cin>>work[i];
		int m;
		cin>>m;
		for(int j=0;j<m;j++){
			int x;
			cin>>x;
			a[x].push_back(i);
			cnt[i]++;
		}
	}
	queue<int> q;
	
	for(int i=1;i<=n;i++){
		if(cnt[i]==0){
			q.push(i);
			d[i]=work[i];
		}
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=0;i<a[x].size();i++){
			int y = a[x][i];
			cnt[y]--;
			if(d[y]<d[x]+work[y])d[y]=d[x]+work[y];
			if(cnt[y]==0)q.push(y);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(ans<d[i])ans=d[i];
	}
	cout<<ans<<endl;
	return 0;
}
