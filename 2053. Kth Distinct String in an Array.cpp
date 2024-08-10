class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
    unordered_map<std::string, int> countMap;

    for (const string& a : arr) {
        ++countMap[a];
    }
    for (const string& a : arr) {
        if (countMap[a] == 1 && --k==0){
            return a;
        }
    }
    return "";
    }
};
