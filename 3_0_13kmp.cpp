// C++ program for implementation of KMP pattern searching
// algorithm
#include <bits/stdc++.h>
#include <iostream>
#include <map>
 
void computelps(char* pat, int M, int* lps);
  
// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
  
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
    // Preprocess the pattern (calculate lps[] array)
    computelps(pat, M, lps);
    std::cout<<"\n\nkmp---------------------------------------------";
  
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            std::cout<<"\n"<<i<<" "<<j<<" "<<pat[j]<<" "<<txt[i];
            j++;
            i++;
        }
  
        if (j == M) {
            printf("\nFound pattern at index %d ", i - j);
            j = lps[j - 1];
        }
  
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0){
                std::cout<<"\nelse if if  | i "<<i<<" j "<<j<<" "<<pat[j]<<" "<<txt[i];
                j = lps[j - 1];
                std::cout<<"  | i "<<i<<" j "<<j<<" "<<pat[j]<<" "<<txt[i];
                }
            else{
                std::cout<<"\nelse if else| i "<<i<<" j "<<j<<" "<<pat[j]<<" "<<txt[i];
                i = i + 1;
                std::cout<<"  | i "<<i<<" j "<<j<<" "<<pat[j]<<" "<<txt[i];
                }
        }
    }
}

// Fills lps[] for given patttern pat[0..M-1]
void computelps(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
  
    lps[0] = 0; // lps[0] is always 0
  
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    std::cout<<"\nlps";
    while (i < M) {
        std::cout<<"\n\n"<<pat[i]<<"| i is "<<i;
        if (pat[i] == pat[len]) {
            std::cout<<"\nif |len="<<len<<" "<<lps[i]<<" "<<lps[len];
            len++;
            lps[i] = len;
            std::cout<<" "<<len<<" "<<lps[i]<<" "<<lps[len];
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                std::cout<<"\nelse if |len="<<len<<" "<<lps[i]<<" "<<lps[len];
                len = lps[len - 1];
                std::cout<<" "<<len<<" "<<lps[i]<<" "<<lps[len];
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                std::cout<<"\nelseelse |len="<<len<<" "<<lps[i]<<" "<<lps[len];
                lps[i] = 0;
                std::cout<<" "<<len<<" "<<lps[i]<<" "<<lps[len];
                i++;
            }
        }
        std::cout<<"\n";
        for(int cnt=0;cnt<M;cnt++){
           std::cout<<lps[cnt]<<" ";
        }
    }
}

void computelps2(char* pat, int M, int* lps)
{
lps[0] = 0;
int len=0;
for(int i = 1; i < M; i++) {

    while(pat[i] != pat[len] && len != 0) {
        len = lps[len - 1];
    }

    if (pat[i] == pat[len]) {
        len++;
        lps[i] = len;
    }
}
}


// The term LPS refers to the Longest Proper Prefix that is also a Proper Suffix.
  
// Driver program to test above function
int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat1[] = "pwwkew";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    std::map<int, int> mvar;
    std::cout<<"\n\n=="<<mvar[1];
    return 0;
}
