#include "DebugText.h"
#include <cassert>
#include <DxLib.h>

// �ÓI�����o�ϐ��̎��̉�
int DebugText::m_logCount = 0;
int DebugText::m_fontHandle = -1;
std::list<DebugText::LogData> DebugText::m_logList{};

// ������
void DebugText::Init()
{
// �f�o�b�O���̂�
#ifdef _DEBUG
	// ������
	m_logCount = 0;

	// �t�H���g���쐬
	m_fontHandle = CreateFontToHandle(font.c_str(), font_size, font_thickness);

	// �t�H���g�n���h�����쐬�ł������m�F
	assert(m_fontHandle != -1);
#endif
}

// �I������
void DebugText::End()
{
// �f�o�b�O���̂�
#ifdef _DEBUG
	// ���O�̃N���A
	ClearLog();

	// �t�H���g���폜
	DeleteFontToHandle(m_fontHandle);
#endif
}

// ���O�̃N���A
void DebugText::ClearLog()
{
// �f�o�b�O���̂�
#ifdef _DEBUG
	// ���O�̃��X�g���N���A
	m_logList.clear();

	// �J�E���g�����Z�b�g
	m_logCount = 0;
#endif
}

// ���O�̕`��
void DebugText::DrawLog()
{
// �f�o�b�O���̂�
#ifdef _DEBUG
	// �S�Ẵ��O����
	for (auto& log : m_logList)
	{
		// �������̔w�i�𕶎��̉����A�����ɍ��킹�ĕ`��
		int width = 0, height = 0, line = 0;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, draw_back_alpha);
		GetDrawStringSizeToHandle(&width, &height, &line, log.str.c_str(), log.str.size(), m_fontHandle);
		DrawBox(draw_width, (draw_height_interval * m_logCount) + draw_start_height, draw_width + width, (draw_height_interval * m_logCount) + height + draw_start_height, draw_back_color, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		// �����̕`��
		// ���O�̐������Ԋu���J���ĕ`��
		DrawStringToHandle(
			draw_width,
			draw_start_height + (draw_height_interval * m_logCount),
			log.str.c_str(),
			log.color,
			m_fontHandle);

		// �J�E���g
		m_logCount++;
	}
#endif
}

// ���O�̒ǉ�
void DebugText::AddLog(const std::string& string, unsigned int color)
{
// �f�o�b�O���̂�
#ifdef _DEBUG
	// ���O�f�[�^���쐬
	LogData logData;
	logData.str = string;
	logData.color = color;

	// ���O�̃��X�g�ɒǉ�
	m_logList.push_back(logData);
#endif
}