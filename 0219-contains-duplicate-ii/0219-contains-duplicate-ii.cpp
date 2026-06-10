#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();++i){
            int curr=nums[i];

            if(mp.count(curr)){
                if(i-mp[curr]<=k){
                return true;
                }
            }
            mp[curr]=i;
        }
        return false;
    }
};