#include "DxLib.h"
#include <cassert>
#include <vector>
#include "game.h"
#include "SceneMain.h"
#include "Pad.h"
#include "Vec2.h"

//bool CheckHit(Vec2 playerMinHitBox,Vec2 playerMaxHitBox,Vec2 objectMinHitBox,Vec2 objectMaxHitBox) {
//
//
//	if (playerMinHitBox.y > objectMaxHitBox.y)		return false;
//	if (playerMaxHitBox.y < objectMinHitBox.y)		return false;
//	if (playerMinHitBox.x > objectMaxHitBox.x)		return false;
//	if (playerMaxHitBox.x < objectMinHitBox.x)		return false;
//
//	return true;
//
//}

//bool CheckOutMap(Vec2 playerMinHitBox, Vec2 playerMaxHitBox, Vec2 minMapSize, Vec2 maxMapSize) {
//
//	bool OutMap = false;
//
//	if (playerMinHitBox.y < minMapSize.y)		OutMap = true;
//	if (playerMaxHitBox.y > maxMapSize.y)		OutMap = true;
//	if (playerMinHitBox.x < minMapSize.x)		OutMap = true;
//	if (playerMaxHitBox.x > maxMapSize.x)		OutMap = true;
//	
//	return OutMap;
//
//
//	//return false;
//}

SceneMain::SceneMain()
{
	m_isMenu = false;
	m_isPlayerHit = false;
	m_isEnemyHit = false;
}

SceneMain::~SceneMain()
{

}

// 初期化
void SceneMain::init()
{

	m_menuWindow.init();


	m_isMenu = false;
	m_isOpenWindow = false;

	
}

// 終了処理
void SceneMain::end()
{

	m_menuWindow.end();
	
}

// 毎フレームの処理
void SceneMain::update()
{
	if (!m_isOpenWindow) {
		if (Pad::isTrigger(PAD_INPUT_4)) {
			m_isOpenWindow = true;
		}
	}
	else {
		if (Pad::isTrigger(PAD_INPUT_4)) {
			m_isOpenWindow = false;
		}
	}

	if (m_isOpenWindow) {

		m_menuWindow.update();

		m_isGameEnd = m_menuWindow.getisGameEnd();

		return;
	}

	

	if (Pad::isTrigger(PAD_INPUT_8)) {
		m_isMenu = true;
	}

}

// 毎フレームの描画
void SceneMain::draw()
{
	if (m_isOpenWindow) DrawFormatString(0, 0, GetColor(255, 0, 0), "・", true);

	if (m_isOpenWindow) {

		m_menuWindow.draw();

	}

}
