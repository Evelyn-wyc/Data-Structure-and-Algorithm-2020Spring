#include <stdio.h>

// 本题提交时请选择G++************************


// 单链表节点
struct ListNode {
    int val;
    ListNode *next;
    // 构造函数，在new时调用
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

int n, k, target;

void print_list(ListNode *);

int main() {
    int i;
    // 建立一个虚拟节点作为链表头
    ListNode *dummy = new ListNode(-10000000);
    ListNode *p = dummy, *q;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &k);
        // 建立新节点
        p -> next = new ListNode(k);
        p = p -> next;
    }

    // 打印链表的所有元素
    //print_list(dummy->next);

    // 读入要删除的数
    scanf("%d", &target);
    p = dummy;
    while (p && p -> next) {
        q = p -> next;
        if (q -> val == target) {
            // 删除q
            //fill up line here********************

            delete q;
        } else
			//fill up line here********************
    }

    // 打印链表的所有元素
    print_list(dummy->next);
}

void print_list(ListNode * p) {
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}
