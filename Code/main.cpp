#include "team.h"

int main()
{
    ifstream file_in("d.in");
    Team *teams;
    //Player *pl;


    int number_of_teams,number_of_members;
    string n;
    file_in>>number_of_teams;
    cout<<number_of_teams<<endl;
    //file_in>>number_of_members;
    if (teams != NULL)
    {
        delete [] teams;
    }
    teams = new Team[number_of_teams];

    for(int i = 0; i < number_of_teams; i++)
    {
        file_in>>teams[i];
        cout<<teams[i]<<endl;
    }
    /*teams = new Team[number_of_teams];

    for(int i = 0; i < number_of_teams; i++)
    {
        file_in>>teams[i];
    }

    
    for(int i = 0; i < number_of_teams; i++)
    {
        cout<<teams[i];
    }*/

    file_in.close();
    return 0;
}