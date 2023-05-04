#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> indices, nums;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        if (nums.empty())
        {
            nums.push_back(num);
            indices.push_back(i);
        }
        else
        {
            if (nums[nums.size()-1] == num)
            {
                nums.pop_back();
                indices.pop_back();
            }
            else
            {
                nums.push_back(num);
                indices.push_back(i);
            }
        }
    }
    if (n % 2)
    {
        cout << "-1\n";
        return;
    }
    if (indices[indices.size()-1] != n)
        indices.push_back(n);
    cout << indices.size() << endl;
    for (int i = 0; i < indices.size(); i++)
    {
        if (i == 0)
        {
            cout << "1 " << indices[0] << endl;
        }
        else
        {
            cout << indices[i - 1] + 1 << " " << indices[i] << endl;
        }
    }
}

int main(int argc, char *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}