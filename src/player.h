#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <array>
#include "game.h"

class Player{
private:
    float funds_;
    std::string username_;
    std::array<Game*, 2> game_ptr_;
public:
    Player();
    Player(float funds, std::string username);
    ~Player(){};

    //setters
    void set_funds(float funds);
    void set_username(std::string username);

    //getters
    float get_funds(){return funds_;}
    std::string get_username(){return username_;}

    //other methods
    void exit_game();
    void deposit_funds(float amt);

};

#endif
