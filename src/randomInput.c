#include "board.h"
#include "readInput.h"
#include "validations.h"
#include "randomInput.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


static void setRandomPawnsPositions(int boardSize, input *randomInput)
{
    time_t t;
    srand((unsigned) time(&t));
    int pawnRow = 0;
    int pawnCol = 0;
    int pawnsPositionsSize = randomInput->pawnsCount * 2;

    for (int i = 0, j = 0; i < pawnsPositionsSize; i+=2, j++)
    {
        pawnRow = rand() % (boardSize - 1);
        pawnCol = rand() % (boardSize - 1);
        
        if (j % 2 == 0)
        {
            while (pawnRow == pawnCol || randomInput->col == pawnCol)
            {
                pawnCol = rand() % (boardSize - 1);
            }
        }
        else
        {
            while (pawnRow == pawnCol || randomInput->row == pawnRow)
            {
                pawnRow = rand() % (boardSize - 1);
            }
        }

        randomInput->positions[i] = pawnRow;
        randomInput->positions[i + 1] = pawnCol;
    }
}

static void setRandomPawns(int boardSize, input *randomInput)
{
    randomInput->pawnsCount = setPawnsCount(boardSize);

    int pawnsPositionsSize = randomInput->pawnsCount * 2;

    randomInput->positions = malloc(sizeof(int) * pawnsPositionsSize);

    setRandomPawnsPositions(boardSize, randomInput);

}

static void setRandomFigurePositon(int boardSize, input *randomInput)
{
    time_t t;
    srand((unsigned) time(&t));

    randomInput->row = rand() % (boardSize - 1);
    randomInput->col = rand() % (boardSize - 1);

    while (randomInput->row == randomInput->col)
    {
        randomInput->col = rand() % (boardSize - 1);
    }
}


void setRandomData(int *boardSize, input *randomInput)
{
    (*boardSize) = getBoardSize();

    randomInput->figureType = 'k';

    setRandomFigurePositon(*boardSize, randomInput);

    setRandomPawns(*boardSize, randomInput);

    while (validatePawnsPositions(*boardSize, randomInput) == false)
    {
        setRandomPawnsPositions(*boardSize, randomInput);
    }
}