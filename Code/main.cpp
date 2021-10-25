#include "team.h"
#include "round.h"
#include <list>
#include <iterator>
#include <queue>
#include <stack>


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
        cout<<it->get_team_name()<<" "<<it->get_team_score()<<endl;
    }
    
    cout<<endl;

    Round r;
    Team t1, t2;
    queue <Round> round_queue;
    stack <Team> winners_stack, losers_stack;

    
    for(auto it = list_of_teams.begin(); it != list_of_teams.end(); it++)
    {
        t1 = *it;
        it++;
        t2 = *it;
        r.set_round(t1,t2);


        //cout<<r;
        round_queue.push(r);

    }

   // while(number_of_teams!=1)
   // {
        while (!round_queue.empty())
        {
            r = round_queue.front();
            cout<<r;
            t1 = r.get_win_team();
            t2 = r.get_lose_team();

            winners_stack.push(t1);
            losers_stack.push(t2);

            round_queue.pop();
        }
        
  //  }



    //cout<<winners_queue.empty()<<endl;
    cout<<endl<<"WINNERS OF ROUND 1:"<<endl;
    while (!winners_stack.empty())
    {
        t1 = winners_stack.top();
        cout<<t1.get_team_name()<<" "<<t1.get_team_score()<<endl;
        winners_stack.pop();
    }

    cout<<endl<<"LOSERS OF ROUND 1:"<<endl;
    while (!losers_stack.empty())
    {
        t1 = losers_stack.top();
        cout<<t1.get_team_name()<<" "<<t1.get_team_score()<<endl;
        losers_stack.pop();
    }

    //number_of_teams = number_of_teams/2;

    //while

    //cout<<winners_queue.empty()<<endl;
    




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