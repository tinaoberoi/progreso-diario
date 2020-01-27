# Number Theory Concepts

## Modular Arithmetic

* Properties:
  * (a+b)%c = (a%c + b%c)%c
  * (a*b)%c = ((a%c)*(b%c))%c
  * (a-b)%c = ((a%c) - (b%c))%c
  * (a/b)%c = ((a%c)*(b^(-1)%c))%c
* When used ?
Assume that a = 10<sup>18</sup> , b = 10<sup>18</sup>, and c = 10<sup>7</sup>+7. You have to find (a*b)%c.
When you multiply a with b, the answer is 10<sup>36</sup>, which does not conform with the standard integer data types. Therefore, to avoid this we used the properties.
(a*b)%c = ((a%c)*(b%c))%c

## Modular Exponention

* Calculating x<sup>n</sup>
* Breaking it to x.x<sup>n-1</sup>
```c++
int recursivePower(int x,int n)
{
    if(n==0)
        return 1;
    return x*recursivePower(x,n-1);
}

//Time complexity O(n)
```
* Optimised method, (x<sup>2</sup>)<sup>n/2</sup>
```c++
int binaryExponentiation(int x,int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return binaryExponentiation(x*x,n/2);
    else                             //n is odd
        return x*binaryExponentiation(x*x,(n-1)/2);
}
//Time complexity O(logN)
```