class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> map;
        for(auto & word : words){
            map[word]++;
        }
        vector<string> candidates;
        for(const auto& pair :map){
            candidates.push_back(pair.first);
        }
        sort(candidates.begin(),candidates.end() , [&](const string& a,const string& b){
            if(map[a]==map[b]){
                return a<b;
            }
            return map[a]>map[b];
        });
        return vector<string>(candidates.begin(),candidates.begin()+k);
    }
};