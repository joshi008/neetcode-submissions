class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        map<int, vector<int>> mm;

        int i,j;

        for(i=0;i<nums.size();i++) {
            m[nums[i]]++;
        }

        for(auto it = m.begin(); it!=m.end(); it++) {
            mm[it->second].push_back(it->first);
        }
        vector<int> ans;
        for(auto it1 = mm.rbegin(); it1!=mm.rend(); it1++) {
            if(ans.size()==k) {
                break;
            }
            for(i=0;i<it1->second.size();i++) {
                ans.push_back(it1->second[i]);

                if(ans.size()==k) {
                    break;
                }
            }
        }

        return ans;
    }
};
