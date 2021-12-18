#include <iostream>
#include "src/blackjack.h"
#include "src/player.h"
#include "src/slot.h"

int main() {
    //Slot slot1;
/*int total = 0;
int two = 0;
int triple = 0;
while(slot1.get_multiplier() < 2){
  slot1.spin();
  std::cout << std::endl;
  total++;
  if(slot1.get_multiplier() == 1){
    two++;
  }else if(slot1.get_multiplier() > 1){
    triple++;
  }
  std::cout << "Total: " << total << " Matching: " << two << " Percentage: "
    << static_cast<double>(two) / static_cast<double>(total) << std::endl;
  Sleep(1000);
}*/
bool game = true;
int option;
std::cout << "*****Welcome to the Casino!*****\n";
std::cout << "How much money will you be starting with?\n";
float starting_funds;
std::cin >> starting_funds;
std::cout << "What is the username you would like to use?\n";
std::string username;
Player user1(starting_funds, username);
std::cin >> username;

while(game){
  std::cout << "Do you want to continue the game? 1-Yes 2-No" << std::endl;
  std::cin >> option;
  if(option == 2) {
    game = false;
  }
}
    return 0;
}
