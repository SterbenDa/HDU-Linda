//哎呀  傻逼啊，两个公式合并sum[i+1]=(k1+k2)*sum[i]啊  
//一直模拟超时，狗逼蠢到了 
//（k1+k2）<=1&&&（k1+k2）>=-1  则会越乘越小 inf
//否则会负负得正，有一次会变大，然后变负，接着会更大 
#include<stdio.h>
int main()
{
    int t,cas,i,n;
    double k,k1,k2,j;
    scanf("%d",&cas);
    for(t=1;t<=cas;t++)
    {
         double sumk;  double sum;
         scanf("%d %lf %lf %lf",&n,&k1,&k2,&k);
         sumk=k1+k2;
         sum=0;
         for(i=0;i<n;i++)
         {
              scanf("%lf",&j);
              sum+=j;
         }
         if(sum>k) {printf("Case #%d: 0\n",t);continue;}

        if(sumk<=1&&sumk>=-1)
        {
            printf("Case #%d: inf\n", t);
            continue;
        }
         int cnt=0;
         while(1)
         {
              cnt++;
              sum=sum*sumk;
              if(sum>k) break;
         }
         printf("Case #%d: %d\n",t,cnt);
    }
    return 0;
}


