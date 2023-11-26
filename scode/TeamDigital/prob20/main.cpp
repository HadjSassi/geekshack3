#include<iostream>
#include <iostream>
#include <cstdlib>
using namespace std;

char place[6][7];
int iPlayerTurn=1, turn, win;
int pos0=5, pos1=5, pos2=5, pos3=5, pos4=5, pos5=5, pos6=5;
int tie=0; 
char cPlayerMark; 

void drawBoard() // function to draw a board
{
cout << " 1   2   3   4   5   6   7" << endl;
for(int a=0; a<=5; a++)
{
for(int b=0; b<=6; b++)
cout << char(218) << char(196) << char(191) << " ";
cout<<'\n';
for(int b=0; b<=6; b++)
cout<<char(179)<<place[a][b]<<char(179)<<" ";
cout<<'\n';
for(int b=0; b<=6; b++)
cout<<char(192)<<char(196)<<char(217)<<" ";
cout<<'\n';
}
}
int checkwin() // totaly stuck here
{
}
int main()
{
drawBoard();
do
{
cout << "Player " << iPlayerTurn << " turn: " << endl;
cin >> turn;
if(iPlayerTurn == 1) // sets player mark between X and O
{
cPlayerMark = 'X';
}
else
{
cPlayerMark = 'O';
}
if(iPlayerTurn == 1) // after 1 move changes the player
{
iPlayerTurn = 2;}
else{
iPlayerTurn = 1;}
if(turn == 1){
place[pos0][0] = cPlayerMark;
pos0--; 
tie++;}
else if(turn == 2)
{
    place[pos1][1] = cPlayerMark;
pos1--;
tie++; }
else if(turn == 3)
{
place[pos2][2] = cPlayerMark;
pos2--;
tie++;}else if(turn == 4)
{ place[pos3][3] = cPlayerMark;
pos3--;
tie++;}
else if(turn == 5)
{
place[pos4][4] = cPlayerMark;
pos4--;
tie++;
}
else if(turn == 6)
{
place[pos5][5] = cPlayerMark;
pos5--;
tie++;}
else if(turn == 7){
place[pos6][6] = cPlayerMark;
pos6--;
tie++;
}
else
{
cout << "Wrong number." << endl; 
if(cPlayerMark == 'X')
{
iPlayerTurn = 1;
}
if(cPlayerMark == 'O')
{
iPlayerTurn = 2;
}
}
drawBoard();
}while(tie!=42);

}