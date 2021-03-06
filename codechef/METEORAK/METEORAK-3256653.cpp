// User: lovelotus

//#include<bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
#define pii pair<int,int>
#define pip pair<int,pair>
#define F first
#define S second
#define lli long long int
using namespace std;

// maximum rectangle in a histogram + dp

int hist[1001][1001], met[1001][1001],area[1001][1001],dp[1001][1001];
// met[i][j] is whether meteor is there at i,j
// hist[i][j] has the histograms formed from the rectangle
// area[i][h] stores the max area of rectangle whose base is at i, and histogram is considered till hieght h
// dp[i][h]  stores the actual solution, ie for histograms with all bases from i to i+h-1 till hieght h
int main()
{
    int i,j,n,m,k,x,y;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<k;i++)
    {
        scanf("%d%d",&x,&y);
        met[x-1][y-1]=1;
    }
    for(j=0;j<m;j++) hist[0][j]=(met[0][j]?0:1);
    for(i=1;i<n;i++)
    {
        for(j=0;j<m;j++) hist[i][j]=(met[i][j]?0:hist[i-1][j]+1);
    }
    for(int k=0;k<n;k++)
    {
        stack<int>s;
        int maxarea=0,artop,i=0;
        int maxh=0;
        while(i<m)
        {
            if(s.empty() || hist[k][s.top()]<=hist[k][i])
            {
                s.push(i++);
            }
            else
            {
                int tp=s.top();
                s.pop();
                if(hist[k][tp]>maxh) maxh=hist[k][tp];
                artop=hist[k][tp]*(s.empty()?i:i-s.top()-1);
                if(area[k][hist[k][tp]]<artop)
                {
                    area[k][hist[k][tp]]=artop;
                }
            }
        }
        while(!s.empty())
        {
            int tp=s.top();
            s.pop();
            if(hist[k][tp]>maxh) maxh=hist[k][tp];
            artop=hist[k][tp]*(s.empty()?i:i-s.top()-1);
            if(area[k][hist[k][tp]]<artop)
            {
                area[k][hist[k][tp]]=artop;
            }
        }
        int maxwidth=0;
        for(int h=maxh;h>0;h--)// height strictly decreasing, so, area[k][h] stores max area of histogram at k for varying max heights
        {
            maxwidth=max(maxwidth,area[k][h]/h);
            area[k][h]=max(area[k][h],h*maxwidth);// h*maxwidth lets us include the heights that are extensible but may be constrained by query boundaries
        }
    }
    int h;
    /*for(i=0;i<n;i++)
    {
        for(h=1;h<=i+1;h++)
        {
            printf("%d ",area[i][h]);
        }
        printf("\n");
    }*/
    for(i=0;i<n;i++)
    {
        dp[i][0]=0;
        for(h=1;h<=i+1;h++)
        {
            int val=max(dp[i][h-1],area[i][h]);
            if(i) val=max(val,dp[i-1][h-1]);
            //printf("val :%d ",val);
            dp[i][h]=val;
        }
    }
    /*for(i=0;i<n;i++)
    {
        for(h=1;h<=i+1;h++) printf("%d ",dp[i][h]); printf("\n");
    }*/
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&x,&y);
        x--;
        y--;
        h=y-x+1;
        printf("%d\n",dp[y][h]);
    }
    return 0;
}