
# include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "./src/Text.hpp"

size_t round(size_t now) {
	if (now == 0) return 1;
	if (now == 678) return 677;

	return now;
}

void Main()
{
	// 背景を水色にする
	Scene::SetBackground(ColorF(0.5, 0.6, 7.0));

	const Font font(20);

	//読んでいる話数
	size_t now = 1;

	//読む速度
	double v = 0.0;

	// textのy座標
	auto fontYpos = 60.0;

	// 最初のテキストを読み込み
	auto text = Text::Text(1);

	while (System::Update())
	{
		// マウスカーソルに追従する半透明の赤い円を描く
		Circle(Cursor::Pos(), 10).draw(ColorF(1, 0, 0, 0.5));

		text.draw(font,30, fontYpos);
		fontYpos-=v;

		// ボタンが押されたら
		if (SimpleGUI::Button(U"Next Story", Vec2(600, 20)))
		{
			now = round(now + 1);
			text = Text::Text(now);
			fontYpos = 60.0;
			v = 0.0;
		}
		// ボタンが押されたら
		if (SimpleGUI::Button(U"Prev Story", Vec2(10, 20)))
		{
			now = round(now - 1);
			text = Text::Text(now);
			fontYpos = 60.0;
			v = 0.0;
		}
		//スライド
		SimpleGUI::Slider(U"読む速度", v, -5.0, 5.0, Vec2(270, 20));
	}
}