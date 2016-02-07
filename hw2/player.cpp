#include <iostream>
#include "player.h"

Player::Player(string aName, int aWins, int aLosses, float aPercentage){
    name = aName;
    wins = aWins;
    losses = aLosses;
    percentage = aPercentage;
}

string Player::getName() const {
    return name;
}

int Player::getWins() const {
    return wins;
}

int Player::getLosses() const {
    return losses;
}

int Player::getPercentage() const {
    return percentage;
}

void Player::setName(n){
    name = n;
}

void Player::setWins(w){
    wins = w;
}

void Player::setLosses(l){
    losses = l;
}

void Player::setPercentage(){
    percentage = wins/losses;
}