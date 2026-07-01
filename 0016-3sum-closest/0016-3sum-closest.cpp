class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int res_sum=0;
        int min_diff=INT_MAX;
        for (int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;

            while(j<k){
                int total=nums[i]+nums[j]+nums[k];
                int d = abs(total-target);
                if(min_diff>d){
                    min_diff=d;
                    res_sum=total;
                }
                if(target == total){
                    
                    return res_sum;
                }
                else if(total<target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return res_sum;
    }
};