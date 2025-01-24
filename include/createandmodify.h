#ifndef create_and_modify_H
#define create_and_modify_H
#include "basic.h"
#include "groupe.h"
#include "video.h"
#include "film.h"
#include "photo.h"
#include <array>
#include <map>


class CreateAndModify 
{   
private : 
    std::map<std::string, std::shared_ptr<Basic>> multimediaTable;
    std::map<std::string, std::shared_ptr<Groupe>> groupTable;

public : 

    CreateAndModify();
    ~CreateAndModify();

    std::shared_ptr<Video> createVideo(const std::string name, const std::string filename, int duree);
    std::shared_ptr<Film> createFilm(const std::string name, const std::string filename, int duree, int number_chapter, int * chapter);
    std::shared_ptr<Photo> createPhoto(const std::string name, const std::string filename, int latitude, int longitude);
    std::shared_ptr<Groupe> createGroupe(const std::string name, const std::list<std::string>&List);

    bool isInMultimediatable(const std::string name);
    bool isInGroupeTable(const std::string name);

    void displayObject(const std::string& name,std::ostream& out,bool isgroup) const;
    void playObject(const std::string& name) const;


};

#endif // create_and_modify_H