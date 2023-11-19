#ifndef DECK_H
#define DECK_H

/* Headers */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/* Structs */
/**
 * enum kind_e - Enumeration for card suits
 * @SPADE: Represents the SPADE suit
 * @HEART: Represents the HEART suit
 * @CLUB: Represents the CLUB suit
 * @DIAMOND: Represents the DIAMOND suit
 *
 * Description: Enumerates the possible suits for playing cards.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/* Prototypes */
void sort_deck(deck_node_t **deck);
bool card_cmp(const card_t *card1, const card_t *card2);
int convert_card_value(const char *value);

#endif /* DECK_H */
