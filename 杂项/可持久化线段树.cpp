#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 20000010;

struct Persistable_Segment_tree
{
    //�ֱ��Ǹ�λ�ô���Ľڵ�������������Ҷ��Ӻ�Ȩֵ
    int ls,rs;  //��¼���Ҷ��ӵ��±�
    int v;
} tr[MAX];


//edit ����ڵ�汾 ע���һ��(�±�0)��ֵΪ1���һ���汾 w������ʼȨֵ
int edit[1 << 20] = {1},w[1 << 20],tot;

int build(int l,int r)  //������l-r�����ݹ��ɵĳ�ʼ�߶���
{
    //�˴�����ֱ����++tot����pos ��Ϊ��ת���ӳ����м���������ȥ totֵ������ ���˴�ֵ����ǰ�ڵ��� Ӧ����
    int pos = ++tot;//tot�ǵ�ǰ����ĩβ��λ�� ++tot������ĩβ���½�����ڵ������������Ϣ
    if (l == r)//����������� ��ֻ����һ���� ��ֻ���Ȩ
    {
        tr[pos].v = w[l];//��¼��ʼ��Ȩ
        return pos;//pos�ǵ�ǰ�ڵ�ı�� �践�� �������丸�׽ڵ��¼��
    }
    int mid = (l + r) >> 1;
    tr[pos].ls = build(l,mid);//��¼��ǰ�ڵ������ӱ��
    tr[pos].rs = build(++mid,r);//��¼��ǰ�ڵ���Ҷ��ӱ��
    return pos;//���ص�ǰ�ڵ��� �践�� �������丸�׽ڵ��¼��
}


//��ed�汾�Ļ����� �޸�p��ȨֵΪk ��¼��ǰ��������&&���Ҷ˵ĵ�l&&r
// ÿһ�θ��¶�����һ������ ����ڵ�Ϊ
int update(int ed,int l,int r,int p,int k)
{
    //�˴�����ֱ��++tot����pos ��Ϊ��ת���ӳ����м���������ȥ totֵ������ ���˴�ֵ����ǰ�ڵ��� Ӧ����
    int pos = ++tot;//��¼��ǰ�ڵ���
    if (l == r)//�����������ڵ�
    {
        tr[pos].v = k;//��¼�޸ĺ�ڵ�Ȩֵ
        return pos;//���ص�ǰ�ڵ��� �õ�ǰ�汾�ĸ��׼�¼��
    }
    tr[pos].ls = tr[ed].ls;//��֮ǰ�ĸýڵ�����Ӹ��� (����-->�����ӽڵ�ָ��ǰ���ڵ��Ա����á�)
    tr[pos].rs = tr[ed].rs;//��֮ǰ�ĸýڵ��Ҷ��Ӹ��� ��Ϊ֮��ֻ��ı�������֮һ��ֵ �����ӿ���ȷ���ýڵ�λ��
    int mid = (l + r) >> 1;//���ִ��е�
    if (p <= mid)
        tr[pos].ls = update(tr[ed].ls,l,mid,p,k);//����Ѱ�� �ƽ�p�� ����pos��������
    else
        tr[pos].rs = update(tr[ed].rs,mid+1,r,p,k);//����Ѱ�� �ƽ�p�� ����pos����Ҷ��� ��tr[ed]��ԭ���Ǵ�ʱtr[pos]ֻ��1��ȵĺ��ӵ�ֵ
    return pos;//����pos pos��Ϊ�õ㸸�׵�ĳ�����ӵ�λ�� ���Լ�¼
}

int found(int ed,int l,int r,int p)
{
    //ed�� ĳ�汾 ��������1~n��ֵ ��λ��
    if (l == r)
        return tr[ed].v;//�ҵ��õ� ��ʱed�Ѿ���Ϊ ��¼��ǰ�汾��p���λ���� ��v���ǵ�ǰ�汾��p���Ȩֵ ����
    int mid = (l + r) >> 1;
    if (p <= mid)
        return found(tr[ed].ls,l,mid,p);//����Ѱ�� �ƽ�p�� ed��Ϊed�������
    else
        return found(tr[ed].rs,mid+1,r,p);//����Ѱ�� �ƽ�p�� ed��Ϊed���Ҷ���
}

int main()
{
    int n,m,edition,mode,node,weight;
    scanf("%d%d",&n,&m);
    for (int a = 1 ; a <= n ; a ++)
        scanf("%d",&w[a]);
    build(1,n);//���� ������ 1 ~ n ��ʼ�ݹ� �����Ҷ���
    for (int a = 1 ; a <= m ; a ++)
    {
        scanf("%d%d%d",&edition,&mode,&node);
        if (mode % 2)
        {
            scanf("%d",&weight);
            //��update��ʱ���tr�����ĩβ edit[a]��Ϊ�ڵ�a���汾ʱ�޸ĵĵ�Ϊedit[a-1]��edit[a]�ĵ�(�������г����ñ������˺ܾúܾ�)
            edit[a] = update(edit[edition],1,n,node,weight);//update���ͼ��ӳ���
        }
        else
        {
            //��Ϊ����û�д����½ڵ� ��˵�ǰ�汾�����е���ڵ�ǰ�汾(���ǵ�a-1�İ汾)֮ǰ�����е�
            edit[a] = edit[edition];
            //�����ѯĳedition��ĳnode��ֵ
            printf("%d\n",found(edit[edition],1,n,node));
        }
    }
    return 0;
}
