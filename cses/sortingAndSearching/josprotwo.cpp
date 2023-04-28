#include <bits/stdc++.h>
#include <limits.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>

bool comp(ll p1, ll p2)
{
    return p1 < p2;
}

class TreeNode
{
private:
    ll val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    ll leftNum, rightNum;

public:
    TreeNode(ll val)
    {
        this->val = val;
        leftNum = 0;
        rightNum = 0;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
    ll getVal()
    {
        return val;
    }
    TreeNode *getLeft()
    {
        return left;
    }
    void setLeft(TreeNode *node)
    {
        left = node;
    }
    TreeNode *getRight()
    {
        return left;
    }
    void setRight(TreeNode *node)
    {
        right = node;
    }
    TreeNode *getParent()
    {
        return parent;
    }
    void setParent(TreeNode *node)
    {
        parent = node;
    }
    void changeLeft(ll val)
    {
        leftNum += val;
    }
    void changeRight(ll val)
    {
        rightNum += val;
    }
};

class Tree
{
private:
    TreeNode *root;

public:
    Tree(ll val)
    {
        root = new TreeNode(val);
    }
    void insert(ll val)
    {
        TreeNode *currNode = root;
        while (true)
        {
            if (currNode->getVal() > val)
            {
                if (currNode->getLeft() == nullptr)
                {
                    TreeNode *node = new TreeNode(val);
                    currNode->setLeft(node);
                    node->setParent(currNode);
                    currNode = node;
                    break;
                }
                else
                {
                    currNode = currNode->getLeft();
                }
            }
            else
            {
                if (currNode->getRight() == nullptr)
                {
                    TreeNode *node = new TreeNode(val);
                    node->setParent(currNode);
                    currNode->setRight(node);
                    currNode = node;
                    break;
                }
                else
                {
                    currNode = currNode->getRight();
                }
            }
        }
        while (currNode->getParent() != nullptr)
        {
            if (currNode->getParent()->getLeft() == currNode)
            {
                currNode->getParent()->changeLeft(1);
                currNode = currNode->getParent();
            }
            else
            {
                currNode->getParent()->changeRight(1);
                currNode = currNode->getParent();
            }
        }
    }
    void mydelete(ll val)
    {
        TreeNode *currNode = root;
        while (true)
        {
            if (currNode->getVal() == val)
            {
            }
        }
    }
    ll find(ll index)
    {
    }
};

#define ordered_set tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main(int argc, char *argv[])
{
    ll n, k;
    std::cin >> n >> k;

    if (k == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        return 0;
    }
    ordered_set set;
    for (int i = 1; i <= n; i++)
    {
        set.insert(i);
    }
    ll index = 0;
    for(int i = 0; i < n; i++){
        index+= k;
        index = index % (n-i);
        std::cout << *set.find_by_order(index) << " ";
        set.erase(set.find_by_order(index));
    }
    std::cout << std::endl;
    
}