#include "LinkedList.cpp"

int main()
{
    LinkedList LL;
    LL.append(5);
    LL.append(33);
    LL.append(1);
    LL.append(7);
    LL.append(33);
    LL.append(12);
    LL.display(cout);
    LL.remove(33);
    LL.display(cout);
    LL.prepend(12);
    LL.display(cout);
    LL.remove(13);
    LL.display(cout);
    
    LL.~LinkedList();
    
}