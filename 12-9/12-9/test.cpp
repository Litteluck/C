#include<iostream>
using namespace std; 


//实现加法，不适用现成的运算符
class UnusualAdd 
{
public: int addAB(int A, int B) 
{
			int sum = 0, carry = 0; 
			while (B != 0)
			{ 
				//对应位的和 sum = A^B; 
				//对应位和的进位，既然是进位，就要整体左移一位 
				carry = (A&B)<<1;
				A=sum; 
				B=carry; 
			}
			return sum; 
}
};


//为求取路径总数的题目
int pathNum(int n,int m) 
{
	if(n > 1 && m > 1) 
		//b情况，递归 
		return pathNum(n-1,m) + pathNum(n,m-1); 
	else if(((n >= 1)&&(m == 1))||((n == 1)&&(m >= 1)))
		// a情况，终止条件
		return n + m; 
	else
		//格子为0时， 路径为0
		return 0; 
}
int main() 
{ 
	int n,m;
	while(cin>>n>>m)
	{ 
		cout<<pathNum(n,m)<<endl;
	}return 0; 
}