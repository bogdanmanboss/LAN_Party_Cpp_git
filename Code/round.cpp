#include "round.h"

Team Round::get_win_team()
{
    if(t1.get_team_score() >= t2.get_team_score())
    {
        t1.modify_team_score();
        return t1;
    }
    else
    {
        t2.modify_team_score();
        return t2;
    }
}

Team Round::get_lose_team()
{
    if(t2.get_team_score() < t1.get_team_score())
    {
        return t2;
    }
    else
    {
        return t1;
    }
}

void Round::set_round(const Team& t1, const Team& t2)
{
    this->t1 = t1;
    this->t2  =t2;
}

ostream& operator << (ostream& console_out, Round &r)
{
    console_out<<r.t1.get_team_name();
    for(int i = 0; i < 33 - r.t1.get_team_name().length(); i++)
    {
        console_out<<" ";
    }
    console_out<<"-";
    for(int i = 0; i < 33 - r.t2.get_team_name().length(); i++)
    {
        console_out<<" ";
    }
    console_out<<r.t2.get_team_name()<<endl;

    return console_out;
}