#include<bits/stdc++.h>

using namespace std;

int x[1000000],a[1000][1000],node,edge,m;

bool istrue(int k,int c)
{
    for(int i=0;i<node;i++)
    {
        if(a[k][i]==1 and x[i]==c)
            return false;
    }
    return true;
}

void graphcolor(int k)
{
    if(k==node)
        return;
    for(int c=1;c<=m;c++)
    {
        if(istrue(k,c))
        {
            x[k]=c;
            graphcolor(k+1);
        }
    }
}

int main()
{
    int node,edge,source;
    cin>>node>>edge>>m>>source;
    for(int i=0;i<=node;i++)
    {
        for(int j=0;j<=node;j++)
        {
            a[i][j]=0;
        }
    }
    for(int i=0;i<edge;i++)
    {
        int b,c;
        cin>>b>>c;
        a[b][c]=1;
        a[c][b]=1;
        a[b][b]=1;
        a[c][c]=1;
    }
    graphcolor(source);
    for(int i=0;i<node;i++)
    {
        if(x[i]==1)
        {
            cout<<i<<" = red"<<endl;
        }
        else if(x[i]==2)
        {
            cout<<i<<" = green"<<endl;
        }
        else if(x[i]==3)
        {
            cout<<i<<" = blue"<<endl;
        }
    }
    return 0;
}
