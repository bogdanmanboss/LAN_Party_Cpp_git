#include "team.h"
#include "round.h"
#include <list>
#include <iterator>
#include <queue>


int number_of_needed_teams(int number_teams)
{
    int i;
    for(i = 2; i <= number_teams; i = i*2)
    {
        ;
    }
    return i/2;
}

float get_min_score(list <Team> l)
{
    float min = 1000;
    for(auto it = l.begin(); it != l.end(); it++)
    {
        if(min > it->get_team_score())
        {
            min = it->get_team_score();
            //cout<<min<<endl;
        }
    }
    return min;
}

int main()
{
    ifstream file_in("d.in");
    Team *teams;
    //Player *pl;


    int number_of_teams,number_of_members;
    string n;
    list <Team> list_of_teams;

    file_in>>number_of_teams;
    //cout<<number_of_teams<<endl;

    //file_in>>number_of_members;
    teams = new Team[number_of_teams];

    for(int i = 0; i < number_of_teams; i++)
    {
        file_in>>teams[i];
        list_of_teams.push_front(teams[i]);
        //cout<<teams[i]<<endl;
    }

    float score, min_score;
    while(list_of_teams.size() != number_of_needed_teams(number_of_teams))
    {
        min_score = get_min_score(list_of_teams);
        for(auto it = list_of_teams.begin(); it != list_of_teams.end(); it++)
        {
            score = it->get_team_score();
            if(score == min_score)
            {
                list_of_teams.erase(it);
                break;
            }
        }
    }
    //float score;
    for(auto it = list_of_teams.begin(); it != list_of_teams.end(); it++)
    {
        cout<<it->get_team_name()<<endl;
    }
    
    cout<<endl;

    Round r;
    Team t1, t2;

    for(auto it = list_of_teams.begin(); it != list_of_teams.end(); it++)
    {
        t1 = *it;
        it++;
        t2 = *it;
        r.set_round(t1,t2);

        cout<<r;
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