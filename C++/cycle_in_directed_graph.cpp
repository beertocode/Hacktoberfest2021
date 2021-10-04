int Find(vector<int> &parent, int i)
{

    if(parent[i]==-1)
    return i;
    return Find(parent,parent[i]);

}

void Union(vector<int> &parent,int x,int y)
{
    int xset = Find(parent,y);
    int yset = Find(parent,x);
    parent[yset] = xset;
}

int Solution::solve(int a, vector<vector<int> > &b) {
    vector<int> parent(a+1,-1);
    for(int i=0;i<b.size();i++)
    {
        int x = Find(parent,b[i][0]);
        int y = Find(parent,b[i][1]);
        if(x==y)
        return 1;
        Union(parent, x, y);
    }
    return 0;
}

