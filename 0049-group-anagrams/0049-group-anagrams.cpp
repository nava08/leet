class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        
        for (const string& s : strs) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end()); // Key generation
            anagramGroups[sorted_s].push_back(s);  // Grouping
        }
        
        vector<vector<string>> result;
        for (auto& pair : anagramGroups) {
            result.push_back(move(pair.second));
        }
        
        return result;
    }
};