#include<stdio.h>
#include<stdlib.h>
int ks[2][2000001];
int val[501],wt[501];

inline void rd(int *a)
{
 register char c=0;
 while (c<33) c=getchar_unlocked();
 *a=0;
 while (c>33)
 {
     *a=*a*10+c-'0';
     c=getchar_unlocked();
 }
}


int main()
{
    int k,n,i,j;
    rd(&k);
    rd(&n);
    //scanf("%d %d",&k,&n);
    for(i=0;i<n;i++)
    {
        rd(&val[i]);
        rd(&wt[i]);
    }
    //scanf("%d %d",&val[i],&wt[i]);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            //if(i==0 || j==0) ks[i&1][j]=0;
            if(wt[i-1]<j)
            {
                int x=ks[!(i&1)][j];
                int y=val[i-1]+ks[!(i&1)][j-wt[i-1]];
                if(x>y) ks[i&1][j]=x;
                else ks[i&1][j]=y;
            }
            else ks[i&1][j]=ks[!(i&1)][j];
        }
    }
    printf("%d\n",ks[(n&1)][k]);
    return 0;
}
