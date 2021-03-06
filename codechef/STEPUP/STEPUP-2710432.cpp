#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>v[10005];
int visited[10010],in[10010];
int maxm=0,f=0;

void dfs(int i,int d)
{
    if(visited[i]) {f=1;return;}
    visited[i]=1;
    vector<int>::iterator it;
    for(it=v[i].begin();it!=v[i].end();it++)
    {
        dfs((*it),d+1);
        if(f) return;
    }
    visited[i]=0;
    if(d>maxm) maxm=d;
}

int main()
{
    int t,i,nv,cnt,ne,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&nv,&ne);
        for(i=1;i<=nv;i++) {v[i].clear(); in[i]=0;}
        while(ne--)
        {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            in[y]++;
        }
        maxm=cnt=0;
        for(i=1;i<=nv;i++)
        {
            if(!in[i])
            {
                cnt++;
                f=0;
                fill(visited,visited+ne+2,0);
               // printf("dfs %d\n",i);
                dfs(i,1);
            }
            if(f) break;
        }
        if(f || (!cnt)) printf("IMPOSSIBLE\n");
        else printf("%d\n",maxm);
    }
    return 0;
}