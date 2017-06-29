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
	�Ǘ��֐�

	�R���X�g���N�^

	���e : �{�[�h�̏���������
*/
Board::Board()
{
	CreateBoard();
}
/*
	�Ǘ��֐�

	�f�X�g���N�^

	���e :�{�[�h�̏����폜
*/
Board::~Board()
{
	ClearBoard();
}
/*
	�Ǘ��֐�

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
	�v�Z�֐�

	���e : X��Y���W����Disk�z��ł̔z��ԍ����o��

	���� : �{�[�h���XY���W

	�߂�l : Disk�z��Ō����z��ԍ�
*/
int Board::GetBoardPosition(int in_x,int in_y)
{
	return (in_y + 1)*(BOARD_SIZE + 1) + in_x + 1;
}
/*
	�v�Z�֐�

	���e : Disk�z��ł̔z��ԍ�����X���W���o��

	���� : Disk�z��ł̔z��ԍ�

	�߂�l : X���W
*/
int Board::GetBoardX(int in_pos)
{
	return in_pos % (BOARD_SIZE + 1) - 1;
}
/*
	�v�Z�֐�

	���e : Disk�z��ł̔z��ԍ�����Y���W���o��

	���� : Disk�z��ł̔z��ԍ�

*/
int Board::GetBoardY(int in_pos)
{
	return in_pos / (BOARD_SIZE + 1) - 1;
}
/*
	�v�Z�֐�
�@
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
	�v�Z�֐�

	���e : �{�[�h�������폜
*/
void Board::ClearBoard()
{
		delete MainBoard;
}
/*
	�v�Z�֐�

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
	�v�Z�֐�

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
	�v�Z�֐�

	���e : �������΂̐F��Ԃ�

	���� : �������΂ɂ������F

	�߂�l : �������΂̐F
*/
int Board::GetOppositeColor(int in_color)
{
	return (BLACK + WHITE - in_color);
}
/*
    �v�Z�֐�

    ���e : �Տ�̈ʒu�X�^�b�N�ɐς�
				
    ���� : �{�[�h�����,
	       �Տ�̈ʒu
*/

void Board::BoardStackPush(_Board* board_date, int flip_pos)
{
	(*board_date->Space++) = flip_pos; 
}
/*
	�v�Z�֐�

	���e : �΂�Ԃ�

	���� : �{�[�h�����,
		 
	�߂�l : 

*/