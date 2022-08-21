#include<iostream>
using namespace std;
#define N 9
void printSudoko(int arr[9][9]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isSafe(int arr[9][9],int row,int col,int num){
    for(int i=0;i<N;i++){
        if(arr[row][i]==num)
            return false;
    }
    for(int i=0;i<N;i++){
        if(arr[i][col]==num)
            return false;
    }
    int rowStart=row-row%3;int colStart=col-col%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[rowStart+i][colStart+j]==num)
                return false;
        }
    }
    return true;
}
bool solveSudoko(int arr[9][9], int row, int col){
    if(row==N-1 && col==N){
        return true;
    }
    if(col==N){
        row++;
        col=0;
    }
    if(arr[row][col]>0)
        return solveSudoko(arr,row,col+1);
    for(int num=1;num<=N;num++){
        if(isSafe(arr,row,col,num)){
            arr[row][col]=num;
            if(solveSudoko(arr,row,col+1))
                return true;
        }
        arr[row][col]=0;
    }
    return false;
}
int main(){
    int arr[N][N]={ { 0, 0, 0, 9, 0, 0, 0, 6, 7 },
					{ 0, 9, 0, 0, 0, 0, 2, 0, 8 },
					{ 4, 6, 0, 0, 7, 8, 0, 0, 0 },
					{ 3, 2, 0, 0, 9, 4, 0, 7, 0 },
					{ 7, 0, 0, 6, 0, 3, 0, 0, 2 },
					{ 0, 1, 0, 7, 8, 0, 0, 4, 3 },
					{ 0, 0, 0, 8, 5, 0, 0, 1, 6 },
					{ 5, 0, 1, 0, 0, 0, 0, 9, 0 },
					{ 6, 7, 0, 0, 0, 9, 0, 0, 0 } };
    solveSudoko(arr,0,0);
    printSudoko(arr);
}
//final task need to done
//done my changes
