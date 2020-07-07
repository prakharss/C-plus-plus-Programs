stack<int> elem;
stack<int> minElem;
 
MinStack::MinStack() {
    while(!elem.empty())
        elem.pop();
    
    while(!minElem.empty())
        minElem.pop();
}
/*
16
15
29
19
18

pop 2 elements
18 19 29 (min value: 18)

29
19
18
*/


void MinStack::push(int x) {
    if(elem.size()==0)
        minElem.push(x);
    else
    {
        if(x<=minElem.top())
            minElem.push(x);
    }
    
    elem.push(x);
}
 
void MinStack::pop() {
    if(elem.size()!=0)
    {
        if(elem.top()==minElem.top())
            minElem.pop();
        
        elem.pop();
    }
}
 
int MinStack::top() {
    if(elem.size()==0)
        return -1;
        
    return elem.top();
}
 
int MinStack::getMin() {
    if(elem.size()==0)
        return -1;
        
    return minElem.top();
}
