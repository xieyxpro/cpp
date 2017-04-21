�ж����� 
bool isprime(int m) {
	int i;
	if (m == 1) return false;
	if (m == 2) return true;
	for (i = 2; i*i <= m; i++) {
		if (m%i == 0) return false;
	}
	return true;
}

�ڼ�������
#include<stdio.h>
int main(void) {
    int n, i, j, k = 0;
    scanf("%d", &n);
    for (i = 2; ; i++) {
    	for (j = 2; j*j <= i; j++) {
    		if (i%j == 0) {
    			break;
    		}
    	}
    	if (j*j <= i) {
    		continue;
    	} else {
    		k++;
    	}
    	if (k == n) {
    		printf("%d\n", i);
    		break;
    	}
    }
	return 0;
} 
ѡ������ 
void selsort(int num[], int M) {
	int i, j, m, k;
	for (i = 0; i < M-1; i++) {
		m = i;
		for (j = i+1; j < M; j++) {
			if (num[j] < num[i]) m = j;
		}
		if (i != m) {
			swap(num[i], num[m]);
		}
	}
}
ð������ 
void bubsort(int num[], int M) {
	for (i = 0; i < M-1; i++) {
		for (j = 0; j < n-1-i; j++) {
			if (num[j] > num[j+1]) swap(num[j], num[j+1]);
		}
	}
}
��������
void exchange(int num[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (num[i] > num[j]) swap(num[i], num[j]);
		}
	}
}

��������
void qsort(int n[], int low, int high) {
	if (low >= high) return;
	int first = low, last = high, key = n[first];
	while (first < last) {
		while (n[last--] < key);
		n[first] = n[last];
		while (n[first--] > key);
		n[last] = n[first];
	}
	n[first] = key;
	qsort(n, low, first-1);
	qsort(n, first+1, high);
}

��ͷ��ǩ�㷨
void bihead(int A[], int M[][], int a, int b) {
	for (int i = 0;i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (M[i][j]) swap(A[j], A[j+1]);
		}
	}
}

ħ�������㷨
void square(int **A, int n) {
	int p, q, k;
	p = 0, q = n/2;
	A[p][q] = 1;
	for (k = 2; k <= n*n; k++) {
		p = (p-1+n)%n;
		q = (q-1+n)%n;
		if (A[p][q]) {
			p = (p-1+n)%n;
			A[p][q] = k;
		} else {
			A[p][q] = k;
		}
	}
}

�ߴη���ģ(m�Ǻܴ��һ������)
�ݹ�
int powmod(int n, int p) {
	if (p == 1) return n%m;
	if (p%2 == 0) return powmod(n, p/2)*powmod(n, p/2);
	else return powmod(n, p/2)*powmod(n, p/2)*(n%p);
}
�ǵݹ� 
int powmod(int n, int p) {
	int ans = 1;
	while (p > 0) {
		if (p%2 == 1) {
			ans = (ans*n)%m;
		}
		p /= 2;
		n = (n*n)%m;
	}
	return ans;
}

�����㷨��

���ֲ���
int binarysearch(int A[], int key, int len) {
	int low = 0, upper = len-1, mid;
	while (low <= upper) {
		mid = (low+upper)/2;
		if (key == A[mid]) return mid;
		else if (key < A[mid]) upper = mid-1;
		else low = mid+1;
	}
	return -1;
}

int insertsearch(int A[], int key, int len) {
	int low = 0, upper = len-1, mid;
	while (low <= upper) {
		mid = low+(key-A[low])*(upper-low)/(A[upper]-A[low]);
		if (mid < low) mid = low;
		if (mid > upper) mid = upper;
		if (key == A[mid]) return mid;
		else if (key < A[mid]) upper = mid-1;
		else low = mid+1;
	}
	return -1;
}
������ʵ��ջ�� 
���ݽṹ����
typedef int elemtype;
typedef struct stack_tag {
         elemtype *elem; //ָ��������Ԫ�ص��ڴ��
         int top; //ջ����ʶ��elem[top]��ջ��Ԫ��
         int size; //ջ������
		 }SQSTACK;

��ʼ��ջ
int InitSqstack(SQSTACK *S, int n)
{                                             //��ʼ��˳��ջ��ջ��������n���ɹ��򷵻�1�����򷵻�0
    S->elem=(elemtype *)malloc(n*sizeof(elemtype));  //Ϊ����Ԫ�ط����ڴ�
    if (S->elem==NULL) return 0;                                //��ʼ��ʧ��
    S->size=n;                                                //����ջ������
    S->top= -1;                                              //����ջΪ��ջ
    return 1;
 } 
 
 ����ջ
 void DestroySqstack(SQSTACK *S)
{                                                           //�ͷ�ջ��ռ�е��ڴ�
    free(S->elem);                                 //�ͷ��ڴ棬������ΪNULL
    S->elem=NULL;
    S->top= -1;                                      //��������Ա���óɰ�ȫֵ
    S->size=0;
} 

��ջ
int Push(SQSTACK *S, elemtype e)
{                      //��ջ��һ�˲�������Ԫ��e�������ɹ����򷵻�1�����򷵻�0
    if (IsSqstackFull(*S)) return 0;        //ջ��������ʧ��
    S->top++;                                          //top��1
    S->elem[S->top] = e;                          //��e��ֵ���µ�ջ��
    return 1;
}

��ջ
int Pop(SQSTACK *S, elemtype *e)
{            //��ȡջ������Ԫ�أ���ɾ��ջ���������ɹ����򷵻�1�����򷵻�0
    if (IsSqstackEmpty(*S)) return 0;     //���ջ�գ�����ʧ��
    *e = S->elem[S->top];                          //��ȡջ��Ԫ��
    S->top--;                                             //ɾ��ջ��
    return 1;
} 

�ж�ջ�ա�ջ��
int IsSqstackEmpty(SQSTACK  S)
{   //���ջ�գ��򷵻�1�����򷵻�0
    return S.top==-1;   //top��ջ����ʶ����-1ʱ��ʾ��ջ
}
int IsSqstackFull(SQSTACK  S)
{   //���ջ�����򷵻�1�����򷵻�0
    return S.top==S.size-1; //top��Ϊelem���±꣬�����ֵ��size-1 
}


������ʵ��ջ:
���ݽṹ����
typedef int elemtype;
typedef struct node {
	elemtype elem;
	struct node *link;
	}

struct node* push( struct node* top, int obj) {
	if (top == NULL) {
		top = (struct node*)malloc(sizeof(struct node));
		top->elem = obj;
		top->link = NULL;
	} else {
		struct node *temp;
		temp = (struct node*)malloc(sizeof(struct node));
		temp->elem = obj;
		temp->link = top;
		top = temp;
	}
}

struct node* pop(struct node* top) {
	if (top == NULL) {
		return top;
	} else {
		struct node* temp;
		temp = top;
		top = top->link;
		free(temp);
		return top;
	}
}

void get_top(struct node* top, elemtype* a) {
	if (top == NULL) {
		return;
	} else {
		*a = top->elem;
	}
}

struct node* destroy(struct node* top){
	struct node* temp;
	while (top != NULL) {
		temp = top;
		top = top->link;
		free(temp);
	}
	return top;
}

������ʵ�ֶ���
typedef int elemtype;
typedef struct squeue {
	elemtype *elem;
	int front, rear;
	int size;
};

int InitSqqueue(squeue *q,int n) {
	q->elem = (elemtype*)malloc((n+1)*sizeof(elemtype));
	q->front = q->rear = 0;
	q->size = n+1;
}

void Destroysqueue(squeue *q) {
	free(q->elem);
	q->elem = NULL;
	q->front = q->rear = 0;
	q->size = 0;
}

int issqueueempty(squeue *q) {
	return q->front == q->rear;
}

int issqueuefull(squeue *q) {
	return q->front == (q->rear+1)%q->size;
}

void ensqueue(squeue *q, elemtype e) {
	if (issqueuefull(q)) return;
	q->elem[q->rear] = e;
	q->rear = (q->rear+1)%q->size;
}

void desqueue(squeue *q, elemtype *e) {
	if (issqueueempty(q)) return;
	*e = q->elem[q->front];
	q->front = (q->front+1)%q->size;
}

��ʽ����
typedef int elemtype;
typedef struct NODE {
	elemtype elem;
	struct NODE* next;
}node, *nodeptr;
typedef struct {
	nodeptr front, rear;
}lkqueue;

void initlkqueue(lkqueue *q) {
	q->front = q->rear = NULL;
}

void destorylkqueue(lkqueue *q) {
	nodeptr temp;
	while (q->front != NULL) {
		temp = q->front;
		q->front = q->front->next;
		free(temp);
	}
	q->rear = NULL;
}

void initlkqueue(squeue *q, eletype e) {
	nodeptr p;
	p = (nodeptr)malloc(sizeof(node));
	p->elem = e;
	p->next = NULL;
	if (q->front == NULL) {
		q->front = q->rear = p;
	} else {
		q->rear->next = p;
		q->rear = p;
	}
}

void delkqueue(squeue *q, elemtype *e) {
	if (q->front == NULL) return;
	nodeptr p;
	p = q->front;
	*e = q->front->elem;
	q->front = q->front->next;
	if (q->front == NULL) q->rear = NULL;
	free(p);
}

ŷ�Ｘ�÷������Լ��
�ݹ� 
int gcd(int a, int b) {
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (b == 0) return a;
	if (a%b == 0) return b;
	else return gcd(b, a%b);
}
�ǵݹ�
int gcd(int a, int b) {
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (b == 0) return a;
	while (b > 0) {
		int tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
} 

����չ��

�濵��չ�� 

