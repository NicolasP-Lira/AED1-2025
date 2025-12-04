#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

int main() {
    int n, cmd, x;
    while (scanf("%d", &n) == 1) {
        int stack[MAX_N], queue[MAX_N], pq[MAX_N];
        int stack_size = 0, queue_head = 0, queue_tail = 0, pq_size = 0;
        int is_stack = 1, is_queue = 1, is_pq = 1;

        while (n--) {
            scanf("%d", &cmd);
            if (cmd == 1) {
                scanf("%d", &x);
                stack[stack_size++] = x;
                queue[queue_tail++] = x;
                pq[pq_size++] = x;
            } else {
                scanf("%d", &x);
                if (is_stack) {
                    if (stack_size == 0 || stack[--stack_size] != x) {
                        is_stack = 0;
                    }
                }
                if (is_queue) {
                    if (queue_head == queue_tail || queue[queue_head++] != x) {
                        is_queue = 0;
                    }
                }
                if (is_pq) {
                    int max_index = -1, max_value = -1;
                    for (int i = 0; i < pq_size; i++) {
                        if (pq[i] > max_value) {
                            max_value = pq[i];
                            max_index = i;
                        }
                    }
                    if (max_index == -1 || pq[max_index] != x) {
                        is_pq = 0;
                    } else {
                        pq[max_index] = pq[--pq_size];
                    }
                }
            }
        }

        if (is_stack && !is_queue && !is_pq) {
            printf("stack\n");
        } else if (!is_stack && is_queue && !is_pq) {
            printf("queue\n");
        } else if (!is_stack && !is_queue && is_pq) {
            printf("priority queue\n");
        } else if (!is_stack && !is_queue && !is_pq) {
            printf("impossible\n");
        } else {
            printf("not sure\n");
        }
    }
    return 0;
}
