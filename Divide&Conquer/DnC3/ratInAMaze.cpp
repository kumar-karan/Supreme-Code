#include<iostream>
using namespace std;

// ! Rat in a maze

// ^ rat ko source se destination leke jaana hai 
// ^ Find all solutions to reach the destination

//* 0 means way is blocked, 1 means its opened
//* DLRU move krskte bas
//* Already visited dabbe pe ni jaana

// Down -> i+1, L -> j-1, R -> j+1, U = i-1;

bool isSafe(int i, int j, int row, int col, int arr[][3],vector<vector <bool>> &visited )
{
    if((i >= 0 && i< row) && (j >=0 && j<col) && (arr[i][j] == 1) && (visited[i][j] == false))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solveMaze (int arr[3][3], int row,int col, int srcx, int srcy, vector<vector <bool>> &visited, vector<string>&path, string output )

{
    if( srcx == row-1 && srcy == col-1)
    {
        path.push_back(output);
        return;
    }

    // Down -> i+1 ,j
    if(isSafe(srcx+1, srcy, row, col, arr, visited))
    {
        visited[srcx+1][srcy] = true;
        solveMaze(arr,row ,col, srcx+1, srcy, visited, path, output+'D');
        visited[srcx+1][srcy] = false;

    }
    // Left -> i, j-1
    if(isSafe(srcx, srcy-1, row, col, arr, visited))
    {
        visited[srcx][srcy-1] = true;
        solveMaze(arr,row ,col, srcx, srcy-1, visited, path, output+'L');
        visited[srcx][srcy-1] = false;

    }
    // Right -> i, j+1
    if(isSafe(srcx, srcy+1, row, col, arr, visited))
    {
        visited[srcx][srcy+1] = true;
        solveMaze(arr,row ,col, srcx, srcy+1, visited, path, output+'R');
        visited[srcx][srcy+1] = false;

    }

    // Up -> i-1, j
    if(isSafe(srcx-1, srcy, row, col, arr, visited))
    {
        visited[srcx-1][srcy] = true;
        solveMaze(arr,row ,col, srcx-1, srcy, visited, path, output+'U');
        visited[srcx-1][srcy] = false;

    }

}

int main()
{
    int maze[][3]= {{1,0,0},
                    {1,1,0},
                    {1,1,0} };
    if(maze[0][0] == 0)
    {
        cout<< "NO PATH EXISTS" <<endl;
        return 0;
    }

    int row = 3;
    int col = 3;

    vector<vector <bool>> visited (row, vector<bool>(col, false));
    visited[0][0] = true;

    vector<string> path;
    string  output =""; // answer

    solveMaze(maze, row,col, 0,0, visited, path, output);

    cout << "Printing the results" << endl;
    for(auto i: path)
    {
        cout << i << " ";
    }
    cout << endl;

    if(path.size() == 0)
    {
        cout<< "NO PATH EXISTS" <<endl;
        return 0;
    }


    return 0;
}