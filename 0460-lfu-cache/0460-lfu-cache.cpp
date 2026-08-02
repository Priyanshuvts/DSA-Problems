class Node {
public:
    int key, val, freq;
    Node *prev, *next;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->freq = 1;
        prev = next = nullptr;
    }
};

class List {
public:
    int size;
    Node *head, *tail;

    List() {
        size = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
};

class LFUCache {
    int capacity;
    int minFreq;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;

    void updateFreq(Node *node) {
        int freq = node->freq;

        freqList[freq]->removeNode(node);

        if (freq == minFreq && freqList[freq]->size == 0)
            minFreq++;

        node->freq++;

        if (freqList.find(node->freq) == freqList.end())
            freqList[node->freq] = new List();

        freqList[node->freq]->addFront(node);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end())
            return -1;

        Node *node = keyNode[key];
        updateFreq(node);

        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {
            Node *node = keyNode[key];
            node->val = value;
            updateFreq(node);
            return;
        }

        if (keyNode.size() == capacity) {
            List *list = freqList[minFreq];
            Node *node = list->tail->prev;
            list->removeNode(node);
            keyNode.erase(node->key);
            delete node;
        }

        Node *node = new Node(key, value);

        minFreq = 1;

        if (freqList.find(1) == freqList.end())
            freqList[1] = new List();

        freqList[1]->addFront(node);
        keyNode[key] = node;
    }
};