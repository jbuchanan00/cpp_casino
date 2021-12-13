#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <array>
#include <string>
#include "game.h"


class Blackjack : public Game{
//could create 2 dimension array instead
private:
    std::array<std::string, 52> card_deck_ = {"hA", "hK", "hQ", "hJ",
                                              "h10", "h9", "h8", "h7",
                                              "h6", "h5", "h4", "h3",
                                              "h2", "dA", "dK",
                                              "dQ", "dJ","d10", "d9",
                                              "d8", "d7","d6", "d5",
                                              "d4", "d3","d2",
                                              "cA", "cK", "cQ", "cJ",
                                              "c10", "c9", "c8", "c7",
                                              "c6", "c5", "c4", "c3",
                                              "c2", "sA", "sK",
                                              "sQ", "sJ", "s10", "s9",
                                              "s8", "s7", "s6", "s5",
                                              "s4", "s3", "s2"};
    std::string card_val_;
    bool bust_;
    std::string dealer_val_;
    bool dealer_bust_;
    int numeric_card_values_;
public:
    Blackjack();
    ~Blackjack(){}

    //getters
    std::string get_card_value() const{return card_val_;}
    bool get_bust() const {return bust_;}
    std::string get_dealer_val() const {return dealer_val_;}
    bool get_dealer_bust() const{return dealer_bust_;}
    int get_numeric_card_values()const{return numeric_card_values_;}

    //setters
    void set_card_val(std::string val);
    void bust();
    void set_dealer_val(std::string val);
    void dealer_bust();
    void set_numeric_card_values(int numeric_vals);

    //other methods
    int rand_num();
    void hit();
    void deal();
    void reshuffle_deck();
    void determine_win(std::string card_val);
    int card_count(std::string card_val);
    int rand_num(int spin) const;
};


#endif
