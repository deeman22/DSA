/*
Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:

SET x y : sets the value of the key x with value y
GET x : gets the key of x if present else returns -1.

The LRUCache class has two methods get() and set() which are defined as follows.

get(key)   : returns the value of the key if it already exists in the cache otherwise returns -1.
set(key, value) : if the key is already present, update its value. If not present, add the key-value pair to the cache. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.
In the constructor of the class the capacity of the cache should be intitialized.
 

Example 1:

Input:
cap = 2
Q = 2
Queries = SET 1 2 GET 1
Output: 2
Explanation: 
Cache Size = 2

SET 1 2 GET 1
SET 1 2 : 1 -> 2

GET 1 : Print the value corresponding
to Key 1, ie 2.
*/

class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    class Node {
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        
        Node(int newKey, int newVal){
            key = newKey;
            val = newVal;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;
    int capacity;
    
    void addNode(Node* curr){
        Node* temp = head->next;
        head->next = curr;
        temp->prev = curr;
        curr->prev = head;
        curr->next = temp;
    }
    
    void deleteNode(Node* curr){
        Node* temp = curr->prev;
        Node* temp2 = curr->next;
        temp->next = temp2;
        temp2->prev = temp;
    }
    LRUCache(int cap)
    {
        // code here
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(mp.find(key) != mp.end()){
            
            Node* curr = mp[key];
            int res = curr->val;
            // erase from mp
            mp.erase(key);
            //delete
            deleteNode(curr);
            // insert at front
            addNode(curr);
            
            mp[key] = head->next;
            return res;
        }
        else return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here
        if(mp.find(key) != mp.end()){
            
            Node* curr = mp[key];
            // erase from mp
            mp.erase(key);
            //delete
            deleteNode(curr);
        }
        else if( mp.size() == capacity){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mp[key] = head->next;
        
    }
};
