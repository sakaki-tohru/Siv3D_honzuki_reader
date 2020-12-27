#pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.4.3

namespace Text {

    void addLineText(String& allText, const String& line);
    String readText(const String& filename);
    String constructFilename(size_t num);


    class Text {
        String text;

        auto updateText(size_t fileNum) {
            text = readText(constructFilename(fileNum));
        }
    public:
        Text(size_t fileNum) {
            updateText(fileNum);
        }

        auto draw(const Font& font, int x, int y) const {
            font(text).draw(x, y);
        }
    };
}