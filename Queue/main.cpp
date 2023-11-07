#include <stdio.h>
#include "cherish.h"

int main() {
    PriorityQueue pq;
    initializePriorityQueue(&pq);

    int choice, data, priority;

    do {
        printf("\n���ȼ����в����˵�:\n");
        printf("1. ���\n");
        printf("2. ����\n");
        printf("3. ��ʾ����\n");
        printf("4. �˳�\n");
        printf("����������ѡ��: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            if (isPriorityQueueFull(&pq)) {
                printf("���ȼ������������޷���ӡ�\n");
            }
            else {
                printf("������Ҫ��ӵ�ֵ: ");
                scanf_s("%d", &data);
                printf("������ֵ�����ȼ�: ");
                scanf_s("%d", &priority);
                enqueueWithPriority(&pq, data, priority);
                printf("%d ��ӳɹ���\n", data);
            }
            break;

        case 2:
            if (isPriorityQueueEmpty(&pq)) {
                printf("���ȼ�����Ϊ�գ��޷����ӡ�\n");
            }
            else {
                PriorityQueueElement element = dequeue(&pq);
                printf("���ӵ�Ԫ���ǣ�%d�����ȼ���%d��\n", element.data, element.priority);
            }
            break;

        case 3:
            displayPriorityQueue(&pq);
            break;

        case 4:
            printf("�˳�����\n");
            break;

        default:
            printf("��Чѡ������ԡ�\n");
        }
    } while (choice != 4);

    return 0;
}
