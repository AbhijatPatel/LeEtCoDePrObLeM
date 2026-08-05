class Solution {
public:
    string frequencySort(string s){
    map<char,int> freq;
    for(auto ch : s)
    freq[ch]++;

    vector<vector<char>> bucketData(s.length()+1);
    for(auto it : freq) {
    char ch = it.first;
    int freq = it.second;

    bucketData[freq].push_back(ch);
}
    string ans ="";
    for(int fq=s.length();fq>=1;fq--){
        for(auto ch : bucketData[fq])
        ans.append(fq,ch);
    }
    return ans;
}
};