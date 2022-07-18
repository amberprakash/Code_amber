#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>>board,int r,int c,int move){
   if(r<0 || c<0 || r>=board.size() || c>=board.size() || board[r][c]>0){
       return;
   }
   else if(move==board.size()*board.size()){
       board[r][c]=move;
       for(int i=0;i<board.size();i++){
           for(int j=0;j<board.size();j++){
               cout<<board[i][j]<<" ";
           }
           cout<<endl;
       }
       cout<<endl;
       board[r][c]=0;
       return;
   }
   board[r][c]=move;
   solve(board,r-2,c+1,move+1);
   solve(board,r-1,c+2,move+1);
   solve(board,r+1,c+2,move+1);
   solve(board,r+2,c+1,move+1);
   solve(board,r+2,c-1,move+1);
   solve(board,r+1,c-2,move+1);
   solve(board,r-1,c-2,move+1);
   solve(board,r-1,c-1,move+1);
   board[r][c]=0;

}
int main(){
    int n;
    int r;
    int c;
    cin>>n>>r>>c;
    vector<vector<int>>board(n,vector<int>(n,0));
    solve(board,r,c,1);
    return 0;
}