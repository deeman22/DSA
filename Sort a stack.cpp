/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insert( stack<int> &st, int a){
    if(st.empty() || st.top() <= a){
        st.push(a);
        return;
    }
    else {
        int b = st.top(); st.pop();
        insert(st, a);
        st.push(b);
    }
    
    
}
void recursiveSort(stack<int> &st){
    
    if(st.empty()) return ;
    
    int a = st.top(); st.pop();
    
    recursiveSort(st);
    insert(st, a);
    
    
}

void SortedStack :: sort()
{
   //Your code here
   recursiveSort(s);
}
