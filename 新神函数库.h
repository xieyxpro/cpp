判断素数 
bool isprime(int m) {
	int i;
	if (m == 1) return false;
	if (m == 2) return true;
	for (i = 2; i*i <= m; i++) {
		if (m%i == 0) return false;
	}
	return true;
}

第几个素数
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
选择排序 
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
冒泡排序 
void bubsort(int num[], int M) {
	for (i = 0; i < M-1; i++) {
		for (j = 0; j < n-1-i; j++) {
			if (num[j] > num[j+1]) swap(num[j], num[j+1]);
		}
	}
}
交换排序
void exchange(int num[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (num[i] > num[j]) swap(num[i], num[j]);
		}
	}
}

快速排序
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

大头抽签算法
void bihead(int A[], int M[][], int a, int b) {
	for (int i = 0;i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (M[i][j]) swap(A[j], A[j+1]);
		}
	}
}

魔术方块算法
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

高次方求模(m是很大的一个整数)
递归
int powmod(int n, int p) {
	if (p == 1) return n%m;
	if (p%2 == 0) return powmod(n, p/2)*powmod(n, p/2);
	else return powmod(n, p/2)*powmod(n, p/2)*(n%p);
}
非递归 
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

查找算法：

二分查找
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
用数组实现栈： 
数据结构定义
typedef int elemtype;
typedef struct stack_tag {
         elemtype *elem; //指向存放数据元素的内存块
         int top; //栈顶标识，elem[top]是栈顶元素
         int size; //栈的容量
		 }SQSTACK;

初始化栈
int InitSqstack(SQSTACK *S, int n)
{                                             //初始化顺序栈，栈的容量是n。成功则返回1，否则返回0
    S->elem=(elemtype *)malloc(n*sizeof(elemtype));  //为数据元素分配内存
    if (S->elem==NULL) return 0;                                //初始化失败
    S->size=n;                                                //设置栈的容量
    S->top= -1;                                              //设置栈为空栈
    return 1;
 } 
 
 销毁栈
 void DestroySqstack(SQSTACK *S)
{                                                           //释放栈所占有的内存
    free(S->elem);                                 //释放内存，并设置为NULL
    S->elem=NULL;
    S->top= -1;                                      //将其他成员设置成安全值
    S->size=0;
} 

入栈
int Push(SQSTACK *S, elemtype e)
{                      //在栈顶一端插入数据元素e，操作成功，则返回1，否则返回0
    if (IsSqstackFull(*S)) return 0;        //栈满，操作失败
    S->top++;                                          //top增1
    S->elem[S->top] = e;                          //将e赋值成新的栈顶
    return 1;
}

出栈
int Pop(SQSTACK *S, elemtype *e)
{            //获取栈顶数据元素，并删除栈顶。操作成功，则返回1，否则返回0
    if (IsSqstackEmpty(*S)) return 0;     //如果栈空，操作失败
    *e = S->elem[S->top];                          //获取栈顶元素
    S->top--;                                             //删除栈顶
    return 1;
} 

判断栈空、栈满
int IsSqstackEmpty(SQSTACK  S)
{   //如果栈空，则返回1，否则返回0
    return S.top==-1;   //top是栈顶标识，是-1时表示空栈
}
int IsSqstackFull(SQSTACK  S)
{   //如果栈满，则返回1，否则返回0
    return S.top==S.size-1; //top作为elem的下标，其最大值是size-1 
}


用链表实现栈:
数据结构定义
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

用数组实现队列
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

链式队列
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

欧里几得法求最大公约数
递归 
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
非递归
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

康托展开

逆康托展开 

