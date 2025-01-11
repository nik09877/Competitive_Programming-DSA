class Solution {
public:
    unordered_map<int,int>par;
    int islands;
    int find(int x){
        if(par.find(x)==par.end())
            par[x] = x,islands++;
        if(par[x]==x)
            return x;
        return par[x]=find(par[x]);
    }
    void uni(int a,int b){
        a = find(a);
        b = find(b);
        if(a!=b)
            par[b] = a,islands--;
    }
    int removeStones(vector<vector<int>>& stones) {
        islands=0;
        for(int i=0;i<stones.size();i++){
            uni(stones[i][0],~stones[i][1]);
        }
        return stones.size()-islands;
    }
};