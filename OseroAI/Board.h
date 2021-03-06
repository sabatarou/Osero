/*
	盤上の大きさ
*/
#define BOARD_SIZE 8
/*
	盤上の要素数
*/
#define NUM_DISK 91
/*
	返した数を覚えておくスタックの大きさ
*/
#define NUM_STACK (((BOARD_SIZE-2)*3+3)*BOARD_SIZE*BOARD_SIZE)
/*
	盤上の状態
*/
#define WALL -1
#define EMPTY 0
#define BLACK 1
#define WHITE 2
/*
	盤上の位置
	右端と左端は1つの要素
*/
#define A1 10
#define B1 11
#define C1 12
#define D1 13
#define E1 14
#define F1 15
#define G1 16
#define H1 17
#define A2 19
#define B2 20
#define C2 21
#define D2 22
#define E2 23
#define F2 24
#define G2 25
#define H2 26
#define A3 28
#define B3 29
#define C3 30
#define D3 31
#define E3 32
#define F3 33
#define G3 34
#define H3 35
#define A4 37
#define B4 38
#define C4 39
#define D4 40
#define E4 41
#define F4 42
#define G4 43
#define H4 44
#define A5 46
#define B5 47
#define C5 48
#define D5 49
#define E5 50
#define F5 51
#define G5 52
#define H5 53
#define A6 55
#define B6 56
#define C6 57
#define D6 58
#define E6 59
#define F6 60
#define G6 61
#define H6 62
#define A7 64
#define B7 65
#define C7 66
#define D7 67
#define E7 68
#define F7 69
#define G7 70
#define H7 71
#define A8 73
#define B8 74
#define C8 75
#define D8 76
#define E8 77
#define F8 78
#define G8 79
#define H8 80
/*
	盤上の方向
*/
#define DIR_UP_LEFT		(-BOARD_SIZE-2)
#define DIR_UP			(-BOARD_SIZE-1)
#define DIR_UP_RIGHT	(-BOARD_SIZE)
#define DIR_LEFT		(-1)
#define DIR_RIGHT		(1)
#define DIR_DOWN_LEFT	(BOARD_SIZE)
#define DIR_DOWN		(BOARD_SIZE+1)
#define DIR_DOWN_RIGHT	(BOARD_SIZE+2)

#include <bitset>
/*
ボード管理クラス
*/
class Board
{
	//ボード内情報のポインタ
	_Board* MainBoard;
	//ボードの情報を初期化
	Board();
	//ボードの情報を削除
	~Board();
	//ボード情報を作成
	_Board* CreateBoard();
	//XとY座標からDisk配列での配列番号を出力
	int GetBoardPosition(int in_x,int in_y);
	//Disk配列での配列番号からX座標を出力
	int GetBoardX(int in_pos);
	//Disk配列での配列番号からY座標を出力
	int GetBoardY(int in_pos);
	//ボード内情報分のメモリを確保
	void CeackMemory(_Board* borad_memory);
	//ボード内情報分のメモリを確保
	void ClearBoard();
	//ボード内情報を初期化
	void InitBoard(_Board* board_memory);
	//一方向の石を返す
	int FlipLine(_Board* board_data,int in_color,int in_pos,int in_dir);
	//白黒反対の色を返す
	int GetOppositeColor(int in_color);
	//返した座標をスタックに書き込み
	void BoardStackPush(_Board* board_date, int flip_pos);
	//盤上の石を返す
	int FlipBoard(_Board *self, int in_color, int in_pos);
	//返した石を戻す
	int UnFlipBoard(_Board* board_data);
};