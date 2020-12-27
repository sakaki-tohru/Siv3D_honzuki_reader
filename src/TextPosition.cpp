#include "./TextPosition.hpp"

TextPosition::TextPosition():TextPosition(Vec2(30,60)){}

TextPosition::TextPosition(const Vec2& position):pos(position){}

Vec2 TextPosition::getPos() const {
    return pos;
}

void TextPosition::updatePosUsingSpeed(const Speed& speed) {
    pos.y -= speed.get();
}
