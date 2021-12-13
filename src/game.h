#ifndef GAME_H
#define GAME_H


class Game {
protected:
    float bet_amount_;
    float win_amount_;
public:
  Game() : bet_amount_(0), win_amount_(0){}
  Game(float bet_amount, float win_amount);
  ~Game(){}

  //getters
  float get_bet_amount(){return bet_amount_;}
  float get_win_amount(){return win_amount_;}

  //setters
  void set_bet_amount(float bet_amount);
  void set_win_amount(float win_amount);

  //other methods
  virtual int rand_num(int spin) const = 0;
};


#endif
