#include<bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int t;

    cin>>t;

    while(t--){

        int n,k;

        cin>>n>>k;

        int A[100000]={-1};

        int y,y1 = 0;;

        for(int i = 1; i<=n; i++){

            int c = i,count = 0;

            while(c>0){

                int x = c%2;

                c = c/2;

                A[count] = x;

                count++;

            }

            y = 0;

            for(int i = count; i>=0; i--){

                if(A[i]==1&&A[i+1]==0&&A[i+2]==1){

                    y++;

                }

            }

            if(y>=k){

                y1++;

            }

        }

        cout<<y1<<endl;

        

    }

    return 0;

}