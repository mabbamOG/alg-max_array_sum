#include <iostream>
#include <stdlib.h> //libreria c xk <cmath> del c++ usava std::abs principalmente x i floating points, qndi piu lenta


///PRINT ARRAY, FOR DEBUG -- programmer reference
/*
std::cout<<" ( ";
    for (int i = 0; i <= n; i++) { std::cout<<k[i]<<" "; }
    std::cout<<")"<<std::endl;
*/


///this algorithm must take an array of elements and return the maximum achievable sum
///within any of the sub-arrays (or sub-segments) of the array (the sum must be composed of adjacent numbers within the array)

///it will squeeze the array ...(...positive numbers...)(...negative numbers...)(...positive numbers...)...
///into ...(positive number)(negative number)(positive number)...

///then it will 'remove' any negative numbers in case it would be convienent so that the sum between 2 positive numbers
///separated by 1 negative number would result in the highest achievable number, like this:
// -- (3,-4,4) if u do 'remove' the negative number in order to unite the positive ones, i will get 3-4+4=3. So it would
// be better not to remove the negative number, and let 4 be the highest number achievable, without any sums
// -- (3,-1,4) in this case removing -1 will result in 3-1+4=6, 6 is bigger than both 3 and 4, so it would be convienent to remove the
// negative number and sum all of the three up into one number
///so what this step does is shrink the array furthermore if it is possible to 'remove' any negatives in a smart way
///i also make it reiterate for as long as there is no more shrinking available, because if you think about it not always
///can the pc know if, after a shrinking has occured, there are more shrinkings to be done

///then, lastly, it will calculate which of the positive numbers left is highest, and it will choose that as remaining maximum sum :)

///expected result for the current array of input, s[], is 7

int main() {

const int n=4;
int s[n+1]={3,-2,4,-4,6};
int k[n+1]={0};

int i=0, j=0;
///old step 1. as you can see in while (s[i]>=0) if the i++ kept on going, it could step over the array limits
// step 1: compress negative and postive subsegments of array s[] into single numbers within array k[]
/*while (i<=n)
{
    while (s[i]>=0)
    {
        k[j]+=s[i]; ++i;
    }
    ++j;
    while (s[i]<0)
    {
        k[j]+=s[i]; ++i;
    }
    ++j;
}*/

///kinda ugly fix, needs to be cleaned up...: CERRO, I CHOOSE YOU! "pika!pika!"

while (i<=n)
{

    while (s[i]>=0)
    {
        if (i>n) break;
        k[j]+=s[i]; ++i;
    }
    ++j;
    while (s[i]<0)
    {
        if (i>n) break;
        k[j]+=s[i]; ++i;
    }
    ++j;
}

j=0;
// step 2: remove negative numbers when handy
int p=1;
while (p!=0)
{
    p=0;
    int ttt; //ttt MUST be used!!! otherwise using abs(k[j+1]) will not work!
    while (j<=n)
    {
        if (k[j]<=0) { ++j; continue;}
        ttt = k[j+1];
        if ( k[j]>abs(ttt) && k[j+2]>abs(ttt) )
        {
            k[j+2]=k[j]+k[j+1]+k[j+2];
            k[j]=0; k[j+1]=0;
            ++p;
        }
        j+=2;
    }
}


///PRINT ARRAY, FOR DEBUG


for (int i = 0; i <= n; i++) {  } //****************************TENTARE DI RIMUOVERE QUESTA RIGA DA 0 INVECE CHE 7


j=0; i=0; //i will now use "i" and "p" variables for completely different purposes, as not to waste memory
// i will be final value that algorithm needed to find
// p will be a value to put within i if it is the biggest number found yet, it will keep changing as i go through the array....

// step 3: check which positive number is bigger: IT IS THE MAX ACHIEVABLE SUM!!
while (j<=n)
{
    if(k[j]<=0) { ++j; continue; }
    p=k[j]; if (p>i) { std::swap(p,i); }
    j+=2;
}


std::cout<<std::endl<<"MAX ACHIEVABLE SUM WITHIN SUBSEGMENTS OF ARRAY : "<<i<<std::endl;

return 0;
}
