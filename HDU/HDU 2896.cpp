#include<cstdio>

int N,M;
char a[510][400];
char str[10010];

const int SIZE = 130;
struct Node{
    Node* fail;
    Node* next[SIZE]
};

Node* createTrieNode()
{
    Node* node = new Node();
    node->fail = NULL;
    for(int i=0; i<SIZE; i++)
        node->next[i] == NULL;
    return node;
}

void trieInsert(Node* root, char* key)
{
    Node* node = root;
    char* p = key;
    while(*p)
    {
        if(node->next[(int)(*p)] == NULL)
            node->next[(int)(*p)] == createTrieNode();
        node = node->node->next[(int)(*p)];
        ++p;
    }
}

void buildAcAutomation(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* p = NULL;
        Node* temp =  q.front(); q.pop();
        for(int i=0; i<SIZE; i++)
        {
            if(temp->next[i] != NULL)
            {
                if(temp == root)
                    temp->next[i]->fail = root;
                else
                {
                    p = temp->fail;
                    while(p != NULL)
                    {
                        if(p->next[i] != NULL)
                        {
                            temp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(p == NULL)
                        temp->next[i]->fail = root;
                }
                q.push(temp->next[i]);
            }
        }
    }
}

int query(Node* root, char* s)
{
    int len = strlen(s);
    Node* p = root;
    for(int i=0; i<len; i++)
    {
        int v = (int)s[i];
        while(p->next[v]==NULL && p!=root)
            p = p->fail;
        p = p->next[v];
        if(p == NULL)
            p = root;
        Node* temp = p;
        while(temp != root)
        {
            temp = temp->fail;
        }
    }
    return cnt;
}
void solve()
{

}

int main()
{
    while(~scanf("%d",&N))
    {
        for(int i=0; i<n; i++)
            scanf("%s",a[i]);
        scanf("%d",&M);
        for(int i=0; i<M; i++)
        {
            scanf("%s,",str);
            solve();
        }
    }
    return 0;
}
