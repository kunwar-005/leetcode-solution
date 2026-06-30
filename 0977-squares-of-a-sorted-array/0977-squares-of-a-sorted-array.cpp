class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        for(int x: nums){
            if(x<0){
                neg.push_back(x);
            }
            else{
                pos.push_back(x);
            }
        }
        if(pos.size()==0){ //when all the elements in the og array are negative 

        for(int &x:neg ){
            x=x*x;
        }
        reverse(neg.begin(),neg.end());
        return neg;
        }
        else if (neg.size()==0){
            for(int &x: pos){
                x=x*x;
            }
            return pos;
        }
        else{
            int i= 0 ;
            int j=0;
            int n= pos.size();
            int m=neg.size(); 
            vector<int>result;
            for(int &x:neg){
                x=x*x;
            }
            reverse(neg.begin(),neg.end());

            for(int &x : pos){
                x=x*x;
            }
            while(i<n and j<m){
                if(pos[i]<neg[j]){
                    result.push_back(pos[i]);
                    i++;
                }
                else{
                    result.push_back(neg[j]);
                    j++;
                }
            }
            while(i<n){ //when j has iterated over all the elements of its respective array but still some elemts are left int the positice array 

            result.push_back(pos[i]);
            i++;
            }
            while(j<m){
                result.push_back(neg[j]);
                j++;
            }

        return result;
        }
    }
};


/*   this way we can solce this pro in o(1) space complexity (if we don't count the output as extra space) ear;ier we created two ectra arrays pos and neg to sepsrate the neg and poitive numbers but now be are comparing and storing the results in only one result array


How do we avoid pos and neg?

Notice something about the original array.

Example:

nums = [-7,-3,2,3,11]

The largest square will always come from one of the ends.

Why?

Because the largest absolute value is always at either end of a sorted array.

Example:

-7  -3   2   3   11
 ↑                  ↑
49                 121

The middle numbers can never have the largest square.


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        vector<int> ans(nums.size());

        int k = nums.size() - 1;

        while (left <= right) {

            if (abs(nums[left]) > abs(nums[right])) {
                ans[k] = nums[left] * nums[left];
                left++;
            }
            else {
                ans[k] = nums[right] * nums[right];
                right--;
            }

            k--;
        }

        return ans;
    }
};
*/