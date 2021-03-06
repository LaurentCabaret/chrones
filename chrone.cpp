// Copyright (c) 2021 - present Laurent CABARET
// up to date version: https://github.com/LaurentCabaret/chrones

#include "chrone.hpp"

#include <cassert>
#include <fstream>

chrone::chrone(std::string filename) {
    _filename = filename;
}

chrone::~chrone() {
    std::ofstream file(_filename);
    file << "Label;Execution time in ns\n";
    for (auto& sample : _rack) {
        file << sample.first << ";" << sample.second << "\n";
    }
}

void chrone::appendTimer(std::string label, int64_t elapsed_time) {
    _rack.push_back(std::pair<std::string, int64_t>(label, elapsed_time));
}

int64_t chrone::getSize() {
    return _rack.size();
}

int64_t chrone::getDuration(const std::string& label) {
    for (const auto& sample : _rack) {
        if (sample.first == label) {
            return sample.second;
        }
    }
    assert(false);
}
