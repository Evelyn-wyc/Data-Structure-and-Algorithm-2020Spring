#include <stdio.h>

// �����ύʱ��ѡ��G++************************


// ������ڵ�
struct ListNode {
    int val;
    ListNode *next;
    // ���캯������newʱ����
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

int n, k, target;

void print_list(ListNode *);

int main() {
    int i;
    // ����һ������ڵ���Ϊ����ͷ
    ListNode *dummy = new ListNode(-10000000);
    ListNode *p = dummy, *q;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &k);
        // �����½ڵ�
        p -> next = new ListNode(k);
        p = p -> next;
    }

    // ��ӡ���������Ԫ��
    //print_list(dummy->next);

    // ����Ҫɾ������
    scanf("%d", &target);
    p = dummy;
    while (p && p -> next) {
        q = p -> next;
        if (q -> val == target) {
            // ɾ��q
            //fill up line here********************

            delete q;
        } else
			//fill up line here********************
    }

    // ��ӡ���������Ԫ��
    print_list(dummy->next);
}

void print_list(ListNode * p) {
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}
