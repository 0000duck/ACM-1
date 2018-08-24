#include<cstdio>

const int ALPHABET_SIZE = 26;

struct trieNode{
    int cnt;    //记录该节点代表的单词的个数
    trieNode* children[ALPHABET_SIZE]; //各个子节点
};

trieNode* createTrieNode()
{
    trieNode* node = new trieNode();
    node->cnt = 0;
    for(int i=0; i<ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

void trieInsert(trieNode* root, char* key)
{
    trieNode* node = root;
    char* p  = key;
    while(*p)
    {
        if(node->children[*p - 'a'] == NULL)
            node->children[*p - 'a'] = createTrieNode();
        node = node->children[*p - 'a'];
        node->cnt+=1;
        ++p;
    }

}

int trieSearch(trieNode* root, char* key)
{
    trieNode* node = root;
    char* p = key;
    while(*p && node != NULL)
    {
        node = node->children[*p - 'a'];
        ++p;
    }

    if(node == NULL)
        return 0;
    else
        return node->cnt;
}

int main()
{

    char str[20];
    trieNode* root = createTrieNode();
    while(gets(str))
    {
        if(str[0] == '\0')
            break;
        trieInsert(root, str);
    }
    while(~scanf("%s",str))
    {
        printf("%d\n",trieSearch(root, str));
    }

    return 0;
}
