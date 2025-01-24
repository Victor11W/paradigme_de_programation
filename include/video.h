#ifndef VIDEO_H
#define VIDEO_H

#include "basic.h"


class Video : public Basic
{
private:
    int duree;


public:
    Video(): Basic("", ""),duree(0){}

    Video(int duree1, const std::string& name, const std::string& filename)
        : Basic(name, filename), duree(duree1) {}


    int getDuree()const
    {
        return this->duree;
    }
    void setDuree(int la)
    {
        this->duree = la;
    }

    ~Video(){std::cout << "Element "<< this->getName()<< " à été supprimé"<< std::endl;}

    void play() const override
    {
        std::string arg = "xdg-open "+ getFileName()+" &";
        system(arg.data());
    }

    void printAttribut(std::ostream& out){ 
        out << "Nom : " << this->getName() << std::endl;
        out << "Durée : " << this->getDuree() << " secondes" << std::endl;
    }

    void save(std::ostream& out) const{
        out << "{";
        out << "\"type\": \"Video\", ";
        out << "\"name\": \"" << this->getName() << "\", ";
        out << "\"filename\": \"" << this->getFileName() << "\", ";
        out << "\"duree\": " << this->getDuree();
        out << "}";
};};

#endif // VIDEO_H
