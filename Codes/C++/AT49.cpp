#include<bits/stdc++.h>
using namespace std;

int N;
char S[1005];

int replace(int N,char *S)
{
	int ans=4;
	for(int i=0;i<16;i++){
		int pos=0,j=0,k=0;
		while(j<4&&k<N)
		{
			pos+=i>>j&1;
			if(i>>j&1)
				k=find(S+k,S+N,"IJPC"[j])-S;
			if(k==N)
				break;
			j++;k++;
		}
		if(j==4)
			ans=min(ans,4-pos);
	}
	return ans;
}
signed main()
{
	scanf("%d",&N);
	cin>>S;
	printf("%d\n",replace(N,S));
	return 0;
}