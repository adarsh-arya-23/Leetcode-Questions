#include<iostream>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {
        string news = s;

        if(s.length() != goal.length()){
            return false;
        }
        if(s == goal){
            return true;
        }

        int nex = 1;
        while(s != goal && nex < s.length()){
            s = news;
            int n2 = s.length() - nex;
            for(int i = 0; i < nex/2; i++){
                swap(s[i], s[nex-i-1]);
            }
            for(int i = 0 ; i < n2/2 ; i++){
                swap(s[nex+i], s[s.length()-i-1]);
            }
            for(int i = 0 ; i < s.length()/2 ; i++){
                swap(s[i], s[s.length()-i-1]);
            }
            nex++;
            if(s == goal){
                return true;
            }
        }
        return false;
    }
};
int main(){
    Solution s;
    if(s.rotateString("adarsh" , "haadrs")){
        cout<<"Yes String Matched The Goal"<<endl;
    }
    else{
        cout<<"No String Don't Matched The Goal"<<endl;
    }
}