#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        int carac[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            carac[s[i] - 97]++;
            carac[t[i] - 97]--;
        }

        for (int i : s) {
            if (carac[i - 97] != 0)
                return false;
        }

        return true;
    }
};

int main() {
    Solution s;
    cout << boolalpha;
    cout << s.isAnagram("anagram", "nagaram")  << '\n';
    cout << s.isAnagram("rat", "car") ;

    return 0;
}
