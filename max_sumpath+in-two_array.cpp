int sum1=0,sum2=0,ans=0,i=0,j=0;
        while(i<l1 && j<l2)
        {
            if(a[i]<b[j])
            {
                sum1+=a[i];
                i++;
            }
            else if(a[i]>b[j])
            {
                sum2+=b[j];
                j++;
            }
            else
            {
                ans+=max(sum1,sum2);
                sum1=0,sum2=0;
                ans+=a[i];
                i++;
                j++;
            }
        }
        while(i<l1)
         sum1+=a[i++];
        while(j<l2)
         sum2+=b[j++];
        ans+=max(sum1,sum2);
        return ans;
