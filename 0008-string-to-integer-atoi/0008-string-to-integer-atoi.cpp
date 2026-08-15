class Solution {
public:
        int fun(string s,int i, int sign, long long num){
    if(i >= s.size() || !isdigit (s[i]))
    return num*sign;

    num = num * 10 + (s[i]-'0');

    if(num*sign > INT_MAX)
    return INT_MAX;

    if(num*sign < INT_MIN)
    return INT_MIN;

    return fun(s,i+1,sign,num);
}
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        while(i < n && s[i] == ' ')
        i++;

        int sign = 1;
        if(i < n && s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(i < n && (s[i] == '+')){
            sign = 1;
            i++;
        }
        return fun(s,i,sign,0);
    }
};