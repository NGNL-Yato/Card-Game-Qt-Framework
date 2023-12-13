#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

enum Suit { GOLD, CUP, SWORD, CLUB };
enum Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, SOTA, CABALLO, KING, ACE };

class Card {
public:
    Card(Suit s, Rank r) : suit(s), rank(r) {}

    Suit getSuit() const { return suit; }
    Rank getRank() const { return rank; }

private:
    Suit suit;
    Rank rank;
};

class Deck {
public:
    Deck() {
        initialize();
        shuffle();
    }

    void initialize() {
        for (int s = GOLD; s <= CLUB; ++s) {
            for (int r = TWO; r <= ACE; ++r) {
                cards.push_back(Card(static_cast<Suit>(s), static_cast<Rank>(r)));
            }
        }
    }

    void shuffle() {
        std::random_shuffle(cards.begin(), cards.end());
    }

    Card drawCard() {
        Card drawnCard = cards.back();
        cards.pop_back();
        return drawnCard;
    }

    bool isEmpty() const {
        return cards.empty();
    }

private:
    std::vector<Card> cards;
};

class Player {
public:
    void addCardToHand(const Card& card) {
        hand.push_back(card);
    }

    void showHand() const {
        std::cout << "Player's Hand: ";
        for (const auto& card : hand) {
            std::cout << "(" << getSuitName(card.getSuit()) << ", " << getRankName(card.getRank()) << ") ";
        }
        std::cout << "\n";
    }

    const std::vector<Card>& getHand() const {
        return hand;
    }

private:
    std::vector<Card> hand;

    const char* getSuitName(Suit s) const {
        switch (s) {
            case GOLD: return "Gold";
            case CUP: return "Cup";
            case SWORD: return "Sword";
            case CLUB: return "Club";
            default: return "Unknown";
        }
    }

    const char* getRankName(Rank r) const {
        switch (r) {
            case TWO: return "2";
            case THREE: return "3";
            case FOUR: return "4";
            case FIVE: return "5";
            case SIX: return "6";
            case SEVEN: return "7";
            case EIGHT: return "8";
            case NINE: return "9";
            case SOTA: return "Sota";
            case CABALLO: return "Caballo";
            case KING: return "King";
            case ACE: return "Ace";
            default: return "Unknown";
        }
    }
};

class RondaGame {
public:
    RondaGame() {
        deck.initialize();
        deck.shuffle();
        currentTurn = 1; // Player 1 starts
    }

    void start() {
        // For simplicity, let's assume a two-player game.
        Player player1, player2;

        for (int i = 0; i < 3; ++i) {
            player1.addCardToHand(deck.drawCard());
            player2.addCardToHand(deck.drawCard());
        }

        player1.showHand();
        player2.showHand();

        // Game loop
        while (!deck.isEmpty()) {
            Player& currentPlayer = (currentTurn == 1) ? player1 : player2;

            std::cout << "\nPlayer " << currentTurn << "'s Turn\n";
            currentPlayer.showHand();

            // Simulate player actions (in a real game, this would be user input)
            // For simplicity, the player just draws a card and adds it to their hand.
            currentPlayer.addCardToHand(deck.drawCard());

            // Switch turns
            currentTurn = (currentTurn == 1) ? 2 : 1;
        }

        std::cout << "\nGame Over!\n";
    }

private:
    Deck deck;
    int currentTurn;
};

int main() {
    srand(static_cast<unsigned>(time(0)));  // Seed for random_shuffle

    RondaGame game;
    game.start();

    return 0;
}
