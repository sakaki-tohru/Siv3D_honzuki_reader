
# include <Siv3D.hpp> // OpenSiv3D v0.4.3

size_t round(size_t now) {
	if (now == 0) return 1;
	if (now == 678) return 677;

	return now;
}

auto readText(const String& filename) {
	auto reader = TextReader();
	reader.open(filename);
	if (!reader) {
		throw Error(U"Failed to open .txt");
	}
	String line;
	String allText = U"";
	while (reader.readLine(line)) {
		allText += U"{}\n"_fmt(line);
	}
	return allText;
}

auto constructFilename(int num) {
	static const String Title = U"honzuki/N4830BU-";
	return Title + U"{:0>5}"_fmt(num) + U".txt";
}

void Main()
{
	// 背景を水色にする
	Scene::SetBackground(ColorF(0.8, 0.9, 1.0));

	// 大きさ 60 のフォントを用意
	const Font font(20);

	size_t now = 1;
	double v = 0.0;
	// textのy座標
	auto fontYpos = 60.0;

	// 最初のテキストを読み込み
	auto text = readText(constructFilename(now));

	while (System::Update())
	{
		// マウスカーソルに追従する半透明の赤い円を描く
		Circle(Cursor::Pos(), 10).draw(ColorF(1, 0, 0, 0.5));

		font(text).draw(10, fontYpos);
		fontYpos-=v;

		// ボタンが押されたら
		if (SimpleGUI::Button(U"Next Story", Vec2(600, 20)))
		{
			now = round(now + 1);
			text = readText(constructFilename(now));
			fontYpos = 60.0;
			//ClearPrint();
		}
		// ボタンが押されたら
		if (SimpleGUI::Button(U"Prev Story", Vec2(10, 20)))
		{
			now = round(now - 1);
			text = readText(constructFilename(now));
			fontYpos = 60.0;
			//ClearPrint();
		}
		SimpleGUI::Slider(U"読む速度", v, 0.0, 10.0, Vec2(270, 20));
		//スライド
	}
}