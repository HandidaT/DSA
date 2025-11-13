
#include <bits/stdc++.h>
using namespace std;


int longestCommonSubsequence(string s1, string s2)
{
	int n = s1.length();
	int m = s2.length();
	vector < vector<int>> lcs(n + 1 , vector<int>(m + 1, 0));
	// for (auto i : lcs)
	// {
	// for (auto j : i)
	// {
	// cout << j << ' ';
	// }
	// cout << endl;
	// }
	for (int i = 1; i < n + 1; i++) // be careful to start with index 1 as it will cause error in s1[i-1] statement if 0 is given
	{
		for (int j = 1 ; j < m + 1; j++)
		{
			//cout << "am i insde the 2nd loop\n";
			if (s1[i - 1] == s2[j - 1])
			lcs[i][j] = 1 + lcs[i - 1][j - 1];
			else
			lcs[i][j] = max(lcs[i][j - 1] , lcs[i - 1][j]);
		}
	}
	return lcs[m][n];
}
 
 
int max(int a, int b);
 
 /* A Naive recursive implementation of LCS problem */
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + lcs(X, Y, m-1, n-1);
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}
 
/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Driver code */
int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
     
    int m = strlen(X);
    int n = strlen(Y);
     
    cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;
     
    return 0;
}


/*
int longestCommonSubsequence(string s1, string s2)
{
int n = s1.length();
int m = s2.length();

vector < vector<int>> lcs(n + 1 , vector<int>(m + 1, 0));

// for (auto i : lcs)
// {
// for (auto j : i)
// {
// cout << j << ' ';
// }
// cout << endl;
// }

for (int i = 1; i < n + 1; i++) // be careful to start with index 1 as it will cause error in s1[i-1] statement if 0 is given
{
for (int j = 1 ; j < m + 1; j++)
{
//cout << "am i insde the 2nd loop\n";
if (s1[i - 1] == s2[j - 1])
lcs[i][j] = 1 + lcs[i - 1][j - 1];
else
lcs[i][j] = max(lcs[i][j - 1] , lcs[i - 1][j]);

}
}

return lcs[m][n];

}


int main()
{
string s1 = "chandra";
string s2 = "shekhar";

cout << "Longest common subsequence is : " << longestCommonSubsequence(s1, s2) << endl;

return 0;

}
*/
