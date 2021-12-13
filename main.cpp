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
    Blackjack b1;
    b1.deal();
    while(b1.get_numeric_card_values() < 16 && !b1.get_bust()){
        b1.hit();
    }
    return 0;
}
