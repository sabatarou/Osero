#include "Board.h"
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
	int *Space;
};
/*
	管理関数

	コンストラクタ

	内容 : ボードの情報を初期化
*/
Board::Board()
{
	CreateBoard();
}
/*
	管理関数

	デストラクタ

	内容 :ボードの情報を削除
*/
Board::~Board()
{
	ClearBoard();
}
/*
	管理関数

	内容 : ボード情報を作成

	戻り値 : ボード情報のポインタ
*/
_Board* Board::CreateBoard()
{
	_Board* board;
	ClearBoard();

	CeackMemory(board);

	InitBoard(board);

	return board;
}
/*
	計算関数

	内容 : XとY座標からDisk配列での配列番号を出力

	引数 : ボード上のXY座標

	戻り値 : Disk配列で見た配列番号
*/
int Board::GetBoardPosition(int in_x,int in_y)
{
	return (in_y + 1)*(BOARD_SIZE + 1) + in_x + 1;
}
/*
	計算関数

	内容 : Disk配列での配列番号からX座標を出力

	引数 : Disk配列での配列番号

	戻り値 : X座標
*/
int Board::GetBoardX(int in_pos)
{
	return in_pos % (BOARD_SIZE + 1) - 1;
}
/*
	計算関数

	内容 : Disk配列での配列番号からY座標を出力

	引数 : Disk配列での配列番号

*/
int Board::GetBoardY(int in_pos)
{
	return in_pos / (BOARD_SIZE + 1) - 1;
}
/*
	計算関数
　
	内容 : ボード内情報分のメモリを確保

	引数 : ボード内情報分のポインタ

*/
void Board::CeackMemory(_Board* board_memory)
{
	board_memory = new _Board;
	if (board_memory)
	{
		assert("ボードのメモリが確保できませんでした");
	}
}
/*
	計算関数

	内容 : ボード内情報を削除
*/
void Board::ClearBoard()
{
		delete MainBoard;
}
/*
	計算関数

	内容 : ボード内情報を初期化

	引数 : ボード内情報のポインタ
*/
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
			board_memory->Disk[GetBoardPosition(i, j)] = EMPTY;
		}
	}
	board_memory->Disk[E4] = BLACK;
	board_memory->Disk[D5] = BLACK;
	board_memory->Disk[D4] = WHITE;
	board_memory->Disk[E5] = WHITE;

	board_memory->Space = board_memory->Stack;
}