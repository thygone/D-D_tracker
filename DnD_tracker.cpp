#include<iostream>
#include<string>
#include<cmath>
#include"entity.h"
using namespace std;
 
/*
* program: D&D tracker
* By: Dane Selch
* purpose: to help DM's in tracking the combat occuring
*/

 
/* to do 
 * 1. main x
 * 2. setup x
 *      getplayers x
 *      getmonsters x
 *      getInitiative x
 *          order entities by initiative x
 * 3. play
 *      loop the game
 *      dealdamage(who, how much)
 *      rollDice(dice type, how many)
 *      kill() -- in entity 
 *          if player include death saves
 *      displayCurrentStates()
 *          each character
 *          their health, AC, initiative (display in that order too), stats
 *      
 */
entity turnOrder[10];

// popluate the entities that will be fighting
int getFighters(){
    int numbOfPlay;
    entity player;
    cout << "how many entities are participating in this fight?(max 10)";
    cin >> numbOfPlay;
    for (int i = 0; i < numbOfPlay; i++)
    {
        string sholder;
        int iholder;
        char cholder;
        cout << "y or n, is this a player?\n";
        cin >> cholder;
        if (cholder == 'y'){
            player.setPlayer(true);
            cout << "player\n";
        }
        else{
            cout << "NPC\n";
            player.setPlayer(false);
        }
        cout << "name:";
        cin >> sholder;
        cout << "HP";
        cin >> iholder;
        player.setName(sholder);
        player.setHp(iholder);
        cout << "AC";
        cin >> iholder;
        player.setAC(iholder);
        cout << "str";
        cin >> iholder;
        player.setStr(iholder);
        cout << "wis";
        cin >> iholder;
        player.setWis(iholder);
        cout << "dex";
        cin >> iholder;
        player.setDex(iholder);
        cout << "Con";
        cin >> iholder;
        player.setCon(iholder);

        turnOrder[i] = player;
    }
    return numbOfPlay;
}

// get the initiative of all characters in the game (npc or player alike)
void RollInitiative(entity bug){
    char roll;// yes or no
    int initiative; // number that is the initiative
    cout << "(y or n) shall we roll for " + bug.getName() + "\n";
    cin >> roll; // ask who to roll
    tolower(roll);
    if (roll == 'n'){
        cout << "what was the result? \n";
        cin >> initiative;
        bug.setInitiative(initiative%20+1);
        cout << endl;
    }else if (roll == 'y'){ // us rolling
        initiative = rand() % 20 + 1;
        cout << "\ninttiative is ";
        cout << initiative;
        bug.setInitiative(initiative%20);
        cout << endl;
    }else{ // error 
        cout << "\nan error occured so we rolled for you"; // inform of issue and proceed with random number
        initiative = rand() % 20 + 1;
        cout << "\nintiative is ";
        cout << initiative;
        bug.setInitiative(initiative%20);
        cout << endl;
    }
    
}

// organize the turnorder by highest to lowest initiative
void setTurnOrder(int i){
    entity holderman;
    for (int j = i; j < i-1; j++){ // each person
        
        if (turnOrder[j].getInitiative() > turnOrder[j+1].getInitiative()){
            holderman = turnOrder[j]; 
            turnOrder[j] = turnOrder[j+1];
            turnOrder[j+1] = holderman;
        }
        }
    
}
/*
* method: setUp()
* purpose: this is to populate the entities that will be fighting.
*/
int setUp(){
    int numbOfEntities = getFighters();
    for (int i = 0; i < numbOfEntities; i++){
        RollInitiative(turnOrder[i]);
    }
    setTurnOrder(numbOfEntities);
    return numbOfEntities;
}

//displays all characters at start of the match
void displayAll(int turns){
    for (int i = 0; i < turns; i++){
        turnOrder[i].display(i);
    }

}

//displays the options available to the DM
void displayOptions(){
        cout << "\t 0. end encounter";
        cout << "\t 1. attack";
        cout << "\t 2. heal";
        cout << "\n\t 3. check stats";
        cout << "\t 4. che everyone's stats";
        cout << "\t 4. next player";
}

// conitnues the encounter till DM says stop. allowing all players to take turns
/* options for turn
* attack, heal, check stats, check ALL stats, next turn, end encounter.
*
*/
void play(int turns){
    int input;
    displayAll(turns);
    int turnID = 0;
    int otherPerson;
    int amount;
    do{ 
        turnOrder[turnID].display(turnID);
        cout << "\n\nthe turn of: " + turnOrder[turnID].name + " \n";
        displayOptions();
        cout << "\n select number:\n";
        cin >> input;
        switch (input)
        {
            case 1: // attack
                cout << "who we attacking? (insert turn #) \n";
                cin >> otherPerson;
                cout << "for how much?\n";
                cin >> amount;
                turnOrder[otherPerson-1].takeDamage(amount);
                cout << "new HP: ";
                cout << turnOrder[otherPerson-1].HP;
                break;
            case 2: //heal
                cout << "who we healing? (insert turn #) \n";
                cin >> otherPerson;
                cout << "for how much?\n";
                cin >> amount;
                turnOrder[otherPerson-1].Heal(amount);
                cout << "new hP: ";
                cout << turnOrder[otherPerson-1].HP;
                break;
            case 3: // show stats
                turnOrder[turnID].display(turnID);
                break;
            case 4: // show all stats
                displayAll(turns);
                break;
            case 5: //next turn
                turnID +=1 % turns;
                break;
            case 0: 
                cout << "thanks for playing";
                break;
            default: // an error occured if this shows
                cout << "\nI do not receginze that number as an option sorry\n";
                input = 0;
                break;
        }



    }while(input != 0);
}


/*
* method: main()
* purpose: this is a driver function
*/
int main(){

    int numb = setUp();
    play(numb);

    return 0;
 }