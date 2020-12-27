#pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "./Speed.hpp"

class TextPosition {
    Vec2 pos;
public:
    TextPosition();
    TextPosition(const Vec2& position);

    Vec2 getPos()const;

    void updatePosUsingSpeed(const Speed& speed);
};
