#include<iostream>
#include <algorithm>
using namespace std;
//first i should sort the activities according to finish time (smallest finish time first)
//next i will print the first activity(always)
struct Activity
{
    int start, finish;
};
bool finishtimestorting(Activity A1, Activity A2)
{
    return (A1.finish < A2.finish);
}

void printActivities(Activity arr[], int no)
{
    sort(arr, arr + no, finishtimestorting);

    cout << "The answer is activities :\n";

    //i will print the first activity(always)
    int firstact= 0;
    cout << "(" << arr[firstact].start << ", " << arr[firstact].finish
         << ")";
    // compare the remaining activities
    for (int j = 1; j < no; j++)
    {
        // If this activity has start time greater than or
        // equal to the finish time of previously selected
        // activity, then select it
        if (arr[j].start >= arr[firstact].finish)
        {
            cout << ", (" << arr[j].start << ", "
                 << arr[j].finish << ")";
            firstact = j;
        }
    }
}

int main()
{
    int numofact;
    cout<<"enter the number of activities you'll add"<<endl;
    cin>>numofact;
    Activity arr[numofact];


    // int starttimevals[numofact];
    for(int i=0; i<numofact; i++)
    {
        cout<<"insert start time for activity: "<<i<<endl;
        cin>>arr[i].start;
    }
    //int finishtimevals[numofact];
    for(int i=0; i<numofact; i++)
    {
        cout<<"insert finish time for activity: "<<i<<endl;
        cin>>arr[i].finish;
    }


    printActivities(arr, numofact);
    return 0;
}
