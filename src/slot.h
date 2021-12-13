#ifndef SLOT_H
#define SLOT_H
#include <array>
#include <string>
#include "game.h"

class Slot : public Game {
private:
    std::array<std::string, 7> symbols1_{"1", "2", "3", "4", "5", "6", "7"};

    std::array<std::string, 7> symbols2_{"1", "2", "3", "4","5", "6", "7"};

    std::array<std::string, 7> symbols3_{"1", "2", "3", "4", "5", "6", "7"};

    std::string result_;
    float multiplier_;
public:
    Slot();
    ~Slot(){}

    //getters
    float get_multiplier(){return multiplier_;}
    std::string get_result(){return result_;}

    //setters
    void set_result(std::string result);
    void set_multiplier(std::string result);

    //other methods
    void spin();
    int rand_num(int spin) const;
};


#endif
