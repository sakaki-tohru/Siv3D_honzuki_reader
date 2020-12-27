
# include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "./src/TextList.hpp"
#include "./src/Speed.hpp"
#include "./src/TextPosition.hpp"

void Main()
{
	// 背景を水色にする
	Scene::SetBackground(ColorF(0.5, 0.6, 7.0));

	FontAsset::Register(U"font", 20);

	//読む速度
	Speed speed(0.0);

	// textのy座標
	auto textPos = TextPosition({30.0, 60.0});

	// 最初のテキストを読み込み
	auto text = Text::TextList();

	while (System::Update())
	{
		// マウスカーソルに追従する半透明の赤い円を描く
		Circle(Cursor::Pos(), 10).draw(ColorF(1, 0, 0, 0.5));

		text.draw(textPos.getPos());
		textPos.updatePosUsingSpeed(speed);

		// ボタンが押されたら
		if (SimpleGUI::Button(U"Next Story", Vec2(600, 20)))
		{
			text.increment();
			textPos = TextPosition();
			speed = Speed();
		}
		// ボタンが押されたら
		if (SimpleGUI::Button(U"Prev Story", Vec2(10, 20)))
		{
			text.decrement();
			textPos = TextPosition();
			speed = Speed();
		}
		//スライド
		speed.adjust();
	}
}