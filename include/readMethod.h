#ifndef READMETHOD_H
#define READMETHOD_H
#include "basic.h"
#include "video.h"
#include "photo.h"
#include "film.h"
#include "groupe.h"
#include <array>
#include <sstream>
#include <algorithm>
#include <vector>
#include <nlohmann/json.hpp>
#include <iostream>



class readMethod {
    private : 
    readMethod() = default;

    public : 
    
    static std::shared_ptr<Basic> readElement(std::istream& in) {
    std::string line, type, name, filename;
    int latitude = 0, longitude = 0, duree = 0, number_chapter = 0;
    std::vector<int> chapters;

    std::getline(in, line);
    if (line.front() != '{' || line.back() != '}') {
        throw std::runtime_error("Format JSON invalide !");
    }
    nlohmann::json j = nlohmann::json::parse(line);

    type = j.at("type");
    name = j.at("name");
    filename = j.at("filename");

    if (type == "Photo") {
        latitude = j.at("latitude");
        longitude = j.at("longitude");
        return std::make_shared<Photo>(latitude, longitude, name, filename);
    } else if (type == "Video") {
        duree = j.at("duree");
        return std::make_shared<Video>(duree, name, filename);
    } else if (type == "Film") {
        duree = j.at("duree");
        chapters = j.at("chapters").get<std::vector<int>>();
        number_chapter = j.at("number_chapter");
        int* chapterArray = new int[number_chapter];
        std::copy(chapters.begin(), chapters.end(), chapterArray);
        auto film = std::make_shared<Film>(duree, name, filename, number_chapter, chapterArray);
        delete[] chapterArray;
        return film;
    }

    throw std::runtime_error("Type inconnu : " + type);
}

static Groupe readGroupe(std::istream& in) {
    std::string line, name;
    std::list<std::shared_ptr<Basic>> elements;

    std::getline(in, line);
    if (line.front() != '{' || line.back() != '}') {
        throw std::runtime_error("Format JSON invalide !");
    }
    nlohmann::json j = nlohmann::json::parse(line);

    name = j.at("name");
    for (const auto& element : j.at("List")) {
        try {
            std::istringstream ss(element.dump());
            elements.push_back(readElement(ss));
        } catch (const std::exception& e) {
            std::cerr << "Erreur lors de la lecture d'un élément : " << e.what() << std::endl;
        }
    }

    return Groupe(name, elements);
};

};



#endif // READMETHOD_H