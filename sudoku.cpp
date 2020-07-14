#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int h=0;
void printMatrix (vector <vector <int>> &a){
    
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j]<<" ";

        }
        cout<<"\n";
    }
    
}
void printVector(vector <int> a){
    cout<<"\n";
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}
vector <int> possibleNum(vector <vector <int>> &a,int row, int col){
    vector<int > r,c,s,ok;
    int sqr,sqc;
    for(int i=0;i<9;i++){
        if(a[row][i]!=0) r.push_back(a[row][i]);
        if(a[i][col]!=0) c.push_back(a[i][col]);
    }
   
    if(row<3) sqr=0;
    else if(row<6) sqr=3;
    else sqr=6;
    if(col<3) sqc=0;
    else if(col<6) sqc=3;
    else sqc=6;
    
    for(int i=sqr;i<sqr+3;i++){
        for(int j=sqc;j<sqc+3;j++){
            if(a[i][j]!=0) s.push_back(a[i][j]);
        }
    }
    
    for(int i=1;i<10;i++){
        if(find(r.begin(),r.end(),i)==r.end() && find(c.begin(),c.end(),i)==c.end() && find(s.begin(),s.end(),i)==s.end()) ok.push_back(i);
    }
    return ok;

}
vector <int> nextEmpty(vector <vector <int>> &a,int row,int col){
    int flag=0;
    vector<int> a1;
    while(flag==0){   
        if((col==8)&&(row<8)){ row++; col=0;} 
        else if(col<8) col++;
        
        if(a[row][col]==0)
         flag=1;
        else if((row==8) && (col==8)) return a1 ;
    
    }
    a1.push_back(row);
    a1.push_back(col);
    return a1;
}
int solve_sudoku (vector <vector <int>> &a,int row,int col){
    
    vector<int> possible=possibleNum( a,row,col),next;
    
    if(possible.size()==0)
        return 0;
    for(int i=0;i<possible.size();i++){
        a[row][col]=possible[i];
        next=nextEmpty(a,row,col);
        if(next.size()==0)
            return 1;
        h++;
        if(solve_sudoku(a,next[0],next[1])!=1){
            a[row][col]=0;
            h--;
        }
        else{ 
            if(h==62) printMatrix(a);
            cout<<h<<"\n";
             return 1;
        }
        if(i==possible.size()-1)
            return 0;
    }
    return 1;
}
int main(){
    vector <vector <int>> a;
    int n=9,n_copy=9;
    while(n--){
        vector <int > b1;
        while(n_copy--){
            int c;
            cout<<n<<" "<<n_copy<<": ";
            cin>>c;
            b1.push_back(c);
        }
        n_copy=9;
        a.push_back(b1);
    }
    vector <int >a1;
    if(a[0][0]!=0){
        a1=nextEmpty(a,0,0);
        solve_sudoku(a,a1[0],a1[1]);
    }
    else{
        solve_sudoku(a,0,0);
    }
    cout<<"\n\n in main\n";
    printMatrix(a);

    return 0;
}