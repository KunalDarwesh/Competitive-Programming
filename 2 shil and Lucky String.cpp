#include<iostream>
 using namespace std;
 #include<bits/stdc++.h>
 int has1[26],has2[26];
  int main()
   {
    int n;
      cin>>n;
        char ff[n+10],ss[n+10];
          for(int i=0;i<n/2;i++)
          {
              cin>>ff[i];
               has1[ff[i]-'a']++;
          }
            for(int i=0;i<n/2;i++)
            {

                  cin>>ss[i];
                  has2[ss[i]-'a']++;
            }
            sort(ff,ff+n/2);
              sort(ss,ss+n/2);
              //case 1
               int ans1=0,ans2=0,ans3=0;
              for(int i=0;i<26;i++)
              {
                  ans1+=abs(has1[i]-has2[i]);
                //    cout<<"i " <<i<<" " <<has1[i]<<" " <<has2[i]<<endl;

              }
              int i=0,j=0;
               while(i!=n/2  && j!=n/2)
               {
                   if(ff[i]<ss[j])
                   {

                        i++;
                         j++;
                   }
                   else
                    j++;

               }
               ans2=abs(j-i);


               i=0,j=0;
               while(i!=n/2  && j!=n/2)
               {
                   if(ss[i]<ff[j])
                   {

                        i++;
                         j++;
                   }
                   else
                    j++;

               }

            ans3=abs(j-i);
             // cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
            cout<<min(min(ans1/2,ans2),ans3);
        return 0;
      }