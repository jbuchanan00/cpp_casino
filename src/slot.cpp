//
// Created by Josh on 4/27/2021.
//

#include "slot.h"
#include <array>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

Slot::Slot(){
    result_ = "";
    multiplier_ = 1.0;
    set_bet_amount(0);
    set_win_amount(0);
}

void Slot::spin(){
    int num = rand_num(1);
    int num2 = rand_num(2);
    int num3 = rand_num(3);
    std::cout << "Your Spin Was: " << num << " " << 
        num2 << " " << num3 << std::endl;
    result_ = std::to_string(num) + " " + std::to_string(num2) + " " + std::to_string(num3);
    set_multiplier(result_);
    std::cout << get_multiplier();
}

int Slot::rand_num(int spin) const {
    std::srand(static_cast<unsigned int>(std::time(NULL) + (spin)));
    if(spin == 1){
      return ((std::rand()) % 7) + 1;
    }else if(spin == 2){
      return (std::rand() * 3 % 7) + 1;
    }else if(spin == 3){
      return (std::rand() * 9 % 7) + 1;
    }

}

void Slot::set_multiplier(std::string result){
    std::string num1;
    std::string num2;
    std::string num3;

    num1 = result[0];
    num2 = result[2];
    num3 = result[4];

    if(num1 != num2 && num2 != num3 && num1 != num3){
        multiplier_ = 0;
    }else if(num1 == num2 && num2 == num3){
        multiplier_ = std::stoi(num1);
    }else{
        multiplier_ = 1;
    }
}

