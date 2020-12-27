// 1번째 방법 (브루트 포스) O(n^2) 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        for(int i=0; i<nums.size(); i++) {
            for(int j = i+1; j<nums.size(); j++) {
                if(i != j && nums[i]+nums[j] == target) {
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
                }
            }
        }
        return answer;
    }
};

// 2번째 방법 (map) O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prevMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            
            if(prevMap.count(diff)) 
                return { prevMap[diff], i };
            prevMap[nums[i]] = i;
        }
        return {};
    }
};
