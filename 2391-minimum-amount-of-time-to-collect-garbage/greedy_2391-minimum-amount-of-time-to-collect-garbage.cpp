class Solution {
public:
    int garbageCollection(vector<string>& a, vector<int>& cost) {
        int n = a.size();
        int g_pos=-1,p_pos=-1,m_pos=-1;
        for(int i=n-1;i>=0;i--){
            auto pos = a[i].find('G');
            if(pos!=string::npos){
                g_pos = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            auto pos = a[i].find('P');
            if(pos!=string::npos){
                p_pos = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            auto pos = a[i].find('M');
            if(pos!=string::npos){
                m_pos = i;
                break;
            }
        }
        
        int ans=0;
        for(int i=0;i<g_pos;i++)
            ans+=cost[i];
        for(int i=0;i<p_pos;i++)
            ans+=cost[i];
        for(int i=0;i<m_pos;i++)
            ans+=cost[i];
        int cnt_g(0),cnt_p(0),cnt_m(0);
        for(int i=0;i<n;i++){
            cnt_g+=count(a[i].begin(),a[i].end(),'G');
            cnt_p+=count(a[i].begin(),a[i].end(),'P');
            cnt_m+=count(a[i].begin(),a[i].end(),'M');
        }
        ans+=cnt_g+cnt_p+cnt_m;
        return ans;
    }
};