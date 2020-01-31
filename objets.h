#include<iostream>
#include<string>
#include<time.h>
using namespace std;


class Objet {
    protected :
    string nom {};
    public :
    Objet (string n): nom(n){}

};

class Potion : public Objet {
    private :
    int soin;
    int prix;

    public :
    tableau={{"pomme","potion mystère"},{"pomme","pates","potion mystère"},{"super potion","potion","potion mystère"},{"super potion mystère"}};

    Potion (string n,int p,int pr): Item(n), prix(pr),soin(p){}

    Potion(int niveau){
        int n = tableau[niveau].size();
        x= rand()%n;
        string a = tableau[niveau][x];
        switch(a){
            case "pomme":
                soin =2;
                prix=2;
                break;
            case "potion mystère":
                int y = rand()10 -3
                force =5;
                prix=4;
                break;
            case "dague":
                force =6;
                prix=10;
                break;
            case "poèle":
                force =7;
                prix=10;
                break;
            case "four":
                force =8;
                prix=16;
                break;
            case "oreiller":
                force =8;
                prix=15;
                break;
            case "extincteur":
                force =10;
                prix=20;
                break;
            case "épée":
                force =10;
                prix=25;
                break;
            case "feux d'artifice":
                force =13;
                prix=50;
                break;
            case "palum":
                force =15;
                prix=75;
                break;
            
        }
};

class Arme : public Objet {
    private :
    int attaque;
    int prix;
    vector<vector<string>> tableau;

    public :
    tableau={{"baton","balais à chiotte"},{"baton","dague","poèle"},{"four","oreiller"},{"extincteur","épée"},{"feux d'artifice","palum"}};
    
    Arme(string n , int f, int pr): Item(n), attaque (f), prix(pr){}

    Arme(int niveau){
        int n = tableau[niveau].size();
        x= rand()%n;
        string a = tableau[niveau][x];
        switch(a){
            case "baton":
                force =3;
                prix=2;
                break;
            case "balais à chiotte":
                force =5;
                prix=4;
                break;
            case "dague":
                force =6;
                prix=10;
                break;
            case "poèle":
                force =7;
                prix=10;
                break;
            case "four":
                force =8;
                prix=16;
                break;
            case "oreiller":
                force =8;
                prix=15;
                break;
            case "extincteur":
                force =10;
                prix=20;
                break;
            case "épée":
                force =10;
                prix=25;
                break;
            case "feux d'artifice":
                force =13;
                prix=50;
                break;
            case "palum":
                force =15;
                prix=75;
                break;
            
        }
        
        
    }
    

};

class Armure : public Objet {
    private :
    int pa;
    int prix;

    public :
    Armure (string n, int p, int pr) :Item(n), pa(p),prix(pr){}

    
};

int main(){

    Armure a1 ("armure",1,10);

    return 0;
};