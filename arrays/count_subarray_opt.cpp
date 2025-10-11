class Solution {
public:
    int subarraySum(vector<int>& nums, int tot) {
       int n=nums.size();
       unordered_map<int,int> map;
       map[0]=1;
       int prefixSum=0;
       int count=0;
       for(int i=0;i<n;i++){
        prefixSum+=nums[i];
        int remain=prefixSum-tot;
          count+=map[remain];
          map[prefixSum]++;
       }
       return count;
    }
};