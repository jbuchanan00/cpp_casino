//
// Created by Josh on 4/27/2021.
//

#include "blackjack.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <array>
#include <vector>

void Blackjack::deal() {
  int card;
  //did 4 cards, 2 for player, 2 for dealer
  std::array<int, 4> tempCardNum;

  for(int i = 0; i < 4; i++){
    card = rand_num(i);
    //avoiding duplicate cards
    while(card == tempCardNum[0] || card == tempCardNum[1] || card == tempCardNum[2]){
      card = rand_num(i * i);
    }
    tempCardNum[i] = card;
  }



  for(int i = 0; i < tempCardNum.size(); i++){
    if(i % 2 == 0){
      set_card_val(card_deck_[tempCardNum[i]]);
    }else if(i % 2 == 1){
      set_dealer_val(card_deck_[tempCardNum[i]]);
    }else{
      std::cout << "Error in dealing cards" << std::endl;
    }
  }
  determine_win(card_val_);
}


int Blackjack::rand_num(int spin) const {
  //added more to the seed to appear like numbers are more random
  std::srand(static_cast<unsigned int>(std::time(NULL)) + spin * 52);
  return std::rand() % 51;
}

Blackjack::Blackjack() : card_val_(""), bust_(false), dealer_bust_(false), dealer_val_("") {}

void Blackjack::set_card_val(std::string val) {
  card_val_ += val + " ";
}

void Blackjack::set_dealer_val(std::string val) {
  dealer_val_ += val + " ";
}

void Blackjack::determine_win(std::string card_val) {
  std::string numString;
  std::string king = "K";
  std::string queen = "Q";
  std::string jack = "J";
  std::string ace = "A";
  std::string isolated_card;



  int numeric_card_value;
  int number_of_cards = card_count(card_val);
  //variable length due to having more cards after hitting
  int total_val = 0;
  int cards_parsed = 1;
  int space_location = 0;
  int card_length = 0;
  std::vector<int> card_vals;

  std::cout << card_val << std::endl;
  while(cards_parsed < number_of_cards){
    if(cards_parsed == 1){
      isolated_card = card_val.substr(space_location, card_val.find(" ", space_location));
    }else if(cards_parsed > 1){
      isolated_card = card_val.substr(space_location + 1, card_val.find(" ", space_location + 1) - (card_val.find(" ", space_location) + 1));
    }

    //h2 d5 s10

    numString = isolated_card.substr(1, isolated_card.length() - 1);
    space_location = card_val.find(" ", space_location + 1);

    if(numString == king || numString == queen || numString == jack){
      numeric_card_value = 10;
    }else if(numString == ace){
      if(total_val + 11 > 21){
        numeric_card_value = 1;
      }else if(total_val >= 0 && total_val <= 21){
        numeric_card_value = 11;
      }
    }else{
      numeric_card_value = std::stoi(numString);
    }

    total_val += numeric_card_value;
    set_numeric_card_values(total_val);

    //card_vals.push_back(numeric_card_value);
    cards_parsed++;
  }

  /*for(int i = 0; i < card_vals.size(); i++){
    total_val += card_vals[i];
  }*/

  if(total_val == 21){
    std::cout << "Congrats You've Got Blackjack!" << std::endl;
  }else if (total_val > 21){
    bust();
  }
  std::cout << total_val << std::endl;
  std::cout << get_dealer_val() << std::endl;
}

int Blackjack::card_count(std::string card_val){
  size_t count = 0;
  for(int i = 0; i < card_val.length(); i++){
    if(card_val[i] == ' '){
      count++;
    }
  }

  return count + 1;
}

void Blackjack::bust() {
  bust_ = !bust_;
}

void Blackjack::hit() {
  std::string numString;

  std::string string_card_value;
  int number_of_cards = card_count(get_card_value());
  //variable length due to having more cards after hitting
  int cards_parsed = 1;
  std::vector<std::string> card_vals;
  int space_indices;
  int substring_start_pos = 0;
  int card_number;
  bool isDuplicate = false;

  while(cards_parsed < number_of_cards){
    space_indices = get_card_value().find(" ", substring_start_pos);
    numString = get_card_value().substr(substring_start_pos, space_indices);
    substring_start_pos = space_indices + 1;

    card_vals.push_back(numString);
    cards_parsed++;
  }

  card_number = rand_num(cards_parsed + 1);
  //checking vector for duplicate cards
  for(const auto &s : card_vals){
    if(card_deck_[card_number] + " " == s || card_deck_[card_number] == s){
      isDuplicate = true;
      std::cout << "There was a dupe draw" << std::endl;
    }
  }

  while(isDuplicate){
    card_number = rand_num(cards_parsed * 2);
    isDuplicate = false;

    for(const auto &s : card_vals){
      if(card_deck_[card_number] + " " == s || card_deck_[card_number] == s){
        isDuplicate = true;
      }
    }
  }

  string_card_value = card_deck_[card_number];

  for (std::string &card_value : card_vals) {

    while (string_card_value == card_value.substr(1, card_value.find(" "))) {
      card_number = rand_num(cards_parsed + 1);

      string_card_value = card_deck_[card_number];
    }
  }

  set_card_val(string_card_value);

  //std::cout << get_card_value() << std::endl;

  determine_win(get_card_value());

}

void Blackjack::set_numeric_card_values(int numeric_vals) {
  numeric_card_values_ = numeric_vals;
}