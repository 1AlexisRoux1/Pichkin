#ifndef OBJETS_H
#define OBJETS_H

#include<iostream>
#include<string>
#include<time.h>
#include<vector>
using namespace std;


class Objet {
    
    public :
    string nom {};
    Objet (string n): nom(n){}
    Objet(){}

};

class Potion : public Objet {
    
    public :
    int soin;
    int prix;
    string effet;
    vector<vector<string>> tableau={{"pomme","potion mystère"},{"pomme","pates","potion mystère"},{"super potion","potion mystère"},{"super potion mystère"},{"super potion mystère"}};

    Potion (string n,int p,int pr): Objet(n), prix(pr),soin(p){}

    Potion(int niveau){
        int n = tableau[niveau].size();
        int x= rand()%n;
        string a = tableau[niveau][x];
        if(a=="pomme"){
            Objet("pomme");
            soin =2;
            prix=2;
            effet= "vous mangez une pomme, cela vous rend 2 points de vie";
            }
        if (a=="potion mystère"){
            Objet("potion mystère");
            int y = rand()%10 -3;
            soin =y;
            prix=1;
            if (y>=0){
                effet="vous buvez de la potion mystère : vous gagnez"+to_string(y)+" points de vie";}
            if (y<0){
                effet="vous prennez de la potion mystère : pas de chance vous perdez "+to_string(y)+" point de vie";}
            }

            
        if(a=="pates"){
            Objet("pates");
            soin=5;
            prix=10;
            effet="vous mangez un plat de pates, vous gagnez 5 points de vie";}
            
        if(a=="super potion"){
            Objet("super potion");
            soin =10;
            prix=20;
            effet="vous prennez de la super potion, vous gagnez 10 points de vie";}
            
        if(a=="super potion mystère"){
            Objet("super potion mystère");
            int y = rand()%20 -10;
            soin=8;
            prix=16;
            if (y>=0){
                effet="vous buvez de la super potion mystère : vous gagnez"+to_string(y)+" points de vie";}
            if (y<0){
                effet="vous prennez de la potion mystère : pas de chance vous perdez "+to_string(y)+" point de vie";}
        }
            
                
        
    }
};

class Arme : public Objet {
    
    
    public :
    int attaque;
    int prix;
    
    vector<vector<string>> tableau={{"baton","balais à chiotte"},{"baton","dague","poèle"},{"four","oreiller"},{"extincteur","épée"},{"feux d'artifice","palum"}};
    
    Arme(string n , int f, int pr): Objet(n), attaque (f), prix(pr){}


    Arme(int niveau){
        int n = tableau[niveau].size();
        int x= rand()%n;
        string a = tableau[niveau][x];
        
        if(a=="baton"){
            Objet("baton");
            attaque =3;
            prix=2;}
            
        if(a=="balais à chiotte"){
            Objet("balais à chiotte");
            attaque =5;
            prix=4;}

        if(a=="dague"){
            Objet("dague");
            attaque =6;
            prix=10;}

        if (a=="poèle"){
            Objet("poèle");
            attaque =7;
            prix=10;}

        if(a=="four"){
            Objet("four");
            attaque =8;
            prix=16;}

        if (a=="oreiller"){
            Objet("oreiller");
            attaque =8;
            prix=15;}

        if(a=="extincteur"){
            Objet("extincteur");
            attaque =10;
            prix=20;}

        if(a=="épée"){
            Objet("épée");
            attaque =10;
            prix=25;}

        if(a== "feux d'artifice"){
            Objet("feux d'artifice");
            attaque =13;
            prix=50;}

        if(a=="palum"){
            Objet("palum");
            attaque =15;
            prix=75;}
            
        
        
        
    }
    

};

class Armure : public Objet {
    
    public :
    int protection;
    int prix;
    
    vector<vector<string>> tableau={{"drap"},{"drap","t-shirt centrale-supelec"},{"pull de la mine","t-shirt centrale-supelec"},{"costume Colvert","pull de la mine"},{"costume Colvert","pull de la mine"}};
    Armure (string n, int p, int pr) :Objet(n), protection(p),prix(pr){}

    Armure(int niveau){
        int n = tableau[niveau].size();
        int x= rand()%n;
        string a = tableau[niveau][x];
        
        if(a=="drap"){
            Objet("drap");
            protection=1;
            prix=1;}

        if(a=="t-shirt centrale-supelec"){
            Objet("t-shirt centrale-supelec");
            protection =-2;
            prix=5;}

        if(a=="pull de la mine"){
            Objet("pull de la mine");
            protection=10;
            prix=10;}

        if(a=="costume Colvert"){
            Objet("costume Colvert");
            protection =20;
            prix=100;}
            
        
    }
    
};



#endif
