#include<iostream>
#include<string>
using namespace std;


class Item {
    protected :
    string nom {};
    public :
    Item (string n): nom(n){}

};

class Potion : public Item {
    private :
    int pv;
    int prix;

    public :
    Potion (string n,int p,int pr): Item(n), prix(pr),pv(p){}
};

class Arme : public Item {
    private :
    int force;
    int prix;

    public :
    Arme(string n , int f, int pr): Item(n), force (f), prix(pr){}


};

class Armure : public Item {
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