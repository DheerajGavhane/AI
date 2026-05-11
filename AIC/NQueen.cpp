#include<iostream>
#include<vector>
using namespace std;

class NQueen
{
    int N;
    vector<vector<int>> board;
    
public:

    NQueen(int n)
    {
        N=n;
        board.resize(N,vector<int>(N,0));
    }

    bool isSafe(int row,int col)
    {

        // Check upper column
        for(int i=0;i<row;i++)
        {
            if(board[i][col]==1)
                return false;
        }

        // Check left diagonal
        for(int i=row,j=col;i>=0 && j>=0;i--,j--)
        {
            if(board[i][j]==1)
                return false;
        }

        // Check right diagonal
        for(int i=row,j=col;i>=0 && j<N;i--,j++)
        {
            if(board[i][j]==1)
                return false;
        }

        return true;
    }

    bool solve(int row)
    {

        // All queens placed
        if(row==N)
            return true;

        for(int col=0;col<N;col++)
        {

            if(isSafe(row,col))
            {

                board[row][col]=1;

                if(solve(row+1))
                    return true;

                // Backtracking
                board[row][col]=0;
            }
        }

        return false;
    }

    void printBoard()
    {

        for(int i=0;i<N;i++)
        {

            for(int j=0;j<N;j++)
            {

                if(board[i][j]==1)
                    cout<<"Q ";
                else
                    cout<<". ";
            }

            cout<<endl;
        }
    }
};

int main()
{

    int n;

    cout<<"Enter number of queens: ";
    cin>>n;

    NQueen q(n);

    if(q.solve(0))
    {
        cout<<"\nSolution Exists:\n";
        q.printBoard();
    }
    else
    {
        cout<<"No Solution Exists";
    }

    return 0;
}