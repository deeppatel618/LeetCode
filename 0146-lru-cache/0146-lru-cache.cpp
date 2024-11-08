struct Node{
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int kValue, int value): key(kValue),val(value),next(nullptr),prev(nullptr){}
};
class LRUCache {
public:
    unordered_map<int,Node*> dict;
    int capacity=0;
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
        
    }
    void add(Node *node)
    {
        Node *prev = tail->prev;
        prev->next = node;
        node->prev = prev;
        node->next = tail;
        tail->prev = node;
    }
    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    int get(int key) {
        if(dict.find(key) == dict.end())
            return -1;
        
        Node *node = dict[key];
        remove(node);
        add(node);
        return node->val;
    }
    void put(int key, int value) {
        if(dict.find(key) != dict.end())
        {
            Node *oldNode = dict[key];
            remove(oldNode);
        }
        Node *newNode = new Node(key,value);
        dict[key] = newNode;
        add(newNode);
        if(dict.size()>capacity)
        {
            Node *nodeToBeremoved = head->next;
            remove(nodeToBeremoved);
            dict.erase(nodeToBeremoved->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */