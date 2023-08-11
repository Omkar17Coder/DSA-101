// Problem of Leetcode.

/*

A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

 



*/
#define MOD 1000000007
class Solution {
public:
// Here we asume the n to be a n length string which should be used and by using permutaions we are able to simplly solve it..

long long int power(long long x,long long y){
    if(x==0)return 1;
    long long int ans=power(x/2,y);
    ans*=ans;
    ans%=MOD;
    if(x%2)ans*=y;
    ans%=MOD;
    return ans;


}
    int countGoodNumbers(long long n) {
        long long odd=n/2;
        long long even=n/2+n%2;
        return (power(odd,4)*power(even,5))%MOD;

    }
};
