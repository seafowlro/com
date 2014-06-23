
/*  
*       author:  mark
*         date:  2014/06/21
* Illustration:  It's the data structure and not so many common parts, so I did not use the base class.
*                No base class;
*/

#pragma once
#include <iostream>


//this is just the test node;
struct node 
{
    int data;
    struct node * next;
};

//this class has the "HEAD" node;
class CSingleLinkedList
{
public:
    CSingleLinkedList();
    explicit CSingleLinkedList( size_t num );
    ~CSingleLinkedList();

    friend std::ostream & operator<<(std::ostream & os, const CSingleLinkedList & cur);   //output the linked list;
    int reverse();
    int test();

private:
    node * m_phead;      //point to the first node;
    node * m_pend;       //point to the last node;

private:
    void CreateHeadNode( )
    {
        m_phead = new node();
        m_pend = m_phead;
    }
    
};

