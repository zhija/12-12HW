#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct _card {
	char* face;
	char* suit;
}card;

void FillDeck(card* wDeck, char* wFace[], char* wSuit[]);
void Shuffle(card* wDeck);
void Deal(card* wDeck);

int main() {

	card deck[52];

	char* face[] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	char* suit[] = { "Hearts","Diamonds","Clubs","Spades" };

	srand(time(NULL));

	FillDeck(deck, face, suit);
	Shuffle(deck);
	Deal(deck);

	system("pause");
	return 0;

}

void FillDeck(card* wDeck, char* wFace[], char* wSuit[]) {

	int i;

	for (i = 0; i < 52; i++) {
		wDeck[i].face = wFace[i % 13];
		wDeck[i].suit = wSuit[i / 13];
	}

}

void Shuffle(card* wDeck) {

	int i, j;
	card temp;

	for (i = 0; i < 52; i++) {

		j = rand() % 52;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;

	}
}

void Deal(card* wDeck) {

	int i;

	for (i = 0; i < 52; i++) {

		printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit, (i + 1) % 4 ? " " : "\n");

	}
}