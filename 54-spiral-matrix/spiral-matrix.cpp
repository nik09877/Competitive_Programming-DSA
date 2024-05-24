class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
       int n = a.size(), m = a[0].size();
       int left = 0, right = m-1, top = 0, bottom = n-1;
       vector<int> order;
       while(left<= right and top <= bottom){
            for(int i=0;i<4;i++){
                if(i==0){if(top>bottom or left>right)
                break;
                    for(int k=left;k<=right;k++)
                        order.push_back(a[top][k]);
                    top++;
                    if(top>bottom or left>right)
                break;
                }
                else if(i==1){if(top>bottom or left>right)
                break;
                    for(int k=top;k<=bottom;k++){
                        order.push_back(a[k][right]);
                    }
                    right--;
                    
                }
                else if(i==2){if(top>bottom or left>right)
                break;
                    for(int k=right;k>=left;k--)
                        order.push_back(a[bottom][k]);
                    bottom--;
                    
                }
                else{if(top>bottom or left>right)
                break;
                    for(int k=bottom;k>=top;k--){
                        order.push_back(a[k][left]);
                    }
                    left++;
                    
                }
            }
       }
       return order; 
    }
};