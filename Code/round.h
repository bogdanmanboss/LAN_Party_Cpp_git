#include "team.h"

class Round
{
    private:
    Team t1,t2;
    
    public:
    Team get_win_team();
    Team get_lose_team();

    void set_round(const Team&, const Team&);

    friend ostream& operator <<(ostream &, Round&);
    friend ofstream& operator <<(ofstream &, Round&);


};