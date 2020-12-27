#include "./TextList.hpp"

namespace Text {

    size_t round(size_t now) {
        if (now == 0) return 1;
        if (now == 678) return 677;
        return now;
    }

    void TextList::increment() {
        nowFile = round(nowFile + 1);
        text = Text(nowFile);
    }

    void TextList::decrement() {
        nowFile = round(nowFile - 1);
        text = Text(nowFile);
    }

    void TextList::draw(int x, int y) const {
        text.draw(x, y);
    }

}