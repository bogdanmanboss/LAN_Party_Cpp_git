#include "team.h"

Team::Team()
{
    number_of_members = 0;
    team_name = " ";
    teammates = NULL;
}

Team::Team(int number_of_members, string team_name, Player* teammates)
{
    this->number_of_members = number_of_members;
    this->team_name = team_name;
    if (number_of_members>0 && teammates != NULL)
    {
        this->teammates = new Player[number_of_members];
        for(int i = 0; i < number_of_members;i++)
        {
            this->teammates[i] = teammates[i];
        }
    }
    else
    {
        this->teammates = NULL;
    }
}

Team::Team(const Team& T)
{
    number_of_members = T.number_of_members;
    team_name = T.team_name;
    if(T.number_of_members > 0 && T.teammates != NULL)
    {
        teammates = new Player[T.number_of_members];
        for(int i = 0; i < T.number_of_members; i++)
        {
            teammates[i] = T.teammates[i];
        }
    }
    else
    {
        teammates = NULL;
    }
}

Team& Team::operator=(const Team& T)
{
    number_of_members = T.number_of_members;
    team_name = T.team_name;
    if(T.number_of_members > 0 && T.teammates != NULL)
    {
        teammates = new Player[T.number_of_members];
        for(int i = 0; i < T.number_of_members; i++)
        {
            teammates[i] = T.teammates[i];
        }
    }
    else
    {
        teammates = NULL;
    }

    return *this;
}

ifstream& operator >>(ifstream& file_in, Team& T)
{
    
    file_in>>T.number_of_members;
    getline(file_in, T.team_name);
    T.team_name.erase(0,1);
    if(T.teammates != NULL)
    {
        delete [] T.teammates;
    }
    T.teammates = new Player[T.number_of_members];
    for(int i = 0; i < T.number_of_members; i++)
    { 
         
        file_in>>T.teammates[i];
        //cout<<"here"<<endl;
        
    }
    return file_in;
}

ofstream& operator <<(ofstream& file_out, const Team& T)
{
    file_out<<T.number_of_members<<endl;
    file_out<<T.team_name<<endl;
    for(int i = 0; i<T.number_of_members; i++)
    {
        file_out<<T.teammates[i];
    }

    return file_out;
}

ostream& operator <<(ostream& console_out, const Team& T)
{
    console_out<<T.number_of_members<<endl;
    console_out<<T.team_name<<endl;
    //cout<<"here"<<endl;
    for(int i = 0; i<T.number_of_members; i++)
    {
        console_out<<T.teammates[i];
    }

    return console_out;
}

float Team::get_team_score()
{
    float total = 0.0;
    for(int i = 0; i < number_of_members; i++)
    {
        total = total + teammates[i].get_score(); 
    }
    return total/(float)number_of_members;

}

string Team::get_team_name()
{
    return team_name;
}

Team::~Team()
{
    if (teammates != NULL)
    {
        delete[] teammates;
    }
}

void Team::modify_team_score()
{
    for(int i = 0; i < number_of_members; i++)
    {
        teammates[i].modify_score();
    }
}