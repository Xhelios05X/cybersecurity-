// g++ ceasar_decoding.cpp
// ./ceasar_decoding
// Tool is used for decoding a Ceasar Cipher
// Author: github/Xhelios05X
#include <iostream>

using namespace std;

// change to the most common letter in a given language
// for default language (English) C = 'E'
char const C = 'E';

// script doesn't consider special characters
bool condition(char A)
{
    if((A>=32 && A<=64)||(A>=91 && A<=96)||(A>=123 && A<=126))
        return true;
    else
        return false;
}

int key(string a)
{
    int A[26];
    for(int i=0; i<26; i++)
        A[i]=0;

    for(int i=0; i<a.size(); i++)
    {
        if(!condition(a[i]))
            A[int(a[i])-'A']++;
    }

    int tmp = 0, m;
    for(int i =0; i<26; i++)
    {
        if(A[i]>tmp)
        {
            tmp=A[i];
            m = i;
        }
    }

    return int('A'+m-C);
}

void Ceasar(string a, int k)
{

    for(int i=0; i<a.size(); i++)
    {
        if(condition(a[i]))
            cout << a[i];
        else
        {
            if(a[i]>='A' && a[i]<='Z' && a[i]+k>'Z') cout << char(a[i]+k-26);
            else if(a[i]>='a' && a[i]<='z' && a[i]+k>'z') cout << char(a[i]+k-26);
            else cout << (char(a[i]+k));
        }
    }
}

int main()
{
    string a,b;
    getline(cin, a);
    b=a;

    for(int i =0; i<a.size(); i++)
            b[i] = toupper(a[i]);

    int k =key(b);
    cout << "key: " << k << endl;
    cout << "solution: ";
    Ceasar(a, k);


    return 0;
}

