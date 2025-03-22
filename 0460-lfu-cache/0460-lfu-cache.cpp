struct Node{
    int key;
    int value;
    int count;
    Node* next;
    Node* prev;
    Node(int _key,int _value):key(_key),value(_value){
        count = 1;
    }
};

struct List{
    int size;
    List* next;
    List* prev;
    Node* head;
    Node* tail;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    // Function to add a new node in the front of the list;
    void addFront(Node *node){
        Node *temp = head->next;
        
        node->next = temp;
        temp->prev = node;

        head->next = node;
        node->prev = head;
        size++;
    }
    // Function to remove any node;
    void remove(Node* delNode){
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        size--;
    }
};
class LFUCache {
public:
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqListMap;
    int maxCapacity;
    int minFrequency;
    int currentSize;
    LFUCache(int capacity) {
        maxCapacity = capacity;
        minFrequency = 0;
        currentSize = 0;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node *node = keyNode[key];
            updateFreqListMap(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxCapacity == 0) return;

        //If there exists a key
        if(keyNode.find(key) != keyNode.end()){
            Node *node = keyNode[key]; // Fetch that Node
            node->value = value; // Update the value;
            updateFreqListMap(node);
        }
        else{ // if the key is not present;

            // if number of elements are at max capacity
            if(currentSize == maxCapacity){
                List *list = freqListMap[minFrequency];
                Node *delNode = list->tail->prev;
                keyNode.erase(delNode->key);
                freqListMap[minFrequency]->remove(delNode);
                currentSize--;
            }
            currentSize++;

            //Add new value
            minFrequency = 1;
            List *listFreq = new List();
            if(freqListMap.find(minFrequency) != freqListMap.end()){
                listFreq = freqListMap[minFrequency];
            }
            Node *node = new Node(key,value);
            listFreq->addFront(node);
            keyNode[key]= node;
            freqListMap[minFrequency] = listFreq;
        }

    }

    void updateFreqListMap(Node *node){
        keyNode.erase(node->key);
        int count = node->count;
        freqListMap[count]->remove(node); //remove the current Node;

        //Check if it is the last element in the frequency list and the list is min freq list.
        if(count == minFrequency && freqListMap[count]->size == 0){ 
            minFrequency++;
        }

        List *newHigherFrequencyList = new List();
        // Fetch the higher Freq list
        if(freqListMap.find(count+1) != freqListMap.end()){
            newHigherFrequencyList = freqListMap[count+1];
        }

        //Increase the node count;
        node->count++;
        // Add new node to new higher freq list
        newHigherFrequencyList->addFront(node);
        freqListMap[node->count] = newHigherFrequencyList;
        keyNode[node->key] = node;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */