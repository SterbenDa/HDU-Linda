/*
分析：用贪心解决。血量少攻击高的要先消灭，所以以HP/DPS作为参数排序，即
将所有的敌人根据DPS/HP从大到小排序，如果相等，则按HP从小到大排序。
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

struct Node
{
    int dps;
    int hp;
}a[30];

int cmp(Node x,Node y)
{
    return x.hp*y.dps<y.hp*x.dps;//按比率排，避免小数，所以讲式子进行转换
}

int main()
{
    int t,i;
    int sum,ans;
    while(~scanf("%d",&t))
    {
        sum = ans = 0;
        for(i = 0;i<t;i++)
        {
            scanf("%d%d",&a[i].dps,&a[i].hp);
            sum+=a[i].dps;
        }
        sort(a,a+t,cmp);
        for(i = 0;i<t;i++)
        {
            ans+=sum*a[i].hp;
            sum-=a[i].dps;
        }
        printf("%d\n",ans);
    }

    return 0;
}

