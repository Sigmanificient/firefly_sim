#include <malloc.h>
#include "board.h"

__attribute__((nonnull(1)))
static int **board_alloc_failed(int **board, int i)
{
    for (int j = i; j > 0; j--)
        free(board[j]);
    free(board);
    return NULL;
}

int **board_alloc(int height, int width)
{
    int **board = malloc(height * sizeof(int *));

    if (board == NULL)
        return NULL;
    for (int i = 0; i < height; i++) {
        board[i] = malloc(width * sizeof(int));
        if (board[i] == NULL)
            return board_alloc_failed(board, i);
    }
    return board;
}

void board_free(int **board, int height)
{
    board_alloc_failed(board, height);
}
