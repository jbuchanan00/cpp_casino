#include "player.h"
#include <stdexcept>
#include <iostream>

/**
 * brief: default constructor sets funds to 0 and username
 *  to none
 * */
Player::Player() : funds_(0), username_("none"){}

/**
 * brief: custom constructor that sets funds and username
 *  using the setter methods
 * */
Player::Player(float funds, std::string username){

}

/**
 * brief: set funds to the amount passed through unless it is less than 0
 * params: funds-amount of funds to use
 * */
void Player::set_funds(float funds) {
  if(funds < 0){
    throw std::out_of_range("You cannot add negative funds.");
  }else if(funds > 0){
    funds_ = funds;
  }
}

/**
 * brief: set username to username entered.
 * params: username-sent by user
 * possible-add: username checks to make sure it is appropriate
 * */
void Player::set_username(std::string username) {
  username_ = username;
}

/**
 * brief: add amount of funds to existing funds
 * param: amt-amount to add to funds
 * throw: out of range if the amt is less than 0
 * */
void Player::deposit_funds(float amt) {
  if(amt < 0){
    throw std::out_of_range("Amount must be positive");
  }else if(amt > 0){
    set_funds(funds_ + amt);
  }
}

/**
 * brief: exits the game currently being played
 * */
void Player::exit_game() {
  int game_index;
  std::cout << "Which game would you like to play?" << std::endl;
  std::cout << "1: Slots \n2:Blackjack" << std::endl;

  std::cin >> game_index;
  while(std::cin.fail()){
    std::cin.clear();
    std::cout << "Please enter numeric value" << std::endl;
    std::cin >> game_index;
  }

}

