#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string res = "";

    for (auto e : s) {
        if (!s.empty() && res.back() == e) {
            res.pop_back();
            continue; 
        } 
        res.push_back(e);
    }

    cout << (res.empty() ? "Empty String" : res) << endl;

}