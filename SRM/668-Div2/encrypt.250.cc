include <vector>
#include <string>
using namespace std;

class VerySecureEncryption
{
    public:
        string encrypt(string s, vector<int> v, int t) {
            string tmp;
            tmp.assign(s);
            for (int j = 0; j < t; ++j) {
                for (int i = 0; i < s.length(); ++i) {
                    tmp[v[i]] = s[i];
                }
                s.assign(tmp);
            }
            return s;
        }

};

