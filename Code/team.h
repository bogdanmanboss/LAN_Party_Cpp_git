#pragma once
#include "player.h"

class Team
{
    private:
    int number_of_members;
    string team_name;
    Player *teammates;

    public:

    Team();
    Team(int, string, Player*);
    Team(const Team&);
    ~Team();

    float get_team_score();
    string get_team_name();

    void modify_team_score();

    friend ifstream& operator >> (ifstream&, Team&);
    friend ofstream& operator << (ofstream&, const Team&);
    friend ostream& operator << (ostream&, const Team&);

    Team& operator = (const Team&);


};
