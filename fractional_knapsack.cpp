/*
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

 

Example 1:

Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 
*/


/*
struct Item{
    int value;
    int weight;
};
*/
bool static cmp (Item a,Item b)
{
    double r1=(double)a.value/(double)a.weight;
    double r2=(double)b.value/(double)b.weight;
    if(r1>r2)
    return true;
    return false;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp);
        double ans=0;
        int cur_wt=0;
        for(int i=0;i<n;i++)
        {
            if(cur_wt+arr[i].weight<=W)
            {
                cur_wt+=arr[i].weight;
                ans+=arr[i].value;
            }
            else
            {
                double rem_wt=W-cur_wt;
                ans+=((double)arr[i].value/(double)arr[i].weight)*rem_wt;
                break;
            }
        }
        return ans;
    }
        
};