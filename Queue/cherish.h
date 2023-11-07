#define MAX_PRIORITY_QUEUE_SIZE 100 // �������ȼ����е��������

// �������Ԫ�ؽṹ
typedef struct {
    int data;
    int priority;
} PriorityQueueElement;

// �������ȼ����е����ݽṹ
typedef struct {
    PriorityQueueElement data[MAX_PRIORITY_QUEUE_SIZE];
    int size;
} PriorityQueue;

// ����ԭ��
void initializePriorityQueue(PriorityQueue* pq);
int isPriorityQueueFull(PriorityQueue* pq);
int isPriorityQueueEmpty(PriorityQueue* pq);
void enqueueWithPriority(PriorityQueue* pq, int data, int priority);
PriorityQueueElement dequeue(PriorityQueue* pq);
void displayPriorityQueue(PriorityQueue* pq);




// ��ʼ�����ȼ�����
void initializePriorityQueue(PriorityQueue* pq) {
    pq->size = 0;
}

// ������ȼ������Ƿ�����
int isPriorityQueueFull(PriorityQueue* pq) {
    return (pq->size == MAX_PRIORITY_QUEUE_SIZE);
}

// ������ȼ������Ƿ�Ϊ��
int isPriorityQueueEmpty(PriorityQueue* pq) {
    return (pq->size == 0);
}

// ��ӣ��������ȼ�
void enqueueWithPriority(PriorityQueue* pq, int data, int priority) {
    if (isPriorityQueueFull(pq)) {
        printf("���ȼ������������޷���ӡ�\n");
        return;
    }

    int i = pq->size;
    while (i > 0 && pq->data[i - 1].priority > priority) {
        pq->data[i] = pq->data[i - 1];
        i--;
    }

    pq->data[i].data = data;
    pq->data[i].priority = priority;
    pq->size++;
}

// ���ӣ����ض����еľ���������ȼ���Ԫ��
PriorityQueueElement dequeue(PriorityQueue* pq) {
    PriorityQueueElement element;
    if (isPriorityQueueEmpty(pq)) {
        printf("���ȼ�����Ϊ�գ��޷����ӡ�\n");
        element.data = -1; // ��ʾ����Ϊ��
        element.priority = -1;
    }
    else {
        element = pq->data[0];
        for (int i = 1; i < pq->size; i++) {
            pq->data[i - 1] = pq->data[i];
        }
        pq->size--;
    }
    return element;
}

// ��ʾ���ȼ������е�Ԫ��
void displayPriorityQueue(PriorityQueue* pq) {
    if (isPriorityQueueEmpty(pq)) {
        printf("���ȼ�����Ϊ�ա�\n");
    }
    else {
        printf("���ȼ�����Ԫ��:\n");
        for (int i = 0; i < pq->size; i++) {
            printf("���ݣ�%d  ���ȼ���%d\n", pq->data[i].data, pq->data[i].priority);
        }
    }
}
