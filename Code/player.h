#include <string>
#include <iostream>
#include <fstream>

using namespace std;
class Player
{
    private:
        string firstName;
        string secondName;
        int score;

    public:
        int get_score();

        friend ifstream& operator >> (ifstream&, Player& );
        friend ostream& operator << (ostream&, const Player&);
        friend ofstream& operator << (ofstream&, const Player&);


    
};