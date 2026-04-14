#include <iostream>
using namespace std;

// 链栈结点
struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

class LinkStack {
private:
    Node *top;
public:
    LinkStack() : top(nullptr) {}

    // 入栈
    void push(int x) {
        Node *p = new Node(x);
        p->next = top;
        top = p;
    }

    // 遍历（栈顶→栈底）
    void show() {
        Node *p = top;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    // 删除栈顶第 k 个元素
    bool deleteKth(int k) {
        if (top == nullptr || k < 1) return false;

        Node *p = top;
        Node *pre = nullptr;

        // 走到第 k 个结点
        for (int i = 1; i < k; ++i) {
            pre = p;
            p = p->next;
            if (p == nullptr) return false;
        }

        // 删除
        if (pre == nullptr) {
            top = top->next;
        } else {
            pre->next = p->next;
        }
        delete p;
        return true;
    }
};

int main() {
    LinkStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "删除前：";
    st.show();   // 5 4 3 2 1

    st.deleteKth(3);

    cout << "删除第3个后：";
    st.show();   // 5 4 2 1

    return 0;
}
