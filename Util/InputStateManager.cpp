#include "InputStateManager.h"
#include <DxLib.h>

namespace InputStateManager
{
	// ������
	void InputStateManager::Init()
	{
		// �{�^���̓��̓^�C�v���ǂ̃{�^���ɂ��邩�̐ݒ�
		m_inputMapTable[InputType::DECISION] = { {InputCategory::PAD, XINPUT_BUTTON_A },				// A�{�^��
												 {InputCategory::KEYBORD, KEY_INPUT_RETURN} };			// Enter�L�[
		m_inputMapTable[InputType::BACK] = { {InputCategory::PAD, XINPUT_BUTTON_B},						// B�{�^��
												 {InputCategory::KEYBORD, KEY_INPUT_SPACE} };			// SPACE�L�[	
		m_inputMapTable[InputType::PAUSE] = { {InputCategory::PAD, XINPUT_BUTTON_START },				// START�{�^��
												 {InputCategory::KEYBORD, KEY_INPUT_P} };				// P�L�[
		m_inputMapTable[InputType::UP] = { {InputCategory::PAD, XINPUT_BUTTON_DPAD_UP },				// PAD��
												 {InputCategory::KEYBORD, KEY_INPUT_UP},				// KEY��
												 {InputCategory::KEYBORD, KEY_INPUT_W} };				// W�L�[
		m_inputMapTable[InputType::DOWN] = { {InputCategory::PAD, XINPUT_BUTTON_DPAD_DOWN },			// PAD��
												 {InputCategory::KEYBORD, KEY_INPUT_DOWN},				// KEY��
												 {InputCategory::KEYBORD, KEY_INPUT_S} };				// S�L�[
		m_inputMapTable[InputType::RIGHT] = { {InputCategory::PAD, XINPUT_BUTTON_DPAD_RIGHT },			// PAD��
												 {InputCategory::KEYBORD, KEY_INPUT_RIGHT},				// KEY��
												 {InputCategory::KEYBORD, KEY_INPUT_D} };				// D�L�[
		m_inputMapTable[InputType::LEFT] = { {InputCategory::PAD, XINPUT_BUTTON_DPAD_LEFT },			// PAD��
												 {InputCategory::KEYBORD, KEY_INPUT_LEFT},				// KEY��
												 {InputCategory::KEYBORD, KEY_INPUT_A} };				// A�L�[
		m_inputMapTable[InputType::RIGHT_SHOULDER] = { {InputCategory::PAD, XINPUT_BUTTON_RIGHT_SHOULDER} };// RB�{�^��
		m_inputMapTable[InputType::LEFT_SHOULDER] = { {InputCategory::PAD, XINPUT_BUTTON_LEFT_SHOULDER} };	// LB�{�^��

		m_inputMapTable[InputType::ANY_BUTTON] = { {InputCategory::PAD, XINPUT_BUTTON_A },
													{InputCategory::PAD, XINPUT_BUTTON_B },
													{InputCategory::PAD, XINPUT_BUTTON_X },
													{InputCategory::PAD, XINPUT_BUTTON_Y } };

		// �ݒ肵���{�^���̐��ɂ���Ĕz��̐���ύX
		m_currentInput.resize(static_cast<int>(InputType::NUM));
		m_lastInput.resize(static_cast<int>(InputType::NUM));
	}

	// �X�V
	void InputStateManager::Update()
	{
		// ���O�̓��͏����L�����Ă���
		m_lastInput = m_currentInput;

		// �p�b�h�̏��̎擾
		XINPUT_STATE  padState;
		GetJoypadXInputState(DX_INPUT_PAD1, &padState);

		// �L�[���̎擾
		char keystate[256];
		GetHitKeyStateAll(keystate);

		// �}�E�X���̎擾
		int mouseState = GetMouseInput();

		// �}�b�v�̑S�������[�v
		for (const auto& keymap : m_inputMapTable)
		{
			// ���͏��z������[�v
			for (const auto& input : keymap.second)
			{
				// ���͏�񂩂�ǂ̃{�^�������͂���Ă��邩�m�F
				if (input.cat == InputCategory::KEYBORD)
				{
					m_currentInput[static_cast<int>(keymap.first)] = keystate[input.id];
				}
				else if (input.cat == InputCategory::PAD)
				{
					m_currentInput[static_cast<int>(keymap.first)] = padState.Buttons[input.id];
				}
				else if (input.cat == InputCategory::MOUSE)
				{
					m_currentInput[static_cast<int>(keymap.first)] = mouseState & input.id;
				}
				// 3�̓��͂̂����ǂꂩ��true����������͂���Ă邩��break
				if (m_currentInput[static_cast<int>(keymap.first)])
				{
					break;
				}
			}
		}
	}

	// �{�^���������ꂽ�u�Ԃ̓��͏��̎擾
	bool InputStateManager::IsTriggered(const InputType type)
	{
		return IsPressed(type) && !m_lastInput[static_cast<int>(type)];
	}

	// �{�^����������Ă���Ԃ̓��͏��̎擾
	bool InputStateManager::IsPressed(const InputType type)
	{
		return m_currentInput[static_cast<int>(type)];
	}

	// �p�b�h�̃g���K�[�̓��͏��̎擾
	bool InputStateManager::IsPadTrigger(const PadLR type)
	{
		// �p�b�h�̏��̎擾
		XINPUT_STATE  padState;
		GetJoypadXInputState(DX_INPUT_PAD1, &padState);

		// �g���K�[�̍����E��
		if (type == PadLR::LEFT)
		{
			// �g���K�[�������ȏ㉟����Ă�����true
			return 	padState.LeftTrigger > padState.LeftTrigger / 2;
		}
		else
		{
			// �g���K�[�������ȏ㉟����Ă�����true
			return 	padState.RightTrigger > padState.RightTrigger / 2;
		}
	}

	// �p�b�h�̃X�e�B�b�N�̓��͏����擾
	int InputStateManager::IsPadStick(const PadLR stick, const PadStickInputType type)
	{
		// �p�b�h�̏��̎擾
		XINPUT_STATE  padState;
		GetJoypadXInputState(DX_INPUT_PAD1, &padState);

		// �E�X�e�B�b�N�����X�e�B�b�N��
		float x, y;
		if (stick == PadLR::LEFT)
		{
			// padState����擾�����l�������₷���l�ɕϊ�
			x = static_cast<float>(padState.ThumbLX / 32767.0f * 100.0f);
			y = static_cast<float>(padState.ThumbLY / 32767.0f * 100.0f);
		}
		else
		{
			// padState����擾�����l�������₷���l�ɕϊ�
			x = static_cast<float>(padState.ThumbRX / 32767.0f * 100.0f);
			y = static_cast<float>(padState.ThumbRY / 32767.0f * 100.0f);
		}
		if (type == PadStickInputType::LEFT && x < -1.0f)
		{
			return abs(static_cast<int>(x));
		}
		if (type == PadStickInputType::RIGHT && x > 1.0f)
		{
			return abs(static_cast<int>(x));
		}
		if (type == PadStickInputType::UP && y > 1.0f)
		{
			return abs(static_cast<int>(y));
		}
		if (type == PadStickInputType::DOWN && y < -1.0f)
		{
			return abs(static_cast<int>(y));
		}

		// ���͂Ȃ�
		return 0;
	}

	// �p�b�h�̃X�e�B�b�N�̓��͏����擾
	bool IsPadStick(const PadLR stick, const PadStickInputType type, const PadStickStrength strength)
	{
		// ���͂��ꂽ�X�e�B�b�N�̓��͏���l�Ŏ擾
		int inputNum = IsPadStick(stick, type);

		// �����̋����ɂ���ē��͂��ꂽ�l���ǂ̒��x�̒l�ȏォ�Ŕ���
		if (strength == PadStickStrength::WEAK)
		{
			return inputNum > 10;
		}
		else if (strength == PadStickStrength::NORMAL)
		{
			return inputNum > 50;
		}
		else if (strength == PadStickStrength::STRONG)
		{
			return inputNum > 90;
		}
		return false;
	}
}