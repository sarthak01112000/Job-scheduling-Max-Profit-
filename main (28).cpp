#include <iostream>
#include<algorithm>
using namespace std;
struct job
{
    char id;
    int deadline;
    int profit;
};

bool compare(job a,job b)
{
    return(a.profit>b.profit);
}

void calculate(job arr[],int n)
{
    sort(arr,arr+n,compare);
    bool slot[n];
    for(int k=0;k<n;k++)
    slot[k]=false;
    int result[n];

    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=min(n,arr[i].deadline)-1;j>=0;--j)
        {
            if(slot[j]==false)
            {
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
    }
    for(i=0;i<n;i++)
    {   if(slot[i]==true)
        cout<<arr[result[i]].id<<" ";
    }
    
}
int main()
{
    int n;
    // job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, 
    //               {'d', 1, 25}, {'e', 3, 15}}; 
    job arr[1000];
                   cout<<"Enter the number of Jobs\n";
                   cin>>n;
                   for(int i=0;i<n;i++)
                   {
                       cout<<"Enter id\tdeadline\tProfit"<<"\n";
                       cin>>arr[i].id>>arr[i].deadline>>arr[i].profit;
                   }
    //int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Following is maximum profit sequence of jobs \n"; 
    
    // Function call 
    calculate(arr, n); 
    return 0;
}
