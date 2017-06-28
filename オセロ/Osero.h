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
#include <bitset>
/*
ボード管理クラス
*/
class Board
{
	/*
		ボードのポインタ
	*/
	_Board* MainBoard;
	/*
		管理関数

		コンストラクタ

		内容 : ボードの情報の構造体
	*/
	Board();
	/*
		管理関数

		デストラクタ

		内容 :ボードの情報の構造体を削除
	*/
	~Board();
	/*
		管理関数

		内容 : クラス初期化時にボードを作成

		戻り値 : ボードののポインタ
	*/
	_Board* CreateBoard();
	/*
		管理関数

		内容 : ボード情報を作成

		引数 : ボード情報のポインタ
	*/
	int GetBoardPosition(int in_x,int in_y);
	/*
		計算関数

		内容 : XとY座標からDisk配列での配列番号を出力

		引数 : ボード上のXY座標

		戻り値 : Disk配列で見た配列番号
	*/
	int GetBoardX(int in_pos);
	/*
		計算関数

		内容 : Disk配列での配列番号からX座標を出力

		引数 : Disk配列での配列番号

		戻り値 : X座標
	*/
	int GetBoardY(int in_pos);
	/*
		計算関数

		内容 : Disk配列での配列番号からX座標を出力

		引数 : Disk配列での配列番号
		

	*/
	void CeackMemory(_Board* borad_memory);
	/*
		計算関数
	  　
	    内容 : ボード内情報分のメモリを確保

		引数 : ボードない情報分のポインタ

	*/
	void ClearBoard();
	/*
		計算関数

		内容 : ボード内情報
	*/
	void InitBoard(_Board* board_memory);
	/*
		計算関数

		内容 : ボード内情報を初期化

		引数 : ボード内情報ポインタ
	*/
};