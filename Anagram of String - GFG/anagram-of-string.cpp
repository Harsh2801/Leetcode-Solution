// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2)
{
// Your code goes here
   int n1 = str1.length();
   int n2 = str2.length();
   
   vector<int> v1(26,0);
   vector<int> v2(26,0);
   for(int i =0;i<n1;i++){
       v1[str1[i]-'a']++;
   }
   for(int i =0;i<n2;i++){
       v2[str2[i]-'a']++;
   }
   int count = 0;
   for(int i =0;i<26;i++){
       count+=abs(v1[i]-v2[i]);
   }
   return count;
   
}


