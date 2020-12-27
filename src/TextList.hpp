# include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "./Text.hpp"

namespace Text {

    size_t round(size_t now);

    class TextList {
        // 現在のファイル
        int nowFile;
        Text text;
    public:
        TextList() :nowFile(1), text(nowFile) {}

        // ページの進退
        void increment();
        void decrement();

        // 描画
        void draw(int x, int y)const;
        void draw(const Vec2& pos)const;

    };

}