class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        set<string> s1(words.begin(), words.end());
        set<string> s2(words.begin(), words.end());

        for (auto parts : s1)
            for (int i = 1; i < parts.size(); i++)
                s2.erase(parts.substr(i));

        int ans = 0;
        for (string x : s2)
            ans += x.size() + 1;
        return ans;
    }
};