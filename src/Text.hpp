#pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.4.3

namespace Text {

    void addLineText(String& allText, const String& line);
    String readText(const String& filename);
    String constructFilename(size_t num);


    class Text {
        // 全てのテキスト
        String text;

        // テキストをfileNumのものに更新
        auto updateText(size_t fileNum);
    public:
        Text(size_t fileNum);

        // 描画
        void draw(int x, int y) const;
    };
}