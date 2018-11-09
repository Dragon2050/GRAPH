#include<bits/stdc++.h>

using namespace std;

int node,edg,par[1000005];

struct edge
{
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};

vector<edge> e,p;
vector<int> vec;

int find(int r)
{
    if(par[r] == r)
        return r;
    par[r] = find(par[r]);
    return par[r];
}

int mst()
{
    for(int i=1;i<=node;i++)
        par[i]=i;
    sort(e.begin(),e.end());
    int sum = 0, count   = 0;
    for(int i=0;i<edg;i++)
    {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if(u!=v)
        {
            p.push_back(e[i]);
            par[u] = v;
            count++;
            sum+=e[i].w;
            if(count == node-1)
                break;
        }
    }
    return sum;
}

void allmst()
{
    for(int i=0;i<node-1;i++)
    {
        int sum = 0,count = 0;
        for(int j=1;j<=node;j++)
            par[j] = j;
        for(int j=0;j<edg;j++)
        {
             if(p[i].u == e[j].u and p[i].v == e[j].v and p[i].w == e[j].w)
                ;
            else
            {
                int u = find(e[j].u);
                int v = find(e[j].v);
                if(u!=v)
                {
                    par[u] = v;
                    count++;
                    sum+=e[j].w;
                    if(count == node-1)
                        break;
                }
            }
        }
        if(count == node-1)
        {
            vec.push_back(sum);
        }
    }
}

int main()
{
    scanf("%d%d",&node,&edg);
    for(int i=0;i<edg;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edge get;
        get.u=u;
        get.v=v;
        get.w=w;
        e.push_back(get);
    }
    ///print all the spanning tree.
    cout<<mst()<<" ";
    allmst();
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    return 0;
}
