#include <string>
#include <list>
#include "../include/createandmodify.h"




CreateAndModify::CreateAndModify():multimediaTable(),groupTable(){};

CreateAndModify::~CreateAndModify() {}


std::shared_ptr<Video> CreateAndModify::createVideo(const std::string name, const std::string filename,int duree)
{
    auto video = std::make_shared<Video>(duree,name, filename);
    multimediaTable[name] = video;
    return video;
};

std::shared_ptr<Film> CreateAndModify::createFilm(const std::string name, const std::string filename, int duree, int number_chapter, int * chapter)
{
    auto film = std::make_shared<Film>(duree, name, filename, number_chapter, chapter);
    multimediaTable[name] = film;
    return film;

};
    
std::shared_ptr<Photo> CreateAndModify::createPhoto(const std::string name, std::string filename, int latitude, int longitude)
{
    auto photo = std::make_shared<Photo>(latitude, longitude, name, filename);
    multimediaTable[name] = photo;
    return photo;
};

std::shared_ptr<Groupe> CreateAndModify::createGroupe(const std::string name, const std::list<std::string>& List)
{
    if (groupTable.find(name) != groupTable.end()) {
    std::cerr << "Un groupe avec le nom '" << name << "' existe déjà." << std::endl;
    return nullptr; // Ou une autre gestion appropriée
}

    std::list<std::shared_ptr<Basic>> empty_list;
    for (const auto& element : List){
        if (multimediaTable.find(element) != multimediaTable.end()){
            empty_list.push_back(multimediaTable[element]);
        }
    }
    auto groupe = std::make_shared<Groupe>(name,empty_list);
    groupTable[name] = groupe;
    return groupe;
};

void CreateAndModify::displayObject(const std::string& name,std::ostream& out,bool isgroup) const
{
    
    if (isgroup){
        auto it = groupTable.find(name);
        if (it == groupTable.end()){
            out << "Groupe not found";
            return;
        }
        auto groupeElement = it->second;
        groupeElement->Affiche(out);
        return;
    }
    else {
    auto it = multimediaTable.find(name);
    auto element = it->second;
    if (auto filmElement = std::dynamic_pointer_cast<Film>(element)) {
        out<< "ce film s'appelle " << filmElement->getName() << " et dure " << filmElement->getDuree() << " minutes ";
        filmElement->displayChapters();
    } else if (auto videoElement = std::dynamic_pointer_cast<Video>(element)) {
        out << "c'est une video, cette vidéo s'appelle " << videoElement->getName() << " et dure " << videoElement->getDuree() << " minutes." ;
    } else if (auto photoElement = std::dynamic_pointer_cast<Photo>(element)) {
        out << "c'est une photo, cette photo s'appelle " << photoElement->getName();
    }else {
        out << "Cet élément n'est pas pris en compte."; }

}};

void CreateAndModify::playObject(const std::string& name) const
{
    auto it = multimediaTable.find(name);
    if (it != multimediaTable.end()){
        it->second->play();
    } else {
        std::cout << "Object not found" << name << std::endl;
    }
};

bool CreateAndModify::isInMultimediatable(const std::string name)
{
    auto it = multimediaTable.find(name);
    if (it != multimediaTable.end()){
        return true;
    } else {
        return false;
    }
};

bool CreateAndModify::isInGroupeTable(const std::string name)
{
    auto it = groupTable.find(name);
    if (it != groupTable.end()){
        return true;
    } else {
        return false;
    }
};