#pragma once
#include "./Text.hpp"

namespace Text {
    void addLineText(String& allText, const String& line) {
        const size_t splitsize = 37;
        size_t old = 0;
        while (line.size() > old) {
            allText += line.substr(old, Min(splitsize, line.size() - old));
            allText += U"\n";
            old += splitsize;
        }
    }
    String readText(const String& filename) {
        auto reader = TextReader();
        reader.open(filename);
        if (!reader) {
            throw Error(U"Failed to open .txt");
        }
        String line;
        String allText = U"";
        while (reader.readLine(line)) {
            addLineText(allText, line);
        }
        return allText;
    }
    String constructFilename(size_t num) {
        static const String Title = U"honzuki/N4830BU-";
        return Title + U"{:0>5}"_fmt(num) + U".txt";
    }
}