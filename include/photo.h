#ifndef PHOTO_H
#define PHOTO_H

#include "basic.h"

class Photo : public Basic
{
private:
    int lattitude;
    int longitude;


public:

    Photo() : Basic("", ""), lattitude(0), longitude(0) {}

    Photo(int la, int lo, const std::string& name, const std::string& filename)
        : Basic(name, filename), lattitude(la), longitude(lo) {}

    int getLat()const
    {
        return this->lattitude;
    }
    int getLong()const
    {
        return this->longitude;
    }

    void setLat(int la)
    {
        this->lattitude = la;
    }
    void setlong(int lo)
    {
        this->longitude = lo;
    }

    ~Photo(){std::cout << "Element "<< this->getName()<< " à été supprimé"<< std::endl; }

    void play() const override
    {
        std::string arg = "xdg-open "+ getFileName()+" &";
        system(arg.data());
    }

    void printAttribut(std::ostream& out){
        out << "Nom : " << this->getName();
        out << "Lattitude : " << this->getLat();
        out << "Longitude : " << this->getLong();
    }

    void save(std::ostream& out) const {
        out << "{";
        out << "\"type\": \"Photo\", ";
        out << "\"name\": \"" << this->getName() << "\", ";
        out << "\"filename\": \"" << this->getFileName() << "\", ";
        out << "\"latitude\": " << this->getLat() << ", ";
        out << "\"longitude\": " << this->getLong();
        out << "}";
    }

};

#endif // PHOTO_H
