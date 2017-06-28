#include "Osero.h"
#include <cassert>
/*
	ボードの情報の構造体
*/
struct _Board
{
	//マスの状態
	int Disk[NUM_DISK];
	//返した石を覚えておく
	int Stack[NUM_STACK];
	//ボードの位置を覚えておく
	int *Sp;
};
Board::Board()
{
	CreateBoard();
}
Board::Board()
{
	ClearBoard();
}
_Board* Board::CreateBoard()
{
	_Board* board;
	ClearBoard();

	CeackMemory(board);

	InitBoard(board);

	return board;
}
int Board::GetBoardPosition(int in_x,int in_y)
{
	return (in_y + 1)*(BOARD_SIZE + 1) + in_x + 1;
}
int Board::GetBoardX(int in_pos)
{
	return 
}
int Board::GetBoardX(int in_pos)
{
	return
}
void Board::CeackMemory(_Board* board_memory)
{
	board_memory = new _Board;
	if (board_memory)
	{
		assert("ボードのメモリが確保できませんでした");
	}
}
void Board::ClearBoard()
{
		delete MainBoard;
}
void Board::InitBoard(_Board* board_memory)
{

	for (int i=0; i < NUM_DISK; i++)
	{
		board_memory->Disk[i] = WALL;
	}
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; i < BOARD_SIZE;j++)
		{
			board_memory->Disk[]
		}
	}
}