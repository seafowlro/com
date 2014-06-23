/*
*       author:  mark
*         date:  2014/06/21
* Illustration:  the implementation file;
*/

#include "stdafx.h"
#include "SingleLinkedList.h"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


CSingleLinkedList::CSingleLinkedList()
:m_phead(nullptr), m_pend(nullptr)
{
    CreateHeadNode();
}

CSingleLinkedList::CSingleLinkedList( size_t num )
:m_phead(nullptr), m_pend(nullptr)
{
    CreateHeadNode();

    srand( static_cast<unsigned int>(time(NULL)) );
    node * temp = nullptr;
    for ( size_t i = 0; i < num; ++ i )
    {
        temp       = new node();
        temp->data = rand();
        temp->next = nullptr;
        
        m_pend->next = temp;
        m_pend       = temp;
        ++m_phead->data;
    }
}

ostream & operator<<(ostream & os, const CSingleLinkedList & cur)
{
    string label = cur.m_phead->data > 1 ? " nodes:" : " node:";
    os << "this list has " << cur.m_phead->data << label << endl;
    node * temp = cur.m_phead->next;

    int count = 0;
    while ( temp )
    {
        os << temp->data << "-->";
        temp = temp->next;
        ++count;
        if ( 8 == count )
        {
            os << endl;
            count = 0;
        }
    }

    return os;
}


CSingleLinkedList::~CSingleLinkedList()
{
    node *cur = m_phead, * nextNode = m_phead->next;

    while ( nextNode )
    {
        delete cur;
        cur = nextNode;
        nextNode = nextNode->next;
    }

    delete cur;   //here, the "cur" point to the last node;
}


int CSingleLinkedList::reverse()
{
    //<2 node;
    if ( nullptr == m_phead->next || nullptr == m_phead->next->next)
    {
        return -1;
    }

    m_pend = m_phead->next;
    //at first, the "cur" point to the first node, "nextNode" point to the next node after "cur";
    node * pre = nullptr, *cur = m_phead->next, *nextNode = cur->next, * temp = nullptr;
    while (nextNode->next != nullptr)
    {
        cur->next      = pre;
        temp = nextNode->next;
        nextNode->next = cur;
        pre = cur;
        cur = nextNode;
        nextNode = temp;
    }

    //when the "while" end, the "nextNode" point to the last node;
    nextNode->next = cur;
    cur->next      = pre;
    m_phead->next  = nextNode;

    return 0;
}


int CSingleLinkedList::test()
{
    CSingleLinkedList T(130);
    cout << T << endl;
    T.reverse();
    cout << endl << "after reverse: " << endl;
    cout << T << endl;

    return 0;
}
