#include "history.h"

#include <stdint.h>
#include <stdlib.h>

#define INITIAL_HISTORY_CAPACITY 8U

void history_init(MoveHistory *history)
{
    if (history == NULL)
    {
        return;
    }

    history->items = NULL;
    history->count = 0;
    history->capacity = 0;
}

int history_push(MoveHistory *history, Move move)
{
    /* STUDENT TODO 4: Append one move to the resizable history array. */
    if (history == NULL)
    {
        return 0;
    }

    if (history->capacity == 0)
    {
        Move *items = malloc(sizeof(Move) * INITIAL_HISTORY_CAPACITY);

        if (items == NULL)
        {
            return 0;
        }

        history->items = items;
        history->capacity = INITIAL_HISTORY_CAPACITY;
    }

    if (history->count == history->capacity)
    {
        Move *temp = realloc(history->items, sizeof(Move) * (history->capacity * 2));
        if (temp == NULL)
        {
            return 0;
        }
        history->items = temp;
        history->capacity = history->capacity * 2;
    }

    history->items[history->count] = move;
    history->count++;
    return 1;
}

int history_pop(MoveHistory *history, Move *result)
{
    /* STUDENT TODO 4: Remove and return the most recent move. */
    if (history == NULL || result == NULL || history->count == 0)
    {
        return 0;
    }

    history->count--;

    *result = history->items[history->count];

    return 1;
}

void history_clear(MoveHistory *history)
{
    if (history == NULL)
    {
        return;
    }

    history->count = 0;
}

void history_destroy(MoveHistory *history)
{
    /* STUDENT TODO 4: Release all storage owned by the history. */
    if (history == NULL)
    {
        return;
    }

    free(history->items);

    history->items = NULL;
    history->count = 0;
    history->capacity = 0;
}
