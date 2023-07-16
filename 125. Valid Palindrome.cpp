#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        size_t izq = 0, der = s.size() - 1;
        char ci, cd;
        while (der > izq)
        {
            ci = ('A' <= s[izq] && s[izq] <= 'Z') ? s[izq] + 32 : s[izq];
            cd = ('A' <= s[der] && s[der] <= 'Z') ? s[der] + 32 : s[der];
            if (ci < '0' || (ci > '9' && ci < 'a') || ci > 'z')
            {
                izq++;
                continue;
            }
            if (cd < '0' || (cd > '9' && cd < 'a') || cd > 'z')
            {
                der--;
                continue;
            }
            if (ci != cd)
                return false;
            izq++;
            der--;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "";
    bool res = sol.isPalindrome(s);
    cout << boolalpha << res;
    fflush(stdin); // Borrar
    getchar();     // Borrar
    return 0;
}
