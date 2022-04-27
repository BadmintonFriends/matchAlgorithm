//
// Created by 최유진 on 2022/04/26.
//

#include "match.h"
#include <iostream>
#include <string>

using namespace std;

void Match::didGame() {
  this->team1->didGame();
  this->team2->didGame();
}

void Match::printMatch() const {
  this->team1->printTeam();
  cout << " vs ";
  this->team2->printTeam();
}

bool Match::hasTeam(const Team &team) const {
    return team == *(this->team1) || team == *(this->team2);
}
int Match::count() const { return this->team1->count + this->team2->count; }

bool Match::operator==(const Match &match) const {
  return match.team1 == this->team1 && match.team2 == this->team2;
}

bool Match::operator!=(const Match &match) const { return !(match == *this); }

bool Match::operator>=(const Match &match) const {
  return (match.team1->teamName + match.team2->teamName) >=
         (this->team1->teamName + this->team2->teamName);
}

bool Match::operator<=(const Match &match) const { return !(match > *this); }

bool Match::operator>(const Match &match) const {
  return match <= *this && (match != *this);
}
bool Match::operator<(const Match &match) const { return !(match >= *this); }