#pragma once

#include "lainlib.h"
#include "Poker.h"

namespace poker {

	class Player {

	private:
		static int total_number;
		int number_;
		std::list<Card> cards_;

	public:
		string name;
		string sex;

		Player() { total_number++; }
		Player(string name, string sex) : name(name), sex(sex) { total_number++; }
		Player(const Player&);

		friend std::ostream& operator<<(std::ostream& os, const Player& that);
		int number() const { return this->number_; }
		std::list<Card> cards() const { return this->cards_; }
		Card take_from(std::stack<Card>&);
		int quit() { total_number--; return this->number_; }

	};


	int Player::total_number = 0;

	Player::Player(const Player &that) {
		this->number_ = that.number();
		this->name = that.name;
		this->sex = that.sex;
		total_number++;
		this->cards_ = that.cards();
	}


	Card Player::take_from(std::stack<Card> &cards_unused) {
		Card current = cards_unused.top();
		this->cards_.push_back(current);
		cards_unused.pop();

		return current;
	}

	std::ostream& operator<<(std::ostream& os, const Player& that) {
		os << that.name << " " << that.sex << std::endl;

		int i = 0;
		for (auto iter = that.cards_.cbegin(); iter != that.cards_.cend(); iter++) {
			os << i++ << "\t" << *iter << std::endl;
		}
		return os;
	}



}// namespace Poker




