#include <iostream>
#include<vector>
#include<cstdlib>
using namespace std;

//program to find maximum number of thieves can be caught .
int FindThiefs(char PT[], int Size , int d)//d:distance between thief and police man , PT:array of characters.
{
    int caught=0,a=0,b=0;//a,b:counters
    vector<int>T;//T:thief
    vector<int>P;//P:police
    for(int i=0;i<Size;i++)//divide characters of the array to 2 vectors :one for thief and one for police and storing their values .
    {
        if(PT[i]=='p')
            P.push_back(i);
        else if (PT[i]=='t')
            T.push_back(i);
    }
    while(a<T.size()&&a<P.size())
    {
        if(abs(T[a]-P[b])<=d)//abs:to return the absolute value
        {
            a++;
            b++;
            caught++;
        }
        else if (T[a]<P[b])
            a++;
        else
            b++;
    }
    return caught;
}



int main()
{
    int d=1,Size;
    char PT[] ={'p','t','t','p','t'};
    Size=sizeof(PT)/sizeof(PT[0]);
    cout << "the maximum number of thieves can  caught by police :" << endl;
    cout<<FindThiefs(PT,Size,d)<<endl;
    return 0;
}
