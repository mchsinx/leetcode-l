#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rst;
        for(int i = 0, j; i < nums.size(); ++i) {
            for(j = i + 1; j < nums.size() && nums[j] != (target - nums[i]); ++j);
            if(j != nums.size()) {
                rst.push_back(i);
                rst.push_back(j);
                break;
            }
        }
        return rst;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {3, 2, 4};
    vector<int> rstt = rstt = sol.twoSum(vec, 6);
    for(unsigned i=0;i<rstt.size();++i) {
        cout << rstt[i] << endl;
    }
    std::cout << "dadf" << std::endl;
    return 0;
}
