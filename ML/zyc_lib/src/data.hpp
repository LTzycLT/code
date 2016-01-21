#ifndef _DATA_HPP_
#define _DATA_HPP_

#include "machine_learning.h"

template<typename TX, typename TY>
class Case
{
    private:
        vector<TX> x;
        TY y;
    public:
        Case(vector<TX> _x, TY _y){x = _x; y = _y;}
        int get_size(){return x.size();}
        TX get_x(int i){return x[i];}
        TY get_y(){return y;}
        void log()
        {
            for(int i = 0; i < x.size(); i++) 
            {
                cout << x[i] << " ";
            }
            cout << y << endl;
        }
};


template<typename TX, typename TY>
class Input
{
    private:
        int n;
        vector<Case<TX, TY> > cases;
        Input(){}

    public:
        Input(int _n){n = _n;}
        ~Input(){}
        
        int get_n(){return n;}
        int get_m(){return cases.size();}

        bool add_case(Case<TX, TY> c)
        {
            if(c.get_size() == n){cases.push_back(c);return true;}
            return false;
        }
        Case<TX, TY> get_case(int i){ return cases[i];}
};

template<typename T>
class Thetas
{
    private:
        int convert_i(int i)
        {
            if(i >= 0) return i;
            else return thetas.size() - i;
        }
        vector<T> thetas;
    public:
        void clear(){return thetas.clear();}
        int size(){return thetas.size();}
        void set(int i, T value){i=convert_i(i);thetas[i] = value;}
        T get(int i){i=convert_i(i);thetas[i];}
        void add(T value){thetas.push_back(value);}
        void log()
        {
            for(int i = 0; i < thetas.size(); i++)
                cout << thetas[i] << " ";
            cout << endl;
        }
};
#endif
