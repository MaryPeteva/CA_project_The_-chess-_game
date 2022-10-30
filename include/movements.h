#ifndef CHESS_MOVEMENT
#define CHESS_MOVEMENT

#include "board.h"
#include "engine.h"
#include <stdlib.h>
#include <stdbool.h>

void resetOldPosition (board *playBoard, int row, int col);
void makeMove(board *playBoard, int row, int col, input *inputData);
bool checkIsDirectionValid(board *playBoard, int row, int col);
bool checkPawnsRightDirection(board *playBoard, int fields, input *inputData);
bool checkPawnsUpDirection(board *playBoard, int fields, input *inputData);
bool checkPawnsLeftDirection(board *playBoard, int fields, input *inputData);
bool checkPawnsDownDirection(board *playBoard, int fields, input *inputData);
bool checkPawnsDownLeftDirection(board *playBoard, int fields, input *inputData);
bool checkPawnsDownRightDirection(board *playBoard, int fields, input *inputData);
bool checkPawnsUpLeftDirection(board *playBoard, int fields, input *inputData);
bool checkPawnsUpRightDirection(board *playBoard, int fields, input *inputData);

#endif // CHESS_MOVEMENT