#pragma once
#include <vector>
#include <memory>
#include "../Component/ComponentBase.h"

namespace Object
{
	/// <summary>
	/// オブジェクトの基底クラス
	/// </summary>
	class Base
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		Base();

		/// <summary>
		/// デストラクタ
		/// </summary>
		virtual ~Base();

		/// <summary>
		/// 初期化
		/// </summary>
		virtual void Init() = 0;

		/// <summary>
		/// 終了処理
		/// </summary>
		virtual void End() = 0;

		/// <summary>
		/// 更新
		/// </summary>
		virtual void Update() = 0;

		/// <summary>
		/// 描画
		/// </summary>
		virtual void Draw() = 0;

		/// <summary>
		/// アクティブ状態を設定する
		/// </summary>
		/// <param name="isActive">アクティブ状態フラグ</param>
		void SetActive(const bool isActive) { m_isActive = isActive; }

		/// <summary>
		/// アクティブ状態を取得する
		/// </summary>
		/// <returns>アクティブ状態</returns>
		bool IsActive() const { return m_isActive; }

		/// <summary>
		/// 指定された型のコンポーネントを取得する
		/// </summary>
		/// <typeparam name="T">コンポーネントの型</typeparam>
		/// <returns>コンポーネント</returns>
		template<class T> 
		T* GetComponent()
		{
			for (auto& component : m_pComponentList)
			{
				// コンポーネントをT型にキャスト
				auto castedComponent = dynamic_cast<T*>(component.get()));

				// キャストに成功した場合はそのコンポーネントをreturn
				if (castedComponent)
				{
					return castedComponent;
				}
			}	
			// 当該コンポーネントがなければnullptrをreturn
			return nullptr;
		}

	protected:
		/// <summary>
		/// コンポーネントを追加する
		/// 所有権をこのクラスで所有したい為、右辺値参照で受け取る
		/// </summary>
		/// <param name="component">コンポーネントの右辺値</param>
		void AddComponent(std::unique_ptr<Component::Base>&& pComponent);

		template<class T> 
		T* AddComponent()
		{
			// コンポーネントを生成
			auto pComponent = std::make_unique<T>();

			// コンポーネントを追加
			AddComponent(std::move(pComponent));

			// コンポーネントをreturn
			return pComponent.get();
		}

	protected:
		// コンポーネントリスト
		std::vector<std::unique_ptr<Component::Base>> m_pComponentList;

		// アクティブ状態
		// 非アクティブ状態の場合は更新処理、描画処理を行わない
		bool m_isActive;
	};
}