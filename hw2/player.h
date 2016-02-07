class Player {
public:
    Player();
    Player(string aName, int aWins, int aLosses, float aPercentage);
    
    int getWins() const;
    int getLosses() const;
    int getPercentage() const;
    
    void setName (string name);
    void setWins(int wins);
    void setLosses(int losses);
    void setPercentage(float percentage);

    
};