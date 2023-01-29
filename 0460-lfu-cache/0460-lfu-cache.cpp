struct Node {
    int key, val, freq;
    Node *prev, *next;
    Node() : prev(nullptr), next(nullptr){};
};

struct List {
    int size;
    Node *head, *tail;
    
    List() : size(0), head(new Node()), tail(new Node()) {
        head->next = tail;
        tail->prev = head;
    }
    
	~List() {
		Node *curr = head;
		while (curr != nullptr) {
			Node *next = curr->next;
			delete curr;
			curr = next;
		}
	}
    
    void add(Node *node) {
        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        node->prev->next = node;
        ++size;
    }
    
    void remove(Node *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->next = nullptr;
        node->prev = nullptr;
        --size;
    }
    
    Node *last() {
        Node *node = tail->prev;
        remove(node);
        return node;
    }
};

class LFUCache {
public:
    LFUCache(int capacity) : Cap(capacity), Mfreq(0) {
    }
    
    ~LFUCache() {
        for (pair<int, List*> p: Lists) {
            delete p.second;
        }
    }
    
    int get(int key) {
        if(Nodes.count(key) == 1) {
            promote(key);
            return Nodes[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (!Cap) return;
        
        if (Nodes.count(key) == 1) {
            promote(key); // Done
            Nodes[key]->val = value;
        } 
        else {
            if (Nodes.size() == Cap) {
                evict(); // Done
            }
            insert(key, value); // Done
        }
    }
    
private:
    int Cap, Mfreq;
    unordered_map<int, List*> Lists;
    unordered_map<int, Node*> Nodes; 
    
    void insert(int key, int value) {
        Mfreq = 1;
        Node *node = new Node();
        node->key = key;
        node->val = value;
        node->freq = Mfreq;
        Nodes[key] = node;
        addToList(Mfreq, node); // Done
    }
    
    void addToList(int freq, Node *node) {
        if (Lists.count(freq) == 0) {
            Lists[freq] = new List();
        }
        Lists[freq]->add(node);
    }
    
    void evict() {
        Node *node = Lists[Mfreq]->last();
        Nodes.erase(node->key);
        delete node;
        removeIfEmpty(Mfreq); // Done
    }
    
    void removeIfEmpty(int freq) {
        if (Lists[Mfreq]->size == 0) {
            List *del = Lists[Mfreq];
            delete del;
            Lists.erase(Mfreq);
            if (freq == Mfreq)
                ++Mfreq;
        }
    }
    
    void promote(int key) {
        Node *node = Nodes[key];
        int freq = node->freq++;
        Lists[freq]->remove(node);
        removeIfEmpty(freq);
        addToList(freq+1, node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */