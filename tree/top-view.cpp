#include <iostream>
#include <map>
#include <queue>
using namespace std;

// Print vertical sum of tree
// We can use a map here

struct node
{
    int data;
    node *left;
    node *right;

    node(int _data) : data(_data), left(NULL), right(NULL) {}
};

void topView(node *root)
{
    map<int, int> topMap;
    queue<pair<node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        auto p = q.front();
        node *c = p.first;
        int hd = p.second;

        if (topMap.find(hd) == topMap.end())
            topMap[hd] = c->data;

        q.pop();
        if (c->left != NULL)
            q.push({c->left, hd - 1});
        if (c->right != NULL)
            q.push({c->right, hd + 1});
    }

    for (auto it : topMap)
    {
        cout << it.second << " ";
    }
    cout << endl;
}

int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right = new node(30);
    root->right->left = new node(70);
    root->right->left->left = new node(80);
    root->right->left->left->left = new node(90);
    root->right->left->left->left->left = new node(100);
    root->right->right = new node(60);

    topView(root);
}