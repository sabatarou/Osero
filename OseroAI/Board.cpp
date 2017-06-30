#include "Board.h"
#include <cassert>
/*
	�{�[�h�̏��̍\����
*/
struct _Board
{
	//�}�X�̏��
	int Disk[NUM_DISK];
	//�Ԃ����΂��o���Ă���
	int Stack[NUM_STACK];
	//�{�[�h�̈ʒu���o���Ă���
	int *Space;
};
/*
	
	�R���X�g���N�^

	���e : �{�[�h�̏���������
*/
Board::Board()
{
	CreateBoard();
}
/*
	
	�f�X�g���N�^

	���e :�{�[�h�̏����폜
*/
Board::~Board()
{
	ClearBoard();
}
/*
	
	���e : �{�[�h�����쐬

	�߂�l : �{�[�h���̃|�C���^
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
	
	���e : X��Y���W����Disk�z��ł̔z��ԍ����o��

	���� : �{�[�h���XY���W

	�߂�l : Disk�z��Ō����z��ԍ�
*/
int Board::GetBoardPosition(int in_x,int in_y)
{
	return (in_y + 1)*(BOARD_SIZE + 1) + in_x + 1;
}
/*
	
	���e : Disk�z��ł̔z��ԍ�����X���W���o��

	���� : Disk�z��ł̔z��ԍ�

	�߂�l : X���W
*/
int Board::GetBoardX(int in_pos)
{
	return in_pos % (BOARD_SIZE + 1) - 1;
}
/*
	
	���e : Disk�z��ł̔z��ԍ�����Y���W���o��

	���� : Disk�z��ł̔z��ԍ�

*/
int Board::GetBoardY(int in_pos)
{
	return in_pos / (BOARD_SIZE + 1) - 1;
}
/*
	
	���e : �{�[�h����񕪂̃��������m��

	���� : �{�[�h����񕪂̃|�C���^

*/
void Board::CeackMemory(_Board* board_memory)
{
	board_memory = new _Board;
	if (board_memory)
	{
		assert("�{�[�h�̃��������m�ۂł��܂���ł���");
	}
}
/*
	
	���e : �{�[�h�������폜
*/
void Board::ClearBoard()
{
		delete MainBoard;
}
/*
	
	���e : �{�[�h������������

	���� : �{�[�h�����̃|�C���^
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
	
	���e : ������̐΂�Ԃ�

	���� : �{�[�h�����̃|�C���^,
			�����̐F,
			Disk���ł̍��W,
			�Ԃ�����

	�߂�l : �Ԃ����΂̐�
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
	
	���e : �������΂̐F��Ԃ�

	���� : �������΂ɂ������F

	�߂�l : �������΂̐F
*/
int Board::GetOppositeColor(int in_color)
{
	return (BLACK + WHITE - in_color);
}
/*
  
    ���e : �Տ�̈ʒu�X�^�b�N�ɐς�
				
    ���� : �{�[�h�����|�C���^,
	       �Տ�̈ʒu
*/

void Board::BoardStackPush(_Board* board_date, int flip_pos)
{
	(*board_date->Space++) = flip_pos; 
}
/*
	���e : �Տ�̐΂�Ԃ�

	���� : �{�[�h�����|�C���^,
		 
	�߂�l : �S�����̕Ԃ����΂̍��v
*/
int Board::FlipBoard(_Board *borad_data, int in_color, int in_pos)
{
	int result = 0;
	if (borad_data != EMPTY)
	{
		return 0;
	}
	result += FlipLine(borad_data, in_color, in_pos, DIR_UP_LEFT);
	result += FlipLine(borad_data, in_color, in_pos, DIR_UP);
	result += FlipLine(borad_data, in_color, in_pos, DIR_UP_RIGHT);
	result += FlipLine(borad_data, in_color, in_pos, DIR_LEFT);
	result += FlipLine(borad_data, in_color, in_pos, DIR_RIGHT);
	result += FlipLine(borad_data, in_color, in_pos, DIR_DOWN_LEFT);
	result += FlipLine(borad_data, in_color, in_pos, DIR_DOWN);
	result += FlipLine(borad_data, in_color, in_pos, DIR_DOWN_RIGHT);
	if (result > 0)
	{
		borad_data->Disk[in_pos] = in_color;
		BoardStackPush(borad_data, in_pos);
		BoardStackPush(borad_data, GetBoardPosition(in_color));
		BoardStackPush(borad_data, result);
	}
	return result;
}
/*
	���e : �Ԃ����΂�߂�

	���� : �{�[�h���̃|�C���^

	�߂�l : ���ǂ����΂̐�
*/
int Board::UnFlipBoard(_Board* board_data )
{
	int result;
	int i, color; 
	if (board_data->Space <= board_data->Stack)
	{
		return 0;
	}
	result=
}
