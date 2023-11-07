#include <stdio.h>
#include "cherish.h"

int main() {
    PriorityQueue pq;
    initializePriorityQueue(&pq);

    int choice, data, priority;

    do {
        printf("\n优先级队列操作菜单:\n");
        printf("1. 入队\n");
        printf("2. 出队\n");
        printf("3. 显示队列\n");
        printf("4. 退出\n");
        printf("请输入您的选择: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            if (isPriorityQueueFull(&pq)) {
                printf("优先级队列已满，无法入队。\n");
            }
            else {
                printf("请输入要入队的值: ");
                scanf_s("%d", &data);
                printf("请输入值的优先级: ");
                scanf_s("%d", &priority);
                enqueueWithPriority(&pq, data, priority);
                printf("%d 入队成功。\n", data);
            }
            break;

        case 2:
            if (isPriorityQueueEmpty(&pq)) {
                printf("优先级队列为空，无法出队。\n");
            }
            else {
                PriorityQueueElement element = dequeue(&pq);
                printf("出队的元素是：%d（优先级：%d）\n", element.data, element.priority);
            }
            break;

        case 3:
            displayPriorityQueue(&pq);
            break;

        case 4:
            printf("退出程序。\n");
            break;

        default:
            printf("无效选项，请重试。\n");
        }
    } while (choice != 4);

    return 0;
}
