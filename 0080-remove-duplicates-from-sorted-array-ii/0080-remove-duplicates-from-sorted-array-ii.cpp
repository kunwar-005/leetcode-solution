class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int i = 0;
        int j = 1;
        int unique = 1;
        while (j < nums.size()) {
            if (k == 0) {
                if (nums[j] == nums[j - 1]) {
                    nums[i + 1] = nums[j];
                    k = 1;
                    i++;
                    j++;
                } else {
                    nums[i + 1] = nums[j];
                    i++;
                    j++;
                    unique++;
                }

            } else if (k == 1) {
                if (nums[j] == nums[j - 1]) {
                    j++;
                } else {
                    nums[i + 1] = nums[j];
                    k = 0;
                    unique++;
                    i++;
                    j++;
                }
            }
        }

        return i + 1;
    }
};

/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() <= 2)
            return nums.size();

        int i = 2;

        for (int j = 2; j < nums.size(); j++) {

            if (nums[j] != nums[i - 2]) {
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};*/