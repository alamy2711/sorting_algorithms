#include "deck.h"

/**
 * sort_deck - Sorts a deck of cards.
 * @deck: The deck to sort
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *curr, *after, *before;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	curr = (*deck)->next;

	while (curr != NULL)
	{
		after = curr->next;
		before = curr->prev;

		while (before != NULL && card_cmp(before->card, curr->card))
		{
			before->next = curr->next;

			if (curr->next != NULL)
				curr->next->prev = before;

			curr->prev = before->prev;
			curr->next = before;

			if (before->prev != NULL)
				before->prev->next = curr;
			else
				*deck = curr;

			before->prev = curr;
			before = curr->prev;
		}

		curr = after;
	}
}

/**
 * card_cmp - Compares two cards in the deck
 * @card1: the first card
 * @card2: the second card
 *
 * Return: True if card1 > card2 and false otherwise
 */
bool card_cmp(const card_t *card1, const card_t *card2)
{
	if (card1->kind > card2->kind)
		return (true);
	else if (card1->kind == card2->kind)
	{
		if (convert_card_value(card1->value) > convert_card_value(card2->value))
			return (true);
		else
			return (false);
	}
	return (false);
}

/**
 * convert_card_value - Converts card value to integer
 * @value: Card value
 *
 * Return: Converted card value
 */
int convert_card_value(const char *value)
{
	if (strcmp(value, "King") == 0)
		return (13);

	if (strcmp(value, "Queen") == 0)
		return (12);

	if (strcmp(value, "Jack") == 0)
		return (11);

	return (atoi(value));
}
