#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    std::unordered_map<char, node *> child;
    node *suffix_link;
    node *output_link;
    vector<int> pattern_ind;

    node()
    {
        suffix_link = nullptr;
        output_link = nullptr;
        pattern_ind = {};
    }

    size_t hash() const
    {
        size_t hashVal = 0;

        // hashVal ^= std::hash<int>{}(pattern_ind);
        if (suffix_link)
            hashVal ^= std::hash<node *>{}(suffix_link);
        if (output_link)
            hashVal ^= std::hash<node *>{}(output_link);
        return hashVal;
    }
};

void build_trie(node *root, vector<string> &patterns)
{
    for (int i = 0; i < patterns.size(); i++)
    {
        node *curr = root;
        for (int j = 0; j < patterns[i].size(); j++)
        {
            char c = patterns[i][j];
            if (curr->child.count(c) != 0)
                curr = (curr->child[c]);
            else
            {
                node *nn = new node();
                curr->child[c] = nn;
                curr = nn;
            }
        }
        curr->pattern_ind.push_back(i);
    }
}

void build_suffix_and_output_links(node *root)
{                             // will use bfs to set links
    root->suffix_link = root; // root represents empty string
    queue<node *> qu;

    for (auto c : root->child)
    {
        char rc = c.first;
        qu.push(root->child[rc]);
        root->child[rc]->suffix_link = root; // root's children suffixlink will point to root only
    }

    while (qu.size() > 0)
    {
        node *curState = qu.front();
        qu.pop();

        for (auto c : curState->child)
        {
            char cc = c.first;
            node *cchild = curState->child[cc]; // jiske liye suffix link dhund rhe hein
            node *tmp = curState->suffix_link;  // parent suffix link
            while (tmp->child.count(cc) == 0 && tmp != root)
                tmp = tmp->suffix_link; // finding lps

            if (tmp->child.count(cc) != 0)
                cchild->suffix_link = tmp->child[cc];
            else
                cchild->suffix_link = root;
            qu.push(cchild);
        }

        // setting output link
        if (curState->suffix_link->pattern_ind.size() >= 0)
            curState->output_link = curState->suffix_link;
        else
            curState->output_link = curState->suffix_link->output_link;
    }
}

void search2(node *root, string text, vector<int> res[])
{
    node *parent = root;

    for (int i = 0; i < text.length(); i++)
    {
        char c = text[i];
        if (parent->child.count(c) != 0)
        { // if parent has a child node in trie, travel it
            parent = parent->child[c];
            if (parent->pattern_ind.size() >= 0)
            {
                for (auto j : parent->pattern_ind)
                    res[j].push_back(i); // reached a output node
            }

            node *myOutput = parent->output_link;
            while (myOutput != nullptr)
            {
                for (auto j : myOutput->pattern_ind)
                    res[j].push_back(i);
                myOutput = myOutput->output_link;
            }
        }
        else
        {
            while (parent != root && parent->child.count(c) == 0)
                parent = parent->suffix_link;
            if (parent->child.count(c) != 0)
                i--; // hold i and start traversing in next iteration
        }
    }
}

int main()
{
    string txt;
    cin >> txt;
    int n;
    cin >> n;
    vector<string> patterns(n);
    for (int i = 0; i < n; i++)
        cin >> patterns[i];

    node *root = new node();
    build_trie(root, patterns);
    build_suffix_and_output_links(root);

    vector<int> res[n];
    search2(root, txt, res);
    for (int i = 0; i < n; i++)
    {
        cout << res[i].size();
        cout << "\n";
    }
}
