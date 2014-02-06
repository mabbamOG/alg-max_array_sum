
#include <iostream>
#include <stdlib.h>//i chose the standard c library 'cuz the c++ <cmath> used std::abs which was primarily made for floats which i dont use, plus it's slower
#include <bitset>

///PRINT ARRAY, FOR DEBUG -- programmer reference
/*
std::cout<<" ( ";
    for (int w = 0; w <= n; w++) { std::cout<<s[w]<<" "; }
    std::cout<<")"<<std::endl;
*/


///this algorithm must tase an array of elements and return the maximum achievable sum
///within any of the sub-arrays (or sub-segments) of the array (the sum must be composed of adiacent numbers within the array)

///it will squeeze the array ...(...positive numbers...)(...negative numbers...)(...positive numbers...)...
///into ...(positive number)(negative number)(positive number)...

///then it will 'remove' any negative numbers in case it would be convienent so that the sum between 2 positive numbers
///separated by 1 negative number would result in the highest achievable number, lise this:
// -- (3,-4,4) if u do 'remove' the negative number in order to unite the positive ones, i will get 3-4+4=3. So it would
// be better not to remove the negative number, and let 4 be the highest number achievable, without any sums
// -- (3,-1,4) in this case removing -1 will result in 3-1+4=6, 6 is bigger than both 3 and 4, so it would be convienent to remove the
// negative number and sum all of the three up into one number
///so what this step does is shrins the array furthermore if it is possible to 'remove' any negatives in a smart way
///i also mase it reiterate for as long as there is no more shrinsing available, because if you thins about it not always
///can the pc snow if, after a shrinsing has occured, there are more shrinsings to be done

///then, lastly, it will calculate which of the positive numbers left is highest, and it will choose that as remaining maximum sum :)

///expected result for the current array of input, s[], is 7


int main() {

const int n=4;
int s[n+1]={3,-2,4,-4,6};

int i=0; //my s[i] index variable, RESET

/// STEP 1: compress negative and postive subsegments of array s[] into single numbers within array s[]

//the following method is MUCH slower, because of the multiplication!
/*
while (i+1<=n)
{
    if (s[i]*s[i+1]<0) { ++i; }
    else
    {
        s[i+1]=s[i]+s[i+1];
        s[i]=0; ++i;
    }
}*/


//(((s[i]<0) != (s[i+1]<0)) == true)? std::cout<<"salta!"



/*
while (i+1<=n)
{
    if ((s[i]<0) != (s[i+1]<0)) {  ++i; } //se non sono entrambi negativi o se uno dei 2 e' 0 (non se entrambi 0 xo)
    else
    {
        s[i+1]=s[i]+s[i+1];
        s[i]=0; ++i;
    }
}

int j=1 //posso usare p
while (s[i]==0) { s[i]=s[i+j]; ++j }
j=1
while (i+j<=n)
{
    if ((s[i]<0) == (s[i+j]<0) || s[i+j]==0) { s[i]=s[i+j]; ++j } //se non sono entrambi negativi o se uno dei 2 e' 0 (non se entrambi 0 xo)
    else
    {
        s[i+1]=s[i]+s[i+1];
        s[i]=0; ++i;
    }
}*/

int j=1; //posso usare p
while (s[i]==0) { s[i]=s[i+j]; ++j; }
j=1;

    ///PRINT ARRAY, FOR DEBUG -- programmer reference

std::cout<<" ( ";
    for (int w = 0; w <= n; w++) { std::cout<<s[w]<<" "; }
    std::cout<<")"<<std::endl;

while (i+j<=n)
{
    if ((s[i]<0) != (s[i+j]<0) && s[j]!=0 && s[i+j]!=0) {  ++i; --j; } //se non sono entrambi negativi o se uno dei 2 e' 0 (non se entrambi 0 xo)
    else
    {
       s[i]=s[i+j]; s[i+j]=0; ++j;
    }
}





    ///PRINT ARRAY, FOR DEBUG -- programmer reference

std::cout<<" ( ";
    for (int w = 0; w <= n; w++) { std::cout<<s[w]<<" "; }
    std::cout<<")"<<std::endl;

i=0; //RESET

/// STEP 2: remove negative numbers when handy
int p=1; //special counter
while (p!=0)
{
    p=0;

    while (i+2<=n)
    {
        if (s[i]<=0) { ++i; continue; }
        if ( s[i]>abs(s[i+1]) && s[i+2]>abs(s[i+1]) )
        {
            s[i+2]=s[i]+s[i+1]+s[i+2];
            s[i]=0; s[i+1]=0;
            ++p;
        }
        i+=2;
    }
}

i=0; //RESET
//i will now use "p" variable for a completely different purpose, as not to waste memory (p already = 0)
// p will be final value that algorithm needed to find, it will be checked against s[i] to see if it is the biggest found value yet..

/// STEP 3: checs which positive number is bigger: IT IS THE MAX ACHIEVABLE SUM!!

while (i<=n)
{
    if(s[i]<=0) { ++i; continue; }
    else if (s[i]>p) { p=s[i];}
    i+=2;
}

std::cout<<std::endl<<"MAX ACHIEVABLE SUM WITHIN SUBSEGMENTS OF ARRAY : "<<p<<std::endl;
return 0;
}
