class Solution {
public:
    string reverseWords(string s) {

    vector<string> words;
    string temp = "";

    for(char ch : s){

        if(ch == ' '){

            if(temp != ""){
                words.push_back(temp);
                temp = "";
            }
        }
        else{
            temp += ch;
        }
    }

    if(temp != "")
        words.push_back(temp);

    string ans = "";

    for(int i = words.size()-1; i >= 0; i--){

        ans += words[i];

        if(i != 0)
            ans += " ";
    }

    return ans;
}
};