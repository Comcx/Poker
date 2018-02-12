#pragma once

#include "lainlib.h"

namespace poker {

	const int MAX_SIZE = 54;


	/**
	* @class: Card
	* @author: Comcx
	*
	*/
	class Card {

	private:
		int number_;
		string pattern_;

	public:
		Card() {}
		Card(int number, string pattern) : number_(number), pattern_(pattern) {}
		Card(const Card &that) : number_(that.number()), pattern_(that.pattern()) {}
		Card& operator=(const Card &that);

		int number() const { return this->number_; }
		string pattern() const { return this->pattern_; }
		friend std::ostream& operator<<(std::ostream& os, const Card& that);

	};

	Card& Card::operator=(const Card &that) {
		this->number_ = that.number();
		this->pattern_ = that.pattern();

		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Card& that) {
		os << that.number() << "\t" << that.pattern();
		return os;
	}

}// namespace Poker






	
#include "Player.h"
namespace poker {

	/**
	* @class: Poker
	* @author: Comcx
	*
	*/
	class Poker {

	private:
		std::vector<Card> cards_;
		std::stack<Card> cards_unused_;

		std::vector<Player> players_;

	public:
		Poker(int pack_number);
		Poker(const Poker&);


		std::stack<Card> cards_used;

		std::vector<Card> cards() const { return this->cards_; }
		std::stack<Card> cards_unused() const { return this->cards_unused_; }
		std::vector<Player> players() const { return this->players_; }

		friend std::ostream& operator<<(std::ostream& os, const Poker& that);
		int shuffle(int number = 1);
		int play(string game_mode, int player_number);

	};


	Poker::Poker(int pack_number) {
		const std::vector<string> patterns{ "spade", "heart", "club", "diamond" };

		for (int pack = 0; pack < pack_number; pack++) {
			for (int i = 0; i < MAX_SIZE - 2; i++) {
				this->cards_.push_back(Card(i % 13 + 1, patterns[i / 13]));
			}

			this->cards_.push_back(Card(53, "Joker"));
			this->cards_.push_back(Card(54, "joker"));
		}
		
	}

	Poker::Poker(const Poker &that) {
		this->cards_ = that.cards();
		this->cards_unused_ = that.cards_unused();
		this->cards_used = that.cards_used;
	}

	int Poker::shuffle(int number) {
		srand((unsigned)time(NULL));
		for (int i = 0; i < MAX_SIZE*number; i++) {
			double random = std::rand() % 100 / double(101);
			int chosen_id = std::ceil(random * MAX_SIZE);
			
			Card tmp = this->cards_[0];
			this->cards_[0] = this->cards_[chosen_id];
			this->cards_[chosen_id] = tmp;
		}
		return 0;
	}

	int Poker::play(string game_mode, int player_number) {
		this->shuffle(3);
		for (int i = 0; i < MAX_SIZE; i++) {
			this->cards_unused_.push(this->cards_[i]);
		}
		std::cout << "-> Please input every player's infomation: " << std::endl;
		this->players_.push_back(Player("Monika", "female"));
		for (int i = 1; i < player_number; i++) {
			string name, sex;
			std::cout << "Player" << i << ":" << std::endl;
			std::cin >> name >> sex;
			Player current(name, sex);
			this->players_.push_back(current);
		}

		if (game_mode == "fish") { // fishing game mode
			
			for (int i = 0; i < player_number; i++) {
				for (int j = 0; j < 7; j++) {
					players_[i].take_from(this->cards_unused_);
				}
			}
			std::cout << "-> Please input your name: " << std::endl;
			string self_name("");
			std::cin >> self_name;
			auto self = std::find_if(this->players_.begin(), this->players_.end(), 
				[=](Player current) { return current.name == self_name; });

			if (self != this->players_.end()) {
				std::cout << "-> Your infomation: " << std::endl;
				std::cout << *self;

			} else {
				std::cerr << "-> No such player!" << std::endl;
			}

		}



		return 0;
	}


	std::ostream& operator<<(std::ostream& os, const Poker& that) {
		for (auto iter = that.cards_.cbegin(); iter != that.cards_.cend(); iter++) {
			os << *iter << std::endl;
		}
		return os;
	}


}// namespace Poker











