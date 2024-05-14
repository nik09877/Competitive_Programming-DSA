class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        for(int i=n-1-k;i>=0;i--){
            energy[i]+=energy[i+k];
        }
        return *max_element(energy.begin(),energy.end());
    }
};