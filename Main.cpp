
# include <Siv3D.hpp> // OpenSiv3D v0.4.3

size_t round(size_t now) {
	if (now == 0) return 1;
	if (now == 678) return 677;
	
	return now;
}

void Main()
{
	// 背景を水色にする
	Scene::SetBackground(ColorF(0.8, 0.9, 1.0));

	// 大きさ 60 のフォントを用意
	const Font font(60);

	TextReader reader;
	size_t now = 0;
	String Title = U"honzuki/N4830BU-";
	reader.open(Title + U"{:0>5}"_fmt(++now) + U".txt");
	String line=U"";

	if (!reader)
	{
		throw Error(U"Failed to open .txt");
	}
	Print << U"";Print << U"";
	if (reader.readLine(line))
	{
		Print << U"{}"_fmt(line);
	}

	while (System::Update())
	{
		// マウスカーソルに追従する半透明の赤い円を描く
		Circle(Cursor::Pos(), 10).draw(ColorF(1, 0, 0, 0.5));


		// [Space] キーが押されたら
		if (KeySpace.down())
		{
			if (reader.readLine(line)) 
			{
				Print << U"{}"_fmt(line);
			}
		}

		// ボタンが押されたら
		if (SimpleGUI::Button(U"Next Story", Vec2(600, 20)))
		{
			now = round(now + 1);
			reader.open(Title+U"{:0>5}"_fmt(now)+U".txt");
			ClearPrint();
			Print << U"";Print << U"";
			if (reader.readLine(line))
			{
				Print << U"{}"_fmt(line);
			}
		}
		if (SimpleGUI::Button(U"Prev Story", Vec2(10, 20)))
		{
			now = round(now - 1);
			reader.open(Title + U"{:0>5}"_fmt(now) + U".txt");
			ClearPrint();
			Print << U"";Print << U"";
			if (reader.readLine(line))
			{
				Print << U"{}"_fmt(line);
			}
		}
	}
}