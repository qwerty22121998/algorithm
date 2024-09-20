#include <vector>
#include <iostream>

using namespace std;

const int MAXH = 1e4 + 1;

typedef long long ll;

class Solution
{
public:
int maxArea(vector<int> &height) {
    ll res0 = maxAreaInt(height);
    reverse(height.begin(), height.end());
    ll res1 = maxAreaInt(height);
    return max(res0, res1);
}
    int maxAreaInt(vector<int> height) {
        int minn[MAXH];
        fill(minn, minn + MAXH, -1);
        for (int i = 0; i < height.size(); i++)
        {
            if (minn[height[i]] == -1)
            {
                minn[height[i]] = i;
            }
        }
        for (int i = MAXH - 2; i >= 0; i--)
        {
            if (minn[i + 1] != -1)
            {
                if (minn[i] == -1) {
                    minn[i] = minn[i + 1];
                } else {
                minn[i] = min(minn[i], minn[i + 1]);
                }
            }
        }
        // for (int i = 0; i < 10; i++) {
        //     cout << "minn[" << i << "] = " << minn[i] << endl;
        // }
        ll res = 0;
        for (int i = 0; i < height.size(); i++)
        {
            ll e = height[i];
            ll now = e * abs(i - minn[e]);
            res = max(res, now);
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> height{1, 2};
    cout << s.maxArea(height) << endl;
}