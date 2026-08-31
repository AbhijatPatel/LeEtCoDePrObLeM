 class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };
    class LRUCache {
    public:
    int capacity;
    Node* head;
    Node* tail;

    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node) {

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    int get(int key) {

        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        removeNode(node);
        addNode(node);

        return node->value;
    }
    
    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            removeNode(node);
            addNode(node);

            return;
        }

        if (mp.size() == capacity) {

            Node* lru = tail->prev;

            mp.erase(lru->key);

            removeNode(lru);

            delete lru;
        }

        Node* node = new Node(key, value);

        addNode(node);

        mp[key] = node;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */