#include <iostream>
#include <string>
using namespace std;

enum suit_t {CLUBS, DIAMONDS, HEARTS, SPADES}; // default as 0, 1, 2, 3
//enum suit_t {CLUBS = 18, DIAMONDS = 91, HEARTS = 241, SPADES = 13};

const char *print_suit(const suit_t suit) {
	const char *names[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
	return names[suit];
}

int main() {

	return 0;
} 
