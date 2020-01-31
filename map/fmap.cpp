#include<iostream>
#include<vector>
#include<fstream>
using namespace std;


vector<vector<char>> lecture (int n){ //prend en argument un niveau et renvoie un tableau avec la map
    vector<vector<char>> vmap{};
    string adress;
    adress = "niveau"+to_string(n)+".txt";
    ifstream data{adress};
    
    int x;
    int y;
    data >> x;
    data >> y;

    
    char c;
    data.get(c);

    for (int i=0;i<y;i++){
        vector<char> ligne;
        for(int j=0;j<x;j++){
            data.get(c);
            ligne.push_back(c);
        }
        data.get(c);
        vmap.push_back(ligne);
    }


    data.close();
    return vmap;
}


void vaff(vector<vector<char>> vect){
    int n=vect.size();
    int m=vect[0].size();
    for (int i=0;i<n;i++){
        
        for(int j=0;j<m;j++){
            cout<<vect[i][j];
        }
        cout<<endl;
    }
}



int main(){

    vector<vector<char>> vect;

    vect=lecture(0);

    vaff(vect);
    


    return 0;
}