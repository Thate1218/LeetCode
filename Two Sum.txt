class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
            m[target-nums[i]] = i;
        for(int i = 0; i < nums.size(); i++){
            unordered_map<int,int>::iterator it = m.find(nums[i]);
            if(it != m.end() && it->second!=i){
                result.push_back(i);
                result.push_back(it->second);
                break;
            }
        }
        return result;
    }
};