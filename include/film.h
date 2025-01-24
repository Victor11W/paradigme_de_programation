#ifndef FILM_H
#define FILM_H
#include "video.h"
#include <array>
class Film : public Video
{
private:
    int * chapter= nullptr;
    int number_chapter=0;

public:
    Film() : Video(), chapter(nullptr), number_chapter(0) {}

    Film(int duree, const std::string& name, const std::string& filename, int number_chapter, int* chapter)
    : Video(duree, name, filename), number_chapter(number_chapter) {
    if (number_chapter > 0 && chapter != nullptr) {
        this->chapter = new int[number_chapter];
        for (int i = 0; i < number_chapter; ++i) {
            this->chapter[i] = chapter[i];
        }
    }
}


    int * getChapter()const
    {
        return this->chapter;
    }

    int getTimeCode(const int numberChapter) const
    {
        if (this->number_chapter < numberChapter || numberChapter<1)
        {
            return -1;
        }
        else {
            return(this->chapter[numberChapter-1]);
        }
    }
    int getNumberChapter() const
    {
        return this->number_chapter;
    }

    void setChapter(int * chapter1,int number)
    {
        if (this->chapter != nullptr) {
            delete[] this->chapter;
        }
        this->number_chapter=number;
        int i = number;
        if (i!=0){
            this->chapter = new int[number];
        while(i!=0){
            this->chapter[number - i ]= chapter1[number-i];
            i-=1;
        }
        }
        else{
            this->chapter =nullptr;
            this->number_chapter=0;

        }
    }

    ~Film(){std::cout << "Element "<< this->getName()<< " à été supprimé"<< std::endl; }

    void displayChapters() const {
        int valeur;
        if (number_chapter == 0) {
            std::cout << "Il n'y a pas de chapitres dans ce film." << std::endl;
        } else {
            std::cout << "Durée des chapitres de " << getName() << " :\n";
            for (int i = 0; i < number_chapter; ++i) {
                if (i==0){valeur = chapter[i];}
                else {valeur =chapter[i]-chapter[i-1];}
                std::cout << "Chapitre " << (i + 1) << ": " << valeur << " secondes" << std::endl;
            }
        }
    }

    Film(const Film& other) : Video(other), chapter(nullptr), number_chapter(other.number_chapter) {
        int number= this->number_chapter;

        int * chapterCopy = (int *) malloc(sizeof(int)*number);
        if (number > 0) {
            chapterCopy = new int[number];
            for (int i = 0; i < number; ++i) {
                chapterCopy[i] = this->chapter[i];
            }
        }
        this->chapter = chapterCopy;
    }

    Film& operator=(const Film& other) {
        if (this != &other) {
            Video::operator=(other);
            int number= this->number_chapter;
            if (this->chapter != nullptr) {
                delete[] this->chapter;
            }
            int * chapterCopy = (int *) malloc(sizeof(int)*number);
            if (number > 0) {
                chapterCopy = new int[number];
                for (int i = 0; i < number; ++i) {
                    chapterCopy[i] = this->chapter[i];
                }
            }
            this->chapter = chapterCopy;
            this->number_chapter = other.number_chapter;
        }
        return *this;
    }

    void printAttribut(){
        std::cout << "Nom : " << this->getName() << std::endl;
        std::cout << "Durée : " << this->getDuree() << " secondes" << std::endl;
        std::cout << "Nombre de chapitres : " << this->number_chapter << std::endl;
        if (this->number_chapter > 0) {
            std::cout << "Chapitres : ";
            for (int i = 0; i < this->number_chapter; ++i) {
                std::cout << this->chapter[i];
                if (i < this->number_chapter - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
        }
    };

};

#endif // FILM_H
