Coin change problem
            
Here we are using greedy approach as we need to find the min number of coins required to form that sum of money so for that
our first priority will be to use as much as the largest domination of coins which are less then the amount of money so this
is considered to be greedy approach 

Now to break the problem into more simpler sub problems and optimize it we use dynamic programming
where we just use our previously calculated result to deduce the new results

so we create array Coins that holds all of the coins denomination
and an index of array of coins

and to use previously used result we will create a ways arrays 
so lets say
    n=20
    Coins :1,5,10
 
 Number of ways we can form 20 are 
 1) use all 1 Coins
 2) use all 5 Coins
 3) use all 10 Coins
 4)use combinations 
 
 which result in many no of ways stored in ways array

now we go through all of the coins
make a comparison to each index value of ways with the coin value.
and will return n pos at ways array as we dont want denomination greater than the sum required


