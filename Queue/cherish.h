#define MAX_PRIORITY_QUEUE_SIZE 100 // 定义优先级队列的最大容量

// 定义队列元素结构
typedef struct {
    int data;
    int priority;
} PriorityQueueElement;

// 定义优先级队列的数据结构
typedef struct {
    PriorityQueueElement data[MAX_PRIORITY_QUEUE_SIZE];
    int size;
} PriorityQueue;

// 函数原型
void initializePriorityQueue(PriorityQueue* pq);
int isPriorityQueueFull(PriorityQueue* pq);
int isPriorityQueueEmpty(PriorityQueue* pq);
void enqueueWithPriority(PriorityQueue* pq, int data, int priority);
PriorityQueueElement dequeue(PriorityQueue* pq);
void displayPriorityQueue(PriorityQueue* pq);




// 初始化优先级队列
void initializePriorityQueue(PriorityQueue* pq) {
    pq->size = 0;
}

// 检查优先级队列是否已满
int isPriorityQueueFull(PriorityQueue* pq) {
    return (pq->size == MAX_PRIORITY_QUEUE_SIZE);
}

// 检查优先级队列是否为空
int isPriorityQueueEmpty(PriorityQueue* pq) {
    return (pq->size == 0);
}

// 入队，带有优先级
void enqueueWithPriority(PriorityQueue* pq, int data, int priority) {
    if (isPriorityQueueFull(pq)) {
        printf("优先级队列已满，无法入队。\n");
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

// 出队，返回队列中的具有最高优先级的元素
PriorityQueueElement dequeue(PriorityQueue* pq) {
    PriorityQueueElement element;
    if (isPriorityQueueEmpty(pq)) {
        printf("优先级队列为空，无法出队。\n");
        element.data = -1; // 表示队列为空
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

// 显示优先级队列中的元素
void displayPriorityQueue(PriorityQueue* pq) {
    if (isPriorityQueueEmpty(pq)) {
        printf("优先级队列为空。\n");
    }
    else {
        printf("优先级队列元素:\n");
        for (int i = 0; i < pq->size; i++) {
            printf("数据：%d  优先级：%d\n", pq->data[i].data, pq->data[i].priority);
        }
    }
}
