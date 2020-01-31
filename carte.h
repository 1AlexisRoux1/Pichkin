#ifndef CARTE_H
#define CARTE_H

#include<iostream>
#include<vector>
#include<fstream>
#include<ncurses.h>
#include<map>
#include<string>
#include"personnage.h"
#include"Monstres.h"
#include"objets.h"

using namespace std;

class Carte{
    private:
        vector<char> bestiaire;
    public:
        int etage;
        vector<vector<char>> terrain;
        vector<Ennemi*> ennemis;
        Heros heros;
        int x_max;
        int y_max;
        map<string,char> image;

    vector<vector<char>> lecture (int n){ //prend en argument un niveau et renvoie un tableau avec la map
        vector<vector<char>> vmap{};
        string adress;
        adress = "map/niveau"+to_string(n)+".txt";
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
    void rafraichir(WINDOW* win) {
        for (int x = 0 ; x<x_max ; x++ ) {
            for (int y = 0 ; y<y_max ; y++) {
            mvwaddch(win, x, y, terrain[x][y]);
            }
        }
        wrefresh(win) ;
    }
    bool in_bestiaire (char e){
        vector<Ennemi>::iterator it = find(bestiaire.begin(),bestiaire.end(),e);
        return it != bestiaire.end();
    }
    Carte (int n, Heros h): etage{n},heros{h} {
        image["heros"] = 'H';
        image["sol_salle"] = '.';
        image["sol_couloir"] = '#';
        image["porte"] = '+';
        image["escalier"] = '=';
        image["arme"] = '!';
        image["armure"] = 'T';
        image["potion"] = 'j'
        terrain = lecture(n);
        x_max = terrain.size();
        y_max = terrain[0].size();
        bestiaire = {'C','J','V','O','A','P','B','6'}
        for (int x = 0; x < x_max; x++){
            for (int y = 0; y < y_max; y++){
                if (terrain[x][y] == image["heros"]){
                        heros.x = x;
                        heros.y = y;
                }
                elif (in_bestiaire(terrain[x][y])){
                        Ennemi* enn = new Ennemi(x,y,terrain[x][y]);
                        ennemis.push_back(enn);
                }
            }
        }
    }
    string deplacement(int x_rel, int y_rel){
        int x = heros.x;
        int y = heros.y;
        char case_suivante = terrain[x + x_rel][y + y_rel]
        if (case_suivante == image["sol_salle"]){
                heros.x += x_rel;
                heros.y += y_rel;
                terrain[x][y] = heros.sol;
                heros.sol = image["sol_salle"];
                terrain[heros.x][heros.y] = image["heros"];
                return "Je suis dans une salle !";
        }
        elif (case_suivante == image["sol_couloir"]){
                heros.x += x_rel;
                heros.y += y_rel;
                terrain[x][y] = heros.sol;
                heros.sol = image["sol_couloir"];
                terrain[heros.x][heros.y] = image["heros"];
                return "Je suis dans un couloir !";
        }
        elif (case_suivante == image["porte"]){
                heros.x += x_rel;
                heros.y += y_rel;
                terrain[x][y] = heros.sol;
                heros.sol = image["porte"];
                terrain[heros.x][heros.y] = image["heros"];
                return "Je passe une porte !";
        }
        elif (case_suivante == image["escalier"]){
                heros.x += x_rel;
                heros.y += y_rel;
                terrain[x][y] = heros.sol;
                heros.sol = image["escalier"];
                terrain[heros.x][heros.y] = image["heros"];
                return "Je suis sur un escalier !";
        }
        elif (case_suivante == image["arme"]){
                heros.x += x_rel;
                heros.y += y_rel;
                terrain[x][y] = heros.sol;
                heros.sol = image["sol_salle"];
                terrain[heros.x][heros.y] = image["heros"];
                Arme* arme = new Arme (heros.niveau);
                heros.equiper_arme(arme);
                return "J'ai un(e)"+ arme.nom +" !";
        }
        elif (case_suivante == image["armure"]){
                heros.x += x_rel;
                heros.y += y_rel;
                terrain[x][y] = heros.sol;
                heros.sol = image["sol_salle"];
                terrain[heros.x][heros.y] = image["heros"];
                Armure* armure = new Armure (heros.niveau);
                heros.equiper_armure(armure);
                return "J'ai un(e)"+ armure.nom +" !";
        }
        elif (case_suivante == image["potion"]){
                heros.x += x_rel;
                heros.y += y_rel;
                terrain[x][y] = heros.sol;
                heros.sol = image["sol_salle"];
                terrain[heros.x][heros.y] = image["heros"];
                Potion* potion = new Potion (heros.niveau);
                heros.ramasser_potion(potion);
                return "J'ai un(e)"+ potion.nom +" !";
        }
        

    }
    string haut(){
        return deplacement(-1, 0);
    }
    string bas(){
        return deplacement(1, 0);
    }
    string gauche(){
        return deplacement (0,-1);
    }
    string droite(){
        return deplacement (0, 1);
    }
    int escalier(){
        if (terrain[heros.x][heros.y] == image["escalier"]){
            return +1;
        }
        else {
            return 0;
        }
    }
};

#endif