#include "team.h"
#include "round.h"
#include <list>
#include <iterator>
#include <queue>
#include <stack>


int number_of_needed_teams(int number_teams)
{
    //this calculate the first 2^n number lower than the number of teams present at the competition
    int i;
    for(i = 2; i <= number_teams; i = i*2)
    {
        ;
    }
    return i/2;
}

float get_min_score(list <Team> l)
{
    //calculate a minim from a list of objects
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
    ifstream file_in("d.in"); //open the input file
    Team *teams;


    int number_of_teams,number_of_members;
    string n;
    list <Team> list_of_teams;

    file_in>>number_of_teams;
    teams = new Team[number_of_teams];

    //read the teams
    for(int i = 0; i < number_of_teams; i++)
    {
        file_in>>teams[i];
        list_of_teams.push_front(teams[i]);
    }


    //eliminates teams until there are only 2^n number of teams
    //elimination process is based by the team score
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

    //display in file the team that passed the first elimiation process
    for(auto it = list_of_teams.begin(); it != list_of_teams.end(); it++)
    {
        cout<<it->get_team_name()<<" "<<it->get_team_score()<<endl;
    }
    
    cout<<endl;

    //now the tournament starts
    Round r;
    Team t1, t2;
    queue <Round> round_queue;
    stack <Team> winners_stack, losers_stack;

    
    //set the rounds between the teams
    for(auto it = list_of_teams.begin(); it != list_of_teams.end(); it++)
    {
        t1 = *it;
        it++;
        t2 = *it;
        r.set_round(t1,t2);

        round_queue.push(r);

    }


   number_of_teams = number_of_needed_teams(number_of_teams);
   int i = 1;
   
   //in every round,the matches are displayed
   //also the winning teams and the losing teams are displayed
   while(number_of_teams!=2)
   {
        
        cout<<"---ROUND "<<i<<"---"<<endl;
   
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
        
  
        cout<<endl<<"WINNERS OF ROUND "<<i<<":"<<endl;
        while (!winners_stack.empty())
        {
            t1 = winners_stack.top();
            cout<<t1.get_team_name()<<" "<<t1.get_team_score()<<endl;
            winners_stack.pop();

            t2 = winners_stack.top();
            cout<<t2.get_team_name()<<" "<<t2.get_team_score()<<endl;
            winners_stack.pop();

            r.set_round(t1,t2);
            round_queue.push(r);

        }

        cout<<endl<<"LOSERS OF ROUND "<<i<<":"<<endl;
        while (!losers_stack.empty())
        {
            t1 = losers_stack.top();
            cout<<t1.get_team_name()<<" "<<t1.get_team_score()<<endl;
            losers_stack.pop();
        }
        i++;
        number_of_teams = number_of_teams/2;
   }

    //the last round is here
   cout<<"---ROUND "<<i<<"---"<<endl;

   r = round_queue.front();
   cout<<r;
   t1 = r.get_win_team();
   t2 = r.get_lose_team();
   
   round_queue.pop();

   cout<<endl<<"WINNERS OF ROUND "<<i<<":"<<endl;
   cout<<t1.get_team_name()<<" "<<t1.get_team_score()<<endl;

   cout<<endl<<"LOSERS OF ROUND "<<i<<":"<<endl;
   cout<<t2.get_team_name()<<" "<<t2.get_team_score()<<endl;

    

    file_in.close();
    return 0;
}