#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second

ll search(ll demand, pair<ll, ll> *prices, ll n)
{
    ll left = 0, right = n - 1;
    ll mid = (left + right) / 2;
    while (true)
    {
        if (right - left <= 1)
        {
            return right;
        }
        if (prices[mid].fi > demand)
        {
            right = mid;

            mid = (left + right) / 2;
        }
        else if (prices[mid].fi == demand)
        {
            return mid;
        }
        else
        {
            left = mid;
            mid = (left + right) / 2;
        }
    }
}

bool comparator(pair<ll, bool> price1, pair<ll, bool> price2)
{
    return price1.fi < price2.fi;
}

int main(int argc, char *argv[])
{
    ll n, m;
    cin >> n >> m;
    ll count = 0;
    pair<ll, bool> prices[n];
    for (int i = 0; i < n; i++)
    {
        ll price;
        cin >> price;
        prices[i] = {price, 1};
    }
    sort(prices, prices + n, comparator);

    pair<ll, ll> prices2[n];
    ll index = 0, total = 1;
    ll prev = prices[0].fi;
    for (int i = 1; i < n; i++)
    {
        if (prices[i].fi == prev)
        {
            total++;
        }
        else
        {
            prices2[index] = {prev, total};
            prev = prices[i].fi;
            total = 1;
            index++;
        }
    }

    prices2[index] = {prev, total};
    index++;

    pair<ll, ll> *demand;

    demand = new pair<ll, ll>[m];
    ll indexd = 0;
    cin >> demand[0].fi;
    demand[0].se = 1;
    // cout << "HI\n";
    for (int i = 1; i < m; i++)
    {

        ll demand1;
        cin >> demand1;
        if (demand1 == demand[indexd].fi)
        {
            demand[indexd].se++;
        }
        else
        {
            indexd++;
            demand[indexd].fi = demand1;
            demand[indexd].se = 1;
        }
    }
    ll minindex = 0;
    ll jump[index];

    for (int i = 0; i < index; i++)
    {
        jump[i] = i;
    }
    // for (int i = 0; i < index; i++)
    // {
    //     cout << prices2[i].fi << " " << prices2[i].se << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < indexd; i++)
    // {
    //     cout << demand[i].fi << " " << demand[i].se << endl;
    // }
    // cout << endl;

    for (int i = 0; i <= indexd; i++)
    {

        ll currdemand = demand[i].fi;
        ll myindex = search(currdemand, prices2, index);
        // cout << myindex << " " << currdemand << endl;
        ll currindex = myindex;
        ll done = 0;
        stack<ll> indices;
        //indices.push(myindex);
        while (myindex >= 0 && jump[myindex] != myindex)
        {
            // cout << myindex << endl;
            myindex = jump[myindex];
            if (myindex > 0)
                indices.push(myindex);
        }
        // cout << myindex << endl;

        for (; myindex >= minindex; myindex--)
        {
            if(myindex!=currindex){
                indices.push(myindex);
            }
            while (myindex >= 0 && jump[myindex] != myindex)
            {
                // cout << myindex << endl;
                myindex = jump[myindex];
                if (myindex > 0)
                    indices.push(myindex);
            }
            if (myindex < 0)
                break;
            count++;

            if (prices2[myindex].fi <= currdemand && prices2[myindex].se > 0)
            {
                // cout << prices2[myindex].fi << endl;

                ll num = min(prices2[myindex].se, demand[i].se - done);
                for (int k = 0; k < num; k++)
                {
                    cout << prices2[myindex].fi << endl;
                }
                done += num;
                prices2[myindex].se -= num;
                // if(jump[myindex] == myindex) jump[myindex] = currindex;

                // done++;
                if (done == demand[i].se)
                {
                    break;
                }
                // myindex++;
            }
            else if (prices2[myindex].fi > currdemand)
            {
                currindex--;
            }
        }
        // cout << myindex << endl;
        jump[currindex] = myindex;

        while (indices.size() != 0)
        {
            ll elem = indices.top();
            jump[elem] = myindex;
            indices.pop();
        }

        for (int j = 0; j < demand[i].se - done; j++)
        {
            minindex = currindex;
            cout << -1 << endl;
        }

        // for(int k = 0; k < index; k++){
        //     if(jump[k] == -1) cout << k << endl;
        // }
    }
    //cout << count << endl;
}