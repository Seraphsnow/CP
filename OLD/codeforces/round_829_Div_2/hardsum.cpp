#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> prenums, vector<int> preindices, int size)
{
    int n = prenums.size();
    vector<int> indices, nums;
    for (int i = 0; i < n; i++)
    {
        int num;
        num = prenums[i];
        if (nums.empty())
        {
            nums.push_back(num);
            indices.push_back(preindices[i]);
        }
        else
        {
            if (nums[nums.size() - 1] == num)
            {
                nums.pop_back();
                indices.pop_back();
            }
            else
            {
                nums.push_back(num);
                indices.push_back(preindices[i]);
            }
        }
    }
    if (n % 2)
    {
        cout << "-1\n";
        return;
    }
    if (indices[indices.size() - 1] != size)
        indices.push_back(size);
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
        int n;
        cin >> n;
        vector<int> nums, indices;
        bool parity = true;
        for (int i = 1; i <= n; i++)
        {
            int num;
            cin >> num;
            if (num == 0)
            {
                parity = !parity;
                continue;
            }
            if (parity)
            {
                nums.push_back(num);
            }
            else
            {
                nums.push_back(-num);
            }
            indices.push_back(i);
            parity = true;
        }
        if (indices.empty())
        {
            cout << "1\n"
                 << "1 " << n << endl;
        }
        else
        {
            solve(nums, indices, n);
        }
    }
}