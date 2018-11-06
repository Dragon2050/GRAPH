#include<bits/stdc++.h>

using namespace std;

int node,edge,par[1000005];

int find(int r)
{
    if(par[r] == r)
        return r;
    par[r]=find(par[r]);
    return par[r];
}

int main()
{

    scanf("%d",&node);///number of node.
    scanf("%d",&edge);///number of edge.
    for(int i=1;i<=node;i++)
    {
        par[i]=i;
    }
    for(int i=1;i<=edge;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        int a=find(u);
        int b=find(v);
        if(a==b)
            ;
        else
            par[b]=par[a];
    }
    int cnt = 0;
    for(int i=1;i<=node;i++)
    {
        if(par[i]==i)
            cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
