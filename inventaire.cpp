#include<iostream>
#include<vector>
#include"personnage.h"

using namespace std;

vector<vector<string>> inventaire (Heros perso){
    vector<vector<string>> invent ;
    vector<string> menu {"1 - Potions","2 - Armes","3 - Armures"};
    invent.push_back(menu);
    
    vector<string> pot;
    
    pot.push_back("1 - pomme --------------- "+to_string(perso.inventaire_potion[0])=" restant");
    pot.push_back("1 - pates --------------- "+to_string(perso.inventaire_potion[1])=" restant");
    pot.push_back("1 - potion mystère------- "+to_string(perso.inventaire_potion[2])=" restant");
    pot.push_back("1 - super potion--------- "+to_string(perso.inventaire_potion[3])=" restant");
    pot.push_back("1 - super potion mystère- "+to_string(perso.inventaire_potion[4])=" restant");

    invent.push_back(pot);


    vector<string> armu;

    int n_armu=perso.Armures.size();
    for (int i=0;i<n_armu;i++){
        string x;
        x=to_string(i)+"-";
        x+=perso.Armures[i]->nom;
        armu.push_back(x);
    }

    invent.push_back(armu);


    vector<string> arm;

    int n_arm=perso.Armes.size();
    for (int i=0;i<n_arm;i++){
        string x;
        x=to_string(i)+"-";
        x+=perso.Armes[i]->nom;
        arm.push_back(x);
    }

    invent.push_back(arm);

    return invent;
}

int main(){

    return 0;
}
