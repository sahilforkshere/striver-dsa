class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        for(int i=0;i<arr.size();i++){
            int start= arr[i][0];
            int end=arr[i][1];
            if(!ans.empty() && end<=ans.back()[1]){
                continue;
            }

            for(int j=i+1;j<arr.size();j++){
                if(arr[j][0]<=end){
                    end=max(arr[j][1],end);
                }

                else{
                    break;
                }
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};