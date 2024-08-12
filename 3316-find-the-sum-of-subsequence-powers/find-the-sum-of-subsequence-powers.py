class Solution:
    def sumOfPowers(self, nums: List[int], k: int) -> int:
        n = len(nums)
        dp = {}
        
        def solve(idx,last,need,valid,diff):
            if n-idx <need: 
                return 0
            if need == 0:
                return valid
            if idx>=n: 
                return 0 
            
            if (idx,last,valid,need) in dp: 
                return dp[(idx,last,valid,need)]

            
            ans = 0
            ans += solve(idx+1,last,need,valid,diff)
            if last == -1: 
                ans += solve(idx+1,idx,need-1,valid,diff)
    
            elif nums[idx]-nums[last]==diff:
                ans += solve(idx+1,idx,need-1,1,diff)
                
            elif nums[idx]-nums[last]>diff: 
                ans += solve(idx+1,idx,need-1,valid,diff)

            dp[(idx,last,valid,need)] = ans
            return ans
        
        ans = 0        
        mod = 10**9 + 7
        nums.sort()
        st = set()
        for i in range(n):
            for j in range(i+1,n):
                diff = nums[j]-nums[i]
                if diff in st: 
                    continue 
                    
                st.add(diff)
                dp.clear()
                c = solve(0,-1,k,0,diff)
                ans+=diff*c
                ans%=mod
            
                
        return ans