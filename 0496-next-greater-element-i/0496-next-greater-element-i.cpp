class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> nextGreater;
        for(int num:nums2){
            while(!st.empty() && st.top()<num){
                nextGreater[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        vector<int> result;
        for(int num:nums1){
            if(nextGreater.find(num)!=nextGreater.end()){
                result.push_back(nextGreater[num]);
            }
            else{
                result.push_back(-1);
            }
        }
        return result;
    }
};