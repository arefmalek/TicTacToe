#include <iostream>
#include <string>

using namespace std;

//constantly checks entire board for 4 in a column
bool col_check4(int grid[6][7], int compNum)
{  
    for (int i  = 0; i< 7; i++)
    {
        int count = 0;
        for (int j = 0; j < 6; j++)
        {
            if(grid[j][i] == compNum)
            {
                //each time the number in the grid matches what we requested
                //the count increases
                count++;
                //if you got here, congrats!
                if(count==4)
                {
                    return true;
                }
            }
            //if it doesn't match once, we reset
            else
            {
                count = 0;
            }
        }
    } 
    return false;  
}

//constantly checks entire board for 4 in a row 
bool row_check4(int grid[6][7], int compNum)
{  
    for (int i  = 0; i< 6; i++)
    {
        int count = 0;
        for (int j = 0; j < 7; j++)
        {
            if(grid[i][j] == compNum)
            {
                //same thing as col chec, 
                //we checking how many times in a row we get same number
                count++;
                if(count==4)
                {
                    return true;
                }
            }
            //messes up once and we GONE
            else
            {
                count = 0;
            }
        }
    }
    return false;  
}

//constantly checks entire board for 4 in a row diagonally
bool diag_check4_downright(int grid[6][7], int compNum)
{
    //insert code here
    for (int i  = 0; i< 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int xpos = i;            
            int ypos = j;
            int count = 0;
            
            while (xpos < 7 && ypos <6)
            {
                if(grid[ypos][xpos] == compNum)
                {
                    //each time the number in the grid matches what we requested
                    //the count increases
                    count++;
                    //if you got here, congrats!
                    if(count==4)
                    {
                        return true;
                    }
                }

                else
                //if it doesn't match once, we reset
                {
                    count = 0;
                }

                xpos++;
                ypos++;
            }            
        }
    } 
    return false;   
}

bool diag_check4_upright(int grid[6][7], int compNum)
{
    //insert code here
    for (int i  = 0; i< 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int xpos = i;            
            int ypos = j;
            int count = 0;
            
            while (xpos < 7 && ypos > 0)
            {
                if(grid[ypos][xpos] == compNum)
                {
                    //each time the number in the grid matches what we requested
                    //the count increases
                    count++;
                    //if you got here, congrats!
                    if(count==4)
                    {
                        return true;
                    }
                }

                else
                //if it doesn't match once, we reset
                {
                    count = 0;
                }

                xpos++;
                ypos--;
            }            
        }
    } 
    return false;   
}

//calls methods for both checking row and column
bool four_check(int grid[6][7], int test_num)
{
    if (row_check4(grid,test_num)) return true;
    else if (col_check4(grid,test_num)) return true;
    else if (diag_check4_downright(grid, test_num)) return true;
    else if (diag_check4_upright(grid, test_num)) return true;
    else return false;
}

//prints initial starting grid of blank spaces
void printGrid(int grid[6][7])
{
    cout << endl;
    cout << "1234567" << endl;
    cout << "-------";
    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << "-------"<<endl;
    cout << "1234567" << endl;
    cout << endl;
    cout << endl;
}

//creates drop mechanic of Connect4 where piece must take lowest available //location
void placeToken(int grid[6][7], int colNum, int playerNum)
{
    for (int i = 5; i>=0; i--)
    {
        if(grid[i][colNum] == 0)
        {
            grid[i][colNum] = playerNum;
            cout<<"token dropped!"<< endl;
            break;
        }
    }


}

int main()
{
    int grid [6][7];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            grid[i][j] = 0;
        }
        
    }

    cout<< "empty board:" << endl;
    printGrid(grid);
  
//checks the win condition for both players 1 and 2 
   bool flag = (four_check(grid,1) || four_check(grid,2));
   int col;
   int cur_player = 1;


   while (!flag)
   {
// cycle back to player 1 after player 2’s turn
        if(cur_player>2)
            cur_player = 1;
        cout << "player " << cur_player <<", choose a column. (1-7)" << endl;
//enter column player wishes to drop piece in
        cin >> col;
        placeToken(grid, col-1, cur_player);
        printGrid(grid);
        cur_player+=1;
        flag = (four_check(grid,1) || four_check(grid,2));
        if(four_check(grid,1))
            cout<<"Player 1 has won the game!"<<endl;
        if(four_check(grid,2))
            cout<<"Player 2 has won the game!"<<endl;
    } 
 
    return 0;
}
