#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int>vec={12,4,27,10,8};
    int n=vec.size();
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(vec[min]>vec[j])
            {
                min=j;
            }
        }
        int temp=vec[i];
        vec[i]=vec[min];
        vec[min]=temp;
    }
    for(auto val:vec)
    {
        cout<<val<<" ";
    }
    return 0;
}

/*
Greedy Method is a problem-solving technique used to solve optimization problems.
    An optimization problem is a problem where we need to find the maximum or minimum possible result.
It follows greedy approach because:
    At every step, it selects the locally smallest element.
Advantages of Selection Sort
    Simple to understand
    Easy implementation
    Requires less memory
    Performs well for small datasets
Disadvantages of Selection Sort
    Slow for large datasets
    Time complexity always O(n²)
    Not stable sorting algorithm
Applications of Selection Sort
    Educational purposes
    Small datasets
    Embedded systems
    Memory-constrained systems
*/