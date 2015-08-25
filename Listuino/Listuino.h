/*
Copyright 2015 Hugo LEVY-FALK

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef H_LISTUINO
#define H_LISTUINO

template <typename T>
class ListElement
{
public:
    ListElement(T value, ListElement<T>* previous, ListElement<T>* next)
        :_value(value), _next(next), _previous(previous)
        {}
    ~ListElement(){}
    T getValue(){return _value;}
    void setValue(T value){_value = value;}
    void setPrevious(ListElement<T>* previous) {_previous = previous;}
    ListElement<T>* getPrevious() {return _previous;}
    void setNext(ListElement<T>* next) {_next = next;}
    ListElement<T>* getNext() {return _next;}
private:
    T _value;
    ListElement<T>* _next;
    ListElement<T>* _previous;
};

template <typename T>
class List
{
public:
    List():_first(0),_last(0),_length(0){}
    ~List()
    {
        ListElement <T> * current = _first;
        for (int i = 0; i < _length; ++i)
        {
            ListElement <T> * tmp = current;
            current = current->getNext();
            delete tmp;
        }
    }
    void append(T value)
    {
        ListElement <T> * n = new ListElement<T>(value, _last, 0);
        if (n != 0)
        {
            if(_length > 0)
            {
                _last->setNext(n);
            }
            else
            {
                _first = n;
            }
            _last = n;
            _length ++;
        }
    }
    void preface(T value)
    {
        ListElement <T> * n = new ListElement<T>(value, 0, _first);
        if (n != 0)
        {
            if(_length > 0)
            {
                _first->setPrevious(n);
            }
            else
            {
                _last = n;
            }
            _first = n;
            _length ++; 
        }
    }
    void removeFirst() { _first = _first->getNext(); delete _first; _length --;}
    void removeLast() { _last = _last->getPrevious(); delete _last; _length --;}
    T getFirstValue(){ return _first->getValue(); }
    T getLastValue(){ return _last->getValue(); }
    void setFirstValue(T value){ _last->setValue(value); }
    void setLastValue(T value){ _last->setValue(value); }
    T popFirst(){T v = List::getFirstValue();List::removeFirst();return v;}
    T popLast(){T v = List::getLastValue();List::removeLast();return v;}

    ListElement <T> * get(int index)
    {
        ListElement <T> * current = _first;
        for (int i = 0; i < index; ++i)
            current = current->getNext();
        return current;
    }

    T getValue(int index)
    {
        if(index == 0)
            return List::getFirstValue();
        else if (index >= _length-1)
            return List::getLastValue();
        else
            return List::get(index)->getValue();
    }
    void setValue(int index, T value)
    {
        if(index == 0)
            List::setFirstValue(value);
        else if (index >= _length-1)
            List::setLastValue(value);
        else
            List::get(index)->setValue(value);
    }
    void insertValue(int index, T value)
    {
        if(index == 0)
            List::preface(value);
        else if (index >= _length-1)
            List::append(value);
        else
        {
            ListElement <T> * c = List::get(index);
            ListElement <T> * n = new ListElement<T>(value, c->getPrevious(), c);
            if (n)
            {
                c->getPrevious()->setNext(n);
                c->setPrevious(n);
                _length ++;
            }
        }
    }
    void removeValue(int index)
    {
        if(index == 0)
            List::removeFirst();
        else if (index >= _length-1)
            List::removeLast();
        else
        {
            ListElement <T> * c = List::get(index);
            c->getPrevious()->setNext(c->getNext());
            c->getNext()->setPrevious(c->getPrevious());
            _length --;
            delete c;
        }
    }
    T pop(int index)
    {
        if(index == 0)
            return List::popFirst();
        else if (index >= _length-1)
            return List::popLast();
        else
        {
            ListElement <T> * c = List::get(index);
            T v = c->getValue();
            c->getPrevious()->setNext(c->getNext());
            c->getNext()->setPrevious(c->getPrevious());
            delete c;
            _length --;
            return v;
        }
    }
    int getLength(){return _length;}

private:
    ListElement <T> * _first;
    ListElement <T> * _last;
    int _length;    
};


#endif