#include <iostream>

using namespace std;

template <typename T>
class Vertex
{
    private:
        bool exists;
        T element;
    public:
        Vertex()
        {
            this->exists = false;
            this->element = 0;
        }

        bool getExists()
        {
            return this->exists;
        }

        T getElement()
        {
            return this->element;
        }

        void setExists(bool exists)
        {
            this->exists = exists;
        }

        void setElement(T element)
        {
            this->element = element;
        }
};

