class Node {
public:
    string data;
    Node* next;
    Node* back;

    Node(string x) {
        data = x;
        next = NULL;
        back = NULL;
    }
};

class BrowserHistory {
public:
    Node* currentPage;

    BrowserHistory(string homepage) {
        currentPage = new Node(homepage);
    }

    void visit(string url) {
        Node* newNode = new Node(url);

        currentPage->next = newNode;
        newNode->back = currentPage;

        currentPage = newNode;
    }

    string back(int steps) {
        while (steps > 0 && currentPage->back != NULL) {
            currentPage = currentPage->back;
            steps--;
        }

        return currentPage->data;
    }

    string forward(int steps) {
        while (steps > 0 && currentPage->next != NULL) {
            currentPage = currentPage->next;
            steps--;
        }

        return currentPage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */