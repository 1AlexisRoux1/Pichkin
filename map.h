#include<iostream>
#include<vector>
#include<fstream>
#include<ncurses.h>
#include<map>
#include<string>

using namespace std;


class Map{
    public:
        int num;
        vector<vector<char>> terrain;
        vector<Ennemi> ennemis;
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
            mvwaddch(win, y, x, terrain[x][y]);
            }
        }
        refresh() ;
    }
    Map (int n, Hero h): num{n},hero{h} {
        image["heros"] = 'H'
        image["cafard"] = 'C'
        image["sol_salle"] = '.'
        terrain = lecture(n);
        x_max = terrain.size;
        y_max = terrain[0].size;
        for (int x = 0; x < x_max; x++){
            for (int y = 0; y < y_max; y++){
                switch (terrain[x][y]){
                    case image["heros"]:
                        heros = Heros(x,y);
                    case image["cafard"] = 'C':
                        Cafard(x,y);
                }
            }
        }
    }
    void haut(){
        int x = heros.x;
        int y = heros.y;
        switch (terrain[x-1][y]){
            case image["sol_salle"]:
                heros.x --;
                terrain[x][y] = image["sol_salle"];
                terrain[x-1][y] = image["heros"];
            case 
        }

    }

}