#include "../include/groupe.h"
#include <string>
#include "../include/video.h"
#include "../include/film.h"
#include "../include/photo.h"
#include <memory>
// on va faire ue classe groupe qui contient une liste d'List
Groupe::Groupe():Name(""),List(){}

Groupe::Groupe(std::string Name,const std::list<BasicPtr>& List)
    : Name(std::move(Name)), List(List) {}

std::list<BasicPtr> Groupe::getList() const {
    return this->List;
}

void Groupe::AfficheElement(int i, std::ostream& out) {
    int k = List.size();
    if (i < 0 || i >= k) {
        out << "Index hors limites.";
        return;
    }

    auto it = List.begin();
    std::advance(it, i);  // Avance jusqu'à l'index i

    BasicPtr element = *it;
    if (auto filmElement = std::dynamic_pointer_cast<Film>(element)) {
        out << "le "<< i+1 <<"ème élément de la list est un film, ce film s'appelle " << filmElement->getName() << " et dure " << filmElement->getDuree() << " minutes ";
        filmElement->displayChapters();
    } else if (auto videoElement = std::dynamic_pointer_cast<Video>(element)) {
        out << "le "<< i+1 <<"ème élément de la list est une video, cette vidéo s'appelle " << videoElement->getName() << " et dure " << videoElement->getDuree() << " minutes." ;
    } else if (auto photoElement = std::dynamic_pointer_cast<Photo>(element)) {
        out << "le "<< i+1 <<"ème élément de la list est une photo, cette photo s'appelle " << photoElement->getName();
    }else {
        out << "Cet élément n'est ni un Film ni une Vidéo." ;
    }
}
    Groupe::~Groupe(){
        for (auto& element : List) {
            element.reset();  // Réinitialiser chaque shared_ptr pour chaque élément
        }
        List.clear();
    }

    void Groupe::setName(std::string Name){
        this->Name = Name;
    }

    std::string Groupe::getName()const{
        return this->Name;
    }



    void Groupe::setList(std::list<BasicPtr> List){
        this->List = List;
    }
    

void Groupe::Affiche(std::ostream& out) {
    int k = List.size();
    for(int i =0;i<k;i++){
        AfficheElement(i,out);
    }
}

void Groupe::save(std::ostream& out) {
    out << "{";
    out << "\"type\": \"Groupe\", ";
    out << "\"name\": \"" << this->Name << "\", ";
    out << "\"List\": [";
    int k = List.size();
    int i = 0;
    for (auto& element : List) {
        element->save(out);
        if (i < k - 1) {
            out << ", ";
        }
        i++;
    }
    out << "]";
    out << "}";
}
