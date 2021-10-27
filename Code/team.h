#pragma once
#include "player.h"

class Team
{
    private:
    int number_of_members;
    string team_name;
    Player *teammates;

    public:
    //constructors
    Team();
    Team(int, string, Player*);
    Team(const Team&);
    //destructor
    ~Team();

    float get_team_score(); //calculates the score of the team : adds the score of all players than divide by the number of players
    string get_team_name(); //return the team name

    void modify_team_score(); //modify the score of all players by increasing the score of all players by 1 

    friend ifstream& operator >> (ifstream&, Team&);//redefine this operator to make my life easier
    friend ofstream& operator << (ofstream&, const Team&);  //redefine this operator to make my life easier
                                                            //didn't implemet because it is almost the same as the next

    friend ostream& operator << (ostream&, const Team&);//redefine this operator to make my life easier

    Team& operator = (const Team&);//redefine this operator to make my life easier


};
