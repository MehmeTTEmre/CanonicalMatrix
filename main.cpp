
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));
    int n,k;
    cout<<"değerleri girin:"<<endl;
    //2 değer gireriz n değeri kare matrisinin büyüklüğü, k değeri ise kaç kere kıyaslama yapılacağıdır.
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
          //matrisin ilk satırındaki elemanları kontrol eden koşuldur
          if(i == 0){
            if(random[i][j] == random[i][j+1]){
              if(random[i][j]==0)
                random[i][j]=1;
              else
                random[i][j]=0;
            }
            //ilk satırdaki değerleri üstündeki değerler ile yani matrisin en alt satırındaki değerler ile kıyaslar
            else if(j+1 != n && random[i][j] == random[n-1][j+1]){
              if(random[i][j]==0)
                random[i][j]=1;
              else
                random[i][j]=0;
            }
            //matrisin ilk satırındaki ve en sağ tarafındaki değeri kıyaslamak için yazılan koşuldur 
            else if(j+1 == n && random[i][j] == random[n-1][0]){
              if(random[i][j]==0)
                random[i][j]=1;
              else
                random[i][j]=0;
            }
            //ilk satırın sonundaki elemanı bi alt satırın başındaki eleman ile kıyaslar
            else if(j+1 == n){
              if(random[i][j] == random[i+1][0]){
                if(random[i][j]==0)
                random[i][j]=1;
              else
                random[i][j]=0;
              }
            }
          }
          //matrisin ilk satırı dışındaki satırları kontrol eder
          if(i != 0){ 
            if(j+1 != n && (random[i][j] == random[i][j+1] || random[i][j] == random[i-1][j])){
              if(random[i][j]==0)
                random[i][j]=1;
              else
                random[i][j]=0;
            }
            //matrisin ilk ve son satırları dışındaki ve en sağ taraftaki elemanların kontrolünü yapar
            else if(j+1 == n && i+1 != n){
              if(random[i][j] == random[i+1][0] || random[i][j] == random[i-1][j]){
                if(random[i][j]==0)
                random[i][j]=1;
              else
                random[i][j]=0;
              }
            }
            //matrisin en alt sağ elemanının kontrolünü yapar
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
