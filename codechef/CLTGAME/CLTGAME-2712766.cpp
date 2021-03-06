#include<cstdio>
#include<cstdlib>
#include<cstring>
#define INF 1000000001
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)


int dp[1001][1001];
char a[1001][1001];
int calc(int n,int k)
{
    int i,j;
    for(j=0;j<n;j++) dp[n-1][j]=a[n-1][j]-48;
    for(i=n-2;i>=0;i--)
    {
        for(j=0;j<n;j++)
        {
            if(!(i&1)) dp[i][j]=min(min((j>0?dp[i+1][j-1]:INF),(j<n-1?dp[i+1][j+1]:INF)),dp[i+1][j])+a[i][j]-48;
            else dp[i][j]=max(max((j>0?dp[i+1][j-1]:-1),(j<n-1?dp[i+1][j+1]:-1)),dp[i+1][j])+a[i][j]-48;
        }
    }
    int cnt=0;
    for(j=0;j<n;j++) if(dp[0][j]>=k) cnt++;
    return cnt;
}

int main()
{
    int t,n,k,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++) scanf("%s",a[i]);
        printf("%d\n",calc(n,k));
    }
    return 0;
}