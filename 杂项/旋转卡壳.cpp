
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0; i<n; i++)
            scanf("%d %d",&p[i].x,&p[i].y);
        int low = 0;
        for(int i=1; i<n; i++)
            if(p[low].y == p[i].y && p[low].x > p[i].x || p[low].y > p[i].y)
                low = i;
        if(low)
            swap(p[0],p[low]);
        sort(p+1,p+n,cmp);
        Graham(n);
        RC();
    }
    return 0;
}
