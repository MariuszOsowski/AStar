//
// Created by Mariusz Osowski on 22/9/16.
//


#include "Helper.h"
#include <fstream>
#include <iostream>

#ifdef _WIN32 //Win32/64b

#include <windows.h>

void OpenInBrowser(const std::string &url) {
    ShellExecuteA(NULL,"open",url.c_str(),NULL,NULL,SW_SHOWNORMAL);
}

#elif defined __linux__ //Linux32/64b

void OpenInBrowser(const std::string& url) {
    std::string command = "xdg-open "+url;
    system(command.c_str());
}

#endif

bool Save(std::string path, std::string content) {
    std::ofstream output(path);

    if (output.is_open()) {
        output << content;
        output.close();
    }
    else {
        std::cout << "Error opening file " << path << std::endl;
        return false;
    }

    return true;
}

void drawPathOnMap(std::vector<std::vector<int>>& map, std::vector<Vec2>& path) {
    for (auto& node: path) {
        map[node.second][node.first] = 3;
    }
}

std::vector<std::vector<int>> generateMap(unsigned sizeX, unsigned sizeY) {
    std::vector<std::vector<int>> map(sizeY);

    for (unsigned i = 0; i<sizeY; i++) {
        std::vector<int> row(sizeX);
        for (unsigned j = 0; j<sizeX; j++) {

            if (j%5==0) {
                row[j] = (rand()%5) ? 5 : 0;
            }
            else {
                row[j] = (rand()%4) ? 0 : 5;
            }

        }
        map[i] = row;
    }

    return map;
}

std::string renderMapToHtml(std::vector<std::vector<int>>& map) {
    std::string html;
    html += "<!DOCTYPE html>\n";
    html += "<head>\n";
    html += "<style>\n";
    html += "	body {\n";
    html += "	 	background: #333;\n";
    html += "	  	height: 100vh;\n";
    html += "	  	display: flex;\n";
    html += "	  	justify-content: center;\n";
    html += "	  	align-items: center;\n";
    html += "	}\n";
    html += "	.canvas {\n";
    html += "	  	width: 600px;\n";
    html += "	  	height: 600px;\n";
    html += "	  	border: 2px solid #fff;\n";
    html += "	}\n";
    html += "	.pixel {\n";
    html += "		width: 10px;\n";
    html += "		height: 10px;\n";
    html += "		float: left;\n";
    html += "	}\n";
    html += "	.obstacle {\n";
    html += "	  	box-shadow: 0px 0px 1px #fff;\n";
    html += "	  	background: red;\n";
    html += "	}\n";
    html += "	.path {\n";
    html += "	    border-radius: 3px;\n";
    html += "	    background: lightblue;\n";
    html += "	    width: 6px;\n";
    html += "	    height: 6px;\n";
    html += "	    margin: 2px;\n";
    html += "	    box-shadow: 0px 0px 1px #fff;\n";
    html += "	}\n";
    html += "</style>\n";
    html += "</head>\n";
    html += "<html>\n";
    html += "<body>\n";

    html += "   <div class=\"canvas\">\n";

    for (auto& row : map) {
        for (auto& col : row) {
            std::string cssClass = "pixel \n";

            if (col==3) cssClass += "path\n";
            else if (col==5) cssClass += "obstacle\n";

            html += "<div class=\""+cssClass+"\"></div>\n";
        }
    }

    html += "</body>\n";
    html += "</html>\n";

    return html;
}
