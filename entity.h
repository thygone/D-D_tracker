#include<iostream>
#include<cmath>
#include<string>
using namespace std;

/*
--- to be used in later assignment maybe
class point { // holds the location on a map
       private: 
        int x;
        int y;
    public:
        point() {
            x = 0;
            y = 0;
        }
        point(int a, int b){
            x = a;
            y = b;
        }
        // getters
        int getx(){
            return x;
        }
        int gety(){
            return y;
        }
        //setters
        void setx(int a){
            x = a;
        }
        void sety(int b){
            y = b;
        }
};

*/

class entity  {
    public:
        string name;
        int HP;
        int initiative;
        bool player;
     
        int AC;
        int str;
        int dex;
        int wis;
        int con;
       
    
        //constructor
        entity(){
            name = "bob";
            HP = 10;
            initiative = 20;
            player = false;
            AC = 0;
            str = 0;
            dex = 0;
            wis = 0;
            con = 0;
          
        }
        
        entity(string nam, int health, int initiat, 
        bool play, int x, int y, int ac, int s, int d, int w, int co, int ch){
            name = nam;
            HP = health;
            initiative = initiat;
            player = play;
            AC = ac;
            str = s;
            dex = d;
            wis = w;
            con = co;
        
        }

        // getters
        string getName(){
            return name;
        }
        int getHP(){
            return HP;
        }
        int getInitiative(){
            return initiative;
        }
        bool getPlayer(){
            return player;
        }
        int getAC(){
            return AC;
        }
        int getStr(){
            return str;
        }
        int getWis(){
            return wis;
        }
        int getDex(){
            return dex;
        }
        int getCon(){
            return con;
        }
       
        //setters
        void setName(string nam){
            name = nam;
        }
        void setHp(int health){
            HP = health;
        }
        void setInitiative(int i){
            initiative = i;
        }
        void setPlayer(bool play){
            player = play;
        }
        void setAC(int a){
            AC = a;
        }
        void setStr(int strength){
            str = strength;
        }
        void setWis( int wisdom){
            wis = wisdom;
        }
        void setDex(int dextarity){
            dex = dextarity;
        }
        void setCon(int constitution){
            con = constitution;
        }
        
        // if damage is dealt
        void takeDamage(int pain){
            int newHP = this->getHP() - pain;
            setHp(newHP);
        }

        void Heal(int nutrients){
            int newHP = this->getHP() + nutrients;
            setHp(newHP);
        }
        
        // display
        void display(int turnID){
            int ID = turnID + 1;
            if (player == true){
                cout << endl;
                cout << ID;
                cout << ". Name " + this->name + " --- Player\n";
            } else{
                cout << endl;
                cout << ID;
                cout << ". Name " + this->name + " --- npc\n";
            }
            if (HP <= 0){
                cout << "DEAD";
            }else {
                cout << " HP ";
                cout << this->HP; 
                cout << " AC "; 
                cout << this->AC;
                cout << " str "; cout << this->str;
                cout << " dex "; cout << this->dex;
                cout << " wis "; cout << this->wis;
                cout << " Con "; cout << this->con;
            }


        }
};
