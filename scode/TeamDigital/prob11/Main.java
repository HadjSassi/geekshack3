class wolves
{
public:
    string name;
    //wolves(string name,int health); // Constructor
    int hitPoints() { return health; }
private:
    int health;
    string attack;
}
int wolves::hitpoints()
{
    return health;
}
{
    srand(time(0)); // seed random number generator based on current time
int randomNumber= rand(); // generate random number
int hitPoints = (randomNumber% 20) + 1; // get a number between 1 and 20
return hitPoints;
}
int fatigue()
{
    srand(time(0)); // seed random number generator based on current time
int randomNumber= rand(); // generate random number
int fatigue = (randomNumber% 5) + 1; // get a number between 1 and 5
return fatigue;
}
int Encounter()
{


    srand(time(0)); // seed random number generator based on current time
    int randomNumber= rand(); // generate random number
    int encounter = (randomNumber% 3); // get a number between 1 and 5
    cin >> encounter;
        switch(encounter)
        {
        case 1:
            Wolves();
            menu = false;
            break;
        case 2:
            Soldier();
            break;
        case 3:
            CaveBear();
            break;
        }
        cout << encounter;

    return encounter;
}