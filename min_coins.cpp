/*
Dora, the explorer, visits India and decides to try the famous Indian food. However, the restaurant accepts only Indian currency i.e. [1, 2, 5, 10, 20, 50, 100, 500, 1000] valued coins.
So, Dora goes to a bank that has an infinite supply of each of the denominations to make a change for a given ‘Amount’ of money. As a cashier at the bank, your task is to provide Dora the minimum number of coins that add up to the given ‘Amount’.
For Example
For Amount = 70, the minimum number of coins required is 2 i.e an Rs. 50 coin and a Rs. 20 coin.
*/
int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int>notes={1,2,5,10,20,50,100,500,1000};
    int n=9;
    int mincoins=0;
    for(int i=n-1;i>=0 and amount>0;i--)
    {
        if(amount<notes[i])
        {
            continue;
        }
        else
        {
            int coins=amount/notes[i];
            mincoins+=coins;
            amount-=coins*notes[i];
        }
    }
    return mincoins;
}
