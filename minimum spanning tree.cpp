#include<bits/stdc++.h>

using namespace std;

int nod,edg,par[1000005];

struct edge {
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};

int find(int r)
{
    if(par[r] == r)
        return r;
    par[r]=find(par[r]);
    return par[r];
}

vector<edge> e;

int mst()
{
    for(int i=1;i<=nod;i++)
        par[i]=i;
    sort(e.begin(),e.end());
    int count = 0,sum = 0;
    for(int i=0;i<edg;i++)
    {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if(u!=v)
        {
            par[u] = v;
            count++;
            sum+=e[i].w;
        }
        if(count == nod-1)
            break;
    }
    return sum;
}

int main()
{

    scanf("%d",&nod);
    scanf("%d",&edg);
    for(int i=1;i<=edg;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edge get;
        get.u=u;
        get.v=v;
        get.w=w;
        e.push_back(get);
    }
    cout<<mst();
    return 0;
}
