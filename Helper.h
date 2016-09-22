//
// Created by Mariusz Osowski on 22/9/16.
//

#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>

typedef std::pair<int, int> Vec2;

void OpenInBrowser(const std::string& url);

bool Save(std::string path, std::string content);

std::string renderMapToHtml(std::vector<std::vector<int>>& map);

void drawPathOnMap(std::vector<std::vector<int>>& map, std::vector<Vec2>& path);

std::vector<std::vector<int>> generateMap(unsigned sizeX, unsigned sizeY);

#endif //HELPER_H
