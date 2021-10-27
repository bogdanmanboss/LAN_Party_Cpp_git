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
        int get_score(); //returns the score
        void modify_score(); //updates the score by increasing it by 1 

        friend ifstream& operator >> (ifstream&, Player& ); //redefine this operator to make my life easier
                                                            //didn't implemet because it is almost the same as the next
        friend ostream& operator << (ostream&, const Player&);//redefine this operator to make my life easier
        friend ofstream& operator << (ofstream&, const Player&);//redefine this operator to make my life easier


    
};