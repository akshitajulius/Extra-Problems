class DoublyLinkedList {
public:
    string val;
    DoublyLinkedList* next;
    DoublyLinkedList* prev;

    DoublyLinkedList(string val, DoublyLinkedList* next = nullptr,
                        DoublyLinkedList* prev = nullptr) {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        DoublyLinkedList* head = new DoublyLinkedList(tokens[0]);
        DoublyLinkedList* curr = head;

        for (int i = 1; i < tokens.size(); i++) {
            curr->next = new DoublyLinkedList(tokens[i], nullptr, curr);
            curr = curr->next;
        }

        int ans = 0;
        while (head != nullptr) {
            if (head->val == "+" ||
                 head->val == "-" ||
                 head->val == "*" ||
                 head->val == "/")
            {
                int l = stoi(head->prev->prev->val);
                int r = stoi(head->prev->val);
                int res = 0;
                if (head->val == "+") {
                    res = l + r;
                } else if (head->val == "-") {
                    res = l - r;
                } else if (head->val == "*") {
                    res = l * r;
                } else {
                    res = l / r;
                }

                head->val = to_string(res);
                head->prev = head->prev->prev->prev;
                if (head->prev != nullptr) {
                    head->prev->next = head;
                }
            }

            ans = stoi(head->val);
            head = head->next;
        }

        return ans;
    }
};
