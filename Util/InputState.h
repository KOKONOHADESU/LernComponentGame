#pragma once
#include <map>
#include <vector>

// �{�^���̓��̓^�C�v
enum class InputType
{
	DECISION,	// ����
	BACK,		// �߂�
	PAUSE,		// �|�[�Y
	UP,			// ��
	DOWN,		// ��
	RIGHT,		// �E
	LEFT,		// ��
	RIGHT_SHOULDER,	// �E�V�����_�[
	LEFT_SHOULDER,	// ���V�����_�[
	ANY_BUTTON,		// �ǂ̃{�^���ł�����

	// �{�^���̓��̓^�C�v�̍��v�l
	NUM
};

// �p�b�h�̃g���K�[�̍����E���܂��̓p�b�h�̃X�e�B�b�N�̍����E��
enum class PadLR
{
	LEFT,	// �g���K�[�܂��̓X�e�B�b�N�̍�
	RIGHT,	// �g���K�[�܂��̓X�e�B�b�N�̉E
};

// �p�b�h�̃X�e�B�b�N�̓��̓^�C�v
enum class PadStickInputType
{
	UP,				// ��
	DOWN,			// ��
	LEFT,			// ��
	RIGHT,			// �E
};

// �p�b�h�̃X�e�B�b�N�̋���
enum class PadStickStrength
{
	WEAK,	// �ア
	NORMAL,	// ����
	STRONG	// ����
};

// ���͑��u�J�e�S��
enum class InputCategory
{
	KEYBORD,	// �L�[�{�[�h
	PAD,		// �Q�[���p�b�h
	MOUSE		// �}�E�X
};

// ���͏��
struct InputInfo
{
	InputCategory cat;	// ���͑��u�J�e�S��
	int id;				// ����ID(KEY_INPUT_�`,PAD_INPUT_�`,MOUSE_INPUT_�`)
};

/// <summary>
/// ���͏�Ԃ��Ǘ����閼�O���
/// </summary>
namespace InputState
{
	/// <summary>
	/// ������
	/// </summary>
	void Init();

	/// <summary>
	/// ���͏��̍X�V 
	/// ���t���[��Update���Ă΂Ȃ��Ɠ��͏�Ԃ͍X�V����Ȃ�
	/// </summary>
	void Update();

	/// <summary>
	/// �{�^���������ꂽ�u�Ԃ̓��͏��̎擾
	/// </summary>
	/// <param name="type">�擾���������̓^�C�v</param>
	/// <returns>true : ���́Afalse : �����</returns>
	bool IsTriggered(const InputType type);

	/// <summary>
	/// �{�^����������Ă���Ԃ̓��͏��̎擾
	/// </summary>
	/// <param name="type">�擾���������̓^�C�v</param>
	/// <returns>true : ���͒��Afalse : �����</returns>
	bool IsPressed(const InputType type);

	/// <summary>
	/// �p�b�h�̃g���K�[�̓��͏��̎擾
	/// </summary>
	/// <param name="type">�擾���������̓^�C�v</param>
	/// <returns>true : ���͒��Afalse : �����</returns>
	bool IsPadTrigger(const PadLR type);

	/// <summary>
	/// �p�b�h�̃X�e�B�b�N�̓��͏���l�Ŏ擾
	/// </summary>
	/// <param name="stick">�E�X�e�B�b�N�����X�e�B�b�N��</param>
	/// <param name="input">�X�e�B�b�N�̂ǂ̓��̓^�C�v��</param>
	/// <returns>�X�e�B�b�N�̌X�����킢(0�̂Ƃ��͓��͂Ȃ�)�@�X���Ă���p�x���傫���قǑ傫���������Ԃ��Ă���</returns>
	int IsPadStick(const PadLR stic, const PadStickInputType type);

	/// <summary>
	/// �p�b�h�̃X�e�B�b�N�̓��͏����擾
	/// </summary>
	/// <param name="stick">�E�X�e�B�b�N�����X�e�B�b�N��</param>
	/// <param name="type">�X�e�B�b�N�̂ǂ̓��̓^�C�v��</param>
	/// <param name="strength">�X�e�B�b�N���ǂꂭ�炢���͂��Ă��邩</param>
	/// <returns>true : ���́Afalse : �����</returns>
	bool IsPadStick(const PadLR stick, const PadStickInputType type, const PadStickStrength strength);

	// private
	namespace
	{
		// ���z���͏��Ǝ��ۂ̓��͂̃e�[�u��
		std::map<InputType, std::vector<InputInfo>> m_inputMapTable;

		// ���݂̓��͏��(�����Ă邩�����ĂȂ���)
		std::vector<bool> m_currentInput;

		// ���O�̓��͏��(���O�����Ă邩�����ĂȂ���)
		std::vector<bool> m_lastInput;
	}
};