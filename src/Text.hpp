#pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.4.3

namespace Text {

    void addLineText(String& allText, const String& line);
    String readText(const String& filename);
    String constructFilename(size_t num);


    class Text {
        // �S�Ẵe�L�X�g
        String text;

        // �e�L�X�g��fileNum�̂��̂ɍX�V
        auto updateText(size_t fileNum);
    public:
        Text(size_t fileNum);

        // �`��
        void draw(int x, int y) const;
    };
}