
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));
    int n,k;
    cout<<"değerleri girin:"<<endl;
    //We enter 2 values, n is the size of the square matrix, and k is how many times to compare.
    cin>>n>>k;
    int random[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            random[i][j] = rand() % 2;
            cout<<random[i][j];
        }
        cout<<endl;
    }
    cout<<endl<<"çıktı"<<endl;
    for(int x = 1; x <= k; x++){
      
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          //condition that checks the elements in the first row of the matrix
          if(i == 0){
            if(random[i][j] == random[i][j+1]){
              if(random[i][j]==0)
                random[i][j]=1;
              else
                random[i][j]=0;
            }
            //Compares the values in the first row with the values above it, that is, with the values in the bottom row of the matrix.
            else if(j+1 != n && random[i][j] == random[n-1][j+1]){
              if(random[i][j]==0)
                random[i][j]=1;
              else
                random[i][j]=0;
            }
            //Condition written to compare the value in the first row and the rightmost side of the matrix.
            else if(j+1 == n && random[i][j] == random[n-1][0]){
              if(random[i][j]==0)
                random[i][j]=1;
              else
                random[i][j]=0;
            }
            //Compares the element at the end of the first line with the element at the beginning of a sub-line
            else if(j+1 == n){
              if(random[i][j] == random[i+1][0]){
                if(random[i][j]==0)
                random[i][j]=1;
              else
                random[i][j]=0;
              }
            }
          }
          //checks rows other than the first row of the matrix
          if(i != 0){ 
            if(j+1 != n && (random[i][j] == random[i][j+1] || random[i][j] == random[i-1][j])){
              if(random[i][j]==0)
                random[i][j]=1;
              else
                random[i][j]=0;
            }
            //It checks the elements outside the first and last rows of the matrix and the rightmost elements.
            else if(j+1 == n && i+1 != n){
              if(random[i][j] == random[i+1][0] || random[i][j] == random[i-1][j]){
                if(random[i][j]==0)
                random[i][j]=1;
              else
                random[i][j]=0;
              }
            }
            //checks the lowest right element of the matrix
            else if(i+1 == n && j+1 == n){
              if(random[i][j] == random[0][0] || random[i][j] == random[i-1][j]){
                if(random[i][j]==0)
                random[i][j]=1;
              else
                random[i][j]=0;
              }
            }
          }
      }
    }
    
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<random[i][j];
        }
        cout<<endl;
    }
      return 0;
}
