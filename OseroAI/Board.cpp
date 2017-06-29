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
/*
	計算関数

	内容 : 一方向の石を返す

	引数 : ボード内情報のポインタ,
			自分の色,
			Disk内での座標,
			返す方向
	戻り値 : 返した石の数
*/
int  Board::FlipLine(_Board* board_data, int in_color, int in_pos, int in_dir)
{
	int result = 0;
	int opposite_color = GetOppositeColor(in_color);
	int flip_pos=0;
	for (flip_pos = in_pos + in_dir; board_data->Disk[flip_pos] == opposite_color; flip_pos += in_dir){};
	if (board_data->Disk[flip_pos] == in_color)
	{
		result++;
		board_data->Disk[flip_pos] = in_color;
		BoardStackPush(board_data, flip_pos);
	}
	return result;
}
/*
	計算関数

	内容 : 白黒反対の色を返す

	引数 : 白黒反対にしたい色

	戻り値 : 白黒反対の色
*/
int Board::GetOppositeColor(int in_color)
{
	return (BLACK + WHITE - in_color);
}
/*
    計算関数

    内容 : 盤上の位置スタックに積む
				
    引数 : ボード内情報,
	       盤上の位置
*/

void Board::BoardStackPush(_Board* board_date, int flip_pos)
{
	(*board_date->Space++) = flip_pos; 
}
/*
	計算関数

	内容 : 石を返す

	引数 : ボード内情報,
		 
	戻り値 : 

*/