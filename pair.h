
#include <iostream>
using namespace std;

#ifndef PAIR_H_
#define PAIR_H_


template <class T, class U>
class Pair{
public:
    Pair(T t, U u)
    : m_first(t), m_second(u)
    {}

    Pair(Pair& pair)
    : m_first(pair.first()), m_second(pair.second())
    {}

    Pair()
    {}

    ~Pair(){}

    // Accessors
    const T& first() const{
        return m_first;
    }
    const U& second() const{
        return m_second;
    }

    // Mutators
    T& first(){
        return m_first;
    }
     U& second(){
        return m_second;
    }

private:
    T m_first;
    U m_second;
};

template <class T, class U>
ostream& operator<< (ostream& out, Pair<T,U>& p)
{
    return out << p.first() << " " << p.second();
}

#endif /* PAIR_H_ */
