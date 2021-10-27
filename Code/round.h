#include "team.h"
//This represent the shutdown between 2 teams

class Round
{
    private:
    Team t1,t2;
    
    public:
    Team get_win_team(); //return the winnig team
    Team get_lose_team(); //return the losing team

    void set_round(const Team&, const Team&);//helps setting the round

    friend ostream& operator <<(ostream &, Round&);//redefine this operator to make my life easier
    friend ofstream& operator <<(ofstream &, Round&);//redefine this operator to make my life easier


};