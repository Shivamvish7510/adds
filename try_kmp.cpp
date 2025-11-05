#include<iostream>
#include<vector>
using namespace std;

// Function to create LPS (Longest Prefix Suffix) array
void compute_LPS(string pattern, vector<int> &lps){
    int pre=0;
    int suff=1;
    lps[0]=0;
    while(suff<pattern.length()){
        if(pattern[suff]==pattern[pre]){
            lps[suff]=pre+1;
            pre++, suff++;
        }
        else{
            if(pre!=0){
                pre=lps[pre-1];
            }
            else{
                lps[suff]=0;
                suff++;
            }
        }
    }
}

// Kmp functions 


// str1== text
// str2== pattern


void kmp(string str1, string str2){
    int x=str1.length();
    int y=str2.length();

    vector<int>lps(y);
    compute_LPS(str2 , lps);
    bool found = false;


    int i = 0;
    int j =0;

    while(i<x){
        if (str1[i]== str2[j]){
            i++, j++;
        }

        if (j==y){
            cout<<"pattern found at index "<< i-j << endl;
            found = true;
            j = lps[j-1];

        }

        else if(i<x && str1[i]!= str2 [j]){
            if(j!=0)
                j=lps[j-1];
            else 
                i++;
        }


    }

    if (!found)   // no match found
    cout << "Pattern not found in the text." << endl;
}

int main(){
    string text, pattern;
    cout<< "Enter text : ";
    getline(cin, text);

    cout<< "Enter pattern : ";
    getline(cin, pattern);

    kmp(text , pattern);

    return 0;

}