class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        stack<int> st;
        for(int num: nums2){
            while(!st.empty() && st.top() < num){
                map[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        vector<int> result;
        for(int num:nums1){
            result.push_back(map.count(num)?map[num]:-1);

        }
        return result;
    }
};