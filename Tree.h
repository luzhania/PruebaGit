#include <iostream>
#include "Vertex.h"
#include <math.h>
#define CAPACITY 100

using namespace std;

template <typename T>
class Tree
{
    private:
        Vertex<T> vec[CAPACITY];
    public:
        bool vertexIsEmpty(int pos)
        {
            return vec[pos].getExists() == false;
        }

        void insertRandomly(T element, int pos)
        {
            bool ans;
            if(pos < CAPACITY)
            {
                if(vertexIsEmpty(pos))
                {
                    vec[pos].setExists(true);
                    vec[pos].setElement(element);
                }
                else
                {
                    int leftOrRight = (rand()%51) % 2;
                    if (leftOrRight == 1)
                        insertRandomly(element, pos * 2);
                    else
                        insertRandomly(element, pos * 2 + 1);
                }
            }
        }

        void visitInOrder(int pos)
        {
            if(!vertexIsEmpty(pos))
            {
                visitInOrder(pos * 2); //left
                cout << vec[pos].getElement() << "\t";
                visitInOrder(pos * 2 + 1); //right
            }
        }

        void visitPreOrder(int pos)
        {
            if(!vertexIsEmpty(pos))
            {
                cout << vec[pos].getElement() << "\t ";
                visitPreOrder(pos * 2);
                visitPreOrder(pos * 2 + 1);
            }
        }

        void visitPostOrder(int pos)
        {
            if(!vertexIsEmpty(pos))
            {
                visitPostOrder(pos * 2);
                visitPostOrder(pos * 2 + 1);
                cout << vec[pos].getElement() << "    ";
            }
        }

        int countNodes(int pos)
        {
            int ans;
            if(vertexIsEmpty(pos))
                ans = 0;
            else
                ans = countNodes(pos * 2) + countNodes(pos * 2 + 1) + 1;
            return ans;
        }

        int calculateHeight(int pos)
        {
            int height, height1, height2;
            if(vertexIsEmpty(pos))
                height = 0;
            else
            {
                height1 = calculateHeight(pos * 2);
                height2 = calculateHeight(pos * 2 + 1);
                if(height1 > height2)
                    height = height1 + 1;
                else
                    height = height2 + 1;
            }
            return height;
        }

        void print()
        {
            for(int i = 1; i < CAPACITY; i++)
            {
                cout << vec[i].getElement() << "    ";
            }
        }
        void printWithFormat()
        {
            int height = calculateHeight(1);
            for (int h = 0; h < height; h++)
            {
                int top = (pow(2, h + 1) - pow(2, h));
                int v1 = pow(2, h);
                for(int vertex = 0; vertex < top; vertex++)
                {
                    cout << vec[v1].getElement() << "    ";
                    v1++;
                }
                cout << endl;
            }
        }

        Tree<T> mirrorTree()
        {
            Tree<T> mirrorT;
            int height = calculateHeight(1);
            if (height > 1)
                mirrorT.insert(1, vec[1].getElement());
            for (int h = 0; h < height; h++)
            {
                int top = (pow(2, h + 1) - pow(2, h))/2;
                int v1 = pow(2, h);
                int v2 = pow(2, h + 1) - 1;
                for(int vertex = 0; vertex < top; vertex++)
                {
                    mirrorT.insert(v2, vec[v1].getElement());
                    mirrorT.insert(v1, vec[v2].getElement());
                    v1++;
                    v2--;
                }
            }
            return mirrorT;
        }

        void insert(int pos, int element)
        {
            vec[pos].setExists(true);
            vec[pos].setElement(element);
        }
};