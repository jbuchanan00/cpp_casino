#include "game.h"
#include <stdexcept>
#include <stdlib.h>
#include <time.h>

Game::Game(float bet_amount, float win_amount) {
  set_win_amount(win_amount);
  set_bet_amount(bet_amount);
}

void Game::set_bet_amount(float bet_amount) {
  if(bet_amount < 0){
    throw std::out_of_range("Bet must be greater than 0");
  }else if(bet_amount > 0){
    bet_amount_ = bet_amount;
  }
}

void Game::set_win_amount(float win_amount) {
  if(win_amount < 0){
    throw std::out_of_range("Winning amount must be greater than 0");
  }else if(win_amount > 0){
    win_amount_ = win_amount;
  }
}
