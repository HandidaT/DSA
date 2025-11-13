#include <iostream>




int euclidGcd_recursive(int m,int n){
	if(n>m){
	int temp=m;
	m=n;
	n=temp;
	}
	if(m%n==0) return n;
	return euclidGcd_recursive(n,m%n);
}

int euclidGcd_iterative(int m, int n){
	if(n>m){
		int temp=m;
		m=n;
		n=temp;
	}
	while(m%n!=0){
		int temp=m;
		m=n;
		n=m%n;
	}
	return n;
}























































/*
int euclidGcd_recursive(int m, int n){
    if(m<n){
        int temp;//swap operation
        temp=m;
        m=n;
        n=temp;
    }
    if(m%n==0) return n;
    else return euclidGcd_recursive(n,m%n);
}


int euclidGcd_iterative(int m, int n){
	if(m<n){
		int temp=m;
		m=n;
		n=temp;
	}
	while(m%n!=0){
		int temp=m;
		m=n;
		n=temp%n;
	}
	return n;
}*/

int main(){
    int m,n;
    std::cin>>m;
    std::cin>>n;
    std::cout<<m<<" "<<n<<"\n";
    std::cout<<euclidGcd_recursive(m,n)<<"\n"<<euclidGcd_iterative(m,n);
}


/*#greatest common divisor: given two or more numbers, there could be two or more number that divide the given numbers. Among these numbers one that divides all of the given numbers and is the greatest of all is gcd.

def naivegcd(num1,num2):#list out all factors of num1, list out all factors of num2 and then report the largest number that appears in both lists.
    fnum1=[]
    for i in range(1,num1+1):
        if(num1%i) == 0:
            fnum1.append(i)
    fnum2=[]
    for j in range(1,num2+1):
        if (num2%j)==0:
            fnum2.append(j)
    cf=[]
    for k in fnum1:
        if k in fnum2:
            cf.append(k)
    return(cf[-1])

print(naivegcd(4,16))

def betterthannaivegcd(num1,num2):#instead of iterating twice for given two numbers we can iterate just once till minimum of given numbers as gcd won't be greater than min
    cf=[]                      #and calculate cf as well in the same loop
    for i in range(1,min(num1,num2)+1):
        if(num1%i)==0 and (num2%i)==0:
            cf.append(i)
    return cf[-1]

print(betterthannaivegcd(4,16))

def nolist_betterthannaivegcd(num1,num2):#remove all lists as gcd is the current/last element of the loop/(last element of the list), by updating cf variable.
    for i in range(1,min(num1,num2)+1):
        if(num1%i)==0 and (num2%i)==0:
            cf=i
    return i

print(nolist_betterthannaivegcd(4,16))

def gobckwrdsnolst_bttrthnnaivegcd(num1,num2):#go backwards as gcd is always last element of the loop by start from min of given numbers
    cf=min(num1,num2)
    while cf>0:
        if(num1%cf)==0 and (num2%cf)==0:
            return cf
        else:
            cf=cf-1

print(gobckwrdsnolst_bttrthnnaivegcd(4,16))

def recursive_euclid_gcd(num1,num2):# d=gcd m=num1 n=num2 is divide both so m=ad and n=b*d==>  (m-n)=(ad - bd)==>   (m-n)=(a-b)d
    		          #gcd divides (m-n) as well, which is <= min(m,n)    gcd(m,n)==gcd(n,m-n)//which is less
    if num1 < num2:   #assume num1>=num2
        (num1,num2) = (num2,num1)
    if(num1%num2)==0:#if num2 is the gcd
        return num2
    else:
        diff=num1-num2
        return recursive_euclid_gcd(max(num2,diff),min(num2,diff))#diff>n? posssible!

print(recursive_euclid_gcd(4,16))

#difference euclid gcd
def euclid_gcd(num1,num2):# d=gcd m=num1 n=num2 is divide both so m=ad and n=b*d==>  (m-n)=(ad - bd)==>   (m-n)=(a-b)d
    		          #gcd divides (m-n) as well, which is <= min(m,n)    gcd(m,n)==gcd(n,m-n)//which is less
    if num1 < num2:   #assume num1>=num2
        (num1,num2) = (num2,num1)
    while(num1%num2)!=0:#if num2 is not the gcd
        diff=num1-num2#diff>n? posssible!
        (num1,num2) = (max(num2,diff),min(num2,diff))
    return num2

print(euclid_gcd(4,16))

#we can do better. For difference euclid gcd when smaller num2 is very small it takes longer. ex: euclid_gcd(101,2) loop 50 steps steps euclid_gcd(99,2) euclid_gcd(97,2)...euclid_gcd(2,1)
def remainder_euclid_gcd(num1,num2):#if n doesn't divide m. Then m=qn+r (q=quotient, r=remainder) then m=ad, n=bd. so ad=q(bd) + r. It follows that r=cd, so d divides r as well.
    		          #
    if num1 < num2:   #assume num1>=num2
        (num1,num2) = (num2,num1)
    if(num1%num2)==0:#if num2 is the gcd
        return num2
    else:
        return remainder_euclid_gcd(num2,num1%num2)

print(remainder_euclid_gcd(4,16))
*/
