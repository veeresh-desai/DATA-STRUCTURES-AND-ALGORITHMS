// You are using GCC
#include<iostream>
using namespace std;


const int MAX=100;
int p[MAX][MAX];
int adjmatrix[MAX][MAX];



void warshall(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            p[i][j]=adjmatrix[i][j];
        }
    }
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                p[i][j]=p[i][j]||(p[i][k]&&p[k][j]);
                
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main(){
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adjmatrix[i][j];
        }
    }
    warshall(n);
    
}













#include<iostream>
using namespace std;

const int MAX=10;
int p[MAX][MAX];
int adj[MAX][MAX];

void warshall(int n){
    for(int i=0;i<n;i++){
        for(j=0;j<n;j++){
            p[i][j]=adj[i][j];
        }
    }


    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                p[i][j]=p[i][j]||(p[i][k]&&p[k][j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<p[i][j];
        }
    }

}



int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }

    warshall(n);

}














