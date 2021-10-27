#include "player.h"
//nothing special here
//basic things
int Player::get_score()
{
    return score;
}

ifstream& operator >> (ifstream& file_in, Player& P)
{
    
    file_in>>P.firstName;
    //cout<<"here2"<<endl;
   // cout<<"here2"<<endl<<P.firstName<<endl;
    file_in>>P.secondName;
    file_in>>P.score;
    return file_in;

}

ostream& operator << (ostream& console_out, const Player& P)
{
    console_out<<P.firstName<<" "<<P.secondName<<" "<<P.score<<endl;
    return console_out;
}

ofstream& operator << (ofstream& file_out, const Player& P)
{
    file_out<<P.firstName<<" "<<P.secondName<<" "<<P.score<<endl;
    return file_out;
}

void Player::modify_score()
{
    score = score + 1;
}