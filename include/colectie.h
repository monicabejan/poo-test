#ifndef COLECTIE_H
#define COLECTIE_H

#include <vector>
#include <stdexcept>

template <typename T>
class colectie{
    std::vector<T> elemente;
    std::string nume;
public:
    explicit colectie(const std::string& nume) : nume(nume) {}
    void adauga(const T& elem) {elemente.push_back(elem);}
    const T& get(int index) const {
        if(index<0 || index >=(int)elemente.size())
            throw std::out_of_range("Index invalid in "+nume);
        return elemente[index];
    }

    int size() const { return (int)elemente.size();}
    bool esteGoala() const { return elemente.empty();}

    typename std::vector<T>::const_iterator begin() const {return elemente.begin();}
    typename std::vector<T>::const_iterator end() const {return elemente.end();}
};
#endif