// ACCEPTED!

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

//########QUEUE############ (see clear)
typedef struct node_ {
    int val;
    struct node_* next;
} node;

typedef struct {
    node* head;
    node* tail;
    int size;
} queue;

void push_queue(queue* q, int v){
    node *item = (node*)malloc(sizeof(node));
    item->val = v;
    item->next = NULL;
    if(q->head == NULL){
        q->head = q->tail = item;
    } else {
        q->tail->next = item;
        q->tail = item;
    }
    q->size += 1;
}

int pop_queue(queue* q){
    int popped;
    if (q->head == NULL){
        exit(1); // runtime error
    } else {
        popped = q->head->val;
        node* next = q->head->next;
        //free(queue->head);
        q->head = next;
        if(q->head == NULL)
            q->tail = NULL;
        q->size -= 1;
    }
    return popped;
}

int front_queue(queue* q) {
	return q->head->val;
}

bool empty_queue(queue* q) {
    return (q->size == 0);
}

// To save time, free is not used :c
void clear_queue(queue* q) {
	q->head = q->tail = NULL;
	q->size = 0;
}

int size_queue(queue* q) {
	return q->size;
}
//########QUEUE############


typedef vector<int> vi;
typedef vector<queue> vqi;

class SegmentTree {
private:
	string land;
	vi st;
	vqi lazy;
	int n;

	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }

	void build(int p, int L, int R) {
		if(L == R) {
			st[p] = (land[L] == '1') ? 1 : 0;
		} else {
			build(left(p), L, (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R);
			st[p] = st[left(p)] + st[right(p)];
		}
	}

	void updateNode(int p, int L, int R) {
		if(empty_queue(&(lazy[p])))
			return;

		if(front_queue(&(lazy[p])) != -1) {
			int val = pop_queue(&(lazy[p]));
			st[p] = val * (R - L + 1);
			if(L != R) {
				clear_queue(&(lazy[left(p)]));
				push_queue(&(lazy[left(p)]), val);
				clear_queue(&(lazy[right(p)]));
				push_queue(&(lazy[right(p)]), val);
	    	}
		}

		if(empty_queue(&(lazy[p])))
			return;

		if(size_queue(&(lazy[p])) % 2 == 1) {
			st[p] = (R - L + 1) - st[p];
			if(L != R) {
				push_queue(&(lazy[left(p)]), -1);
				push_queue(&(lazy[right(p)]), -1);
			}
		}

		lazy[p] = {NULL, NULL, 0};
	}

	void update(int p, int L, int R, int a, int b, int val) {
		updateNode(p, L, R); // execute pending operations on this node
	  
		if(L > b || R < a) // Current segment is not within range [a, b]
			return;
	    
	  	if(a <= L && R <= b) { // Segment is fully within range
	    	st[p] = val * (R - L + 1);

			if(L != R) { // Not leaf node
				clear_queue(&(lazy[left(p)]));
				push_queue(&(lazy[left(p)]), val);
				clear_queue(&(lazy[right(p)]));
				push_queue(&(lazy[right(p)]), val);
			}
		} else {
			update(left(p), L, (L + R) / 2, a, b, val); // Updating left child
			update(right(p), (L + R) / 2 + 1, R, a, b, val); // Updating right child

			st[p] = st[left(p)] + st[right(p)]; // Updating root with sum
		}
	}

	void invert(int p, int L, int R, int a, int b) {
		updateNode(p, L, R); // execute pending operations on this node
	  
		if(L > b || R < a) // Current segment is not within range [a, b]
			return;

	  	if(a <= L && R <= b) { // Segment is fully within range
	    	st[p] = (R - L + 1) - st[p];

			if(L != R) { // Not leaf node
				push_queue(&(lazy[left(p)]), -1);
				push_queue(&(lazy[right(p)]), -1);
			}
		} else {
			invert(left(p), L, (L + R) / 2, a, b); // Updating left child
			invert(right(p), (L + R) / 2 + 1, R, a, b); // Updating right child
			st[p] = st[left(p)] + st[right(p)]; // Updating root with sum
		}
	}

	int query(int p, int L, int R, int a, int b) {
		if(R < a || b < L)
			return 0; // Out of range

		updateNode(p, L, R); // execute pending operations on this node

		if(a <= L && R <= b) // Current segment is totally within range [a, b]
			return st[p];

		int q1 = query(left(p), L, (L + R) / 2, a, b); // Query left child
		int q2 = query(right(p), (L + R) / 2 + 1, R, a, b); // Query right child
		return q1 + q2;
	}
public:
	SegmentTree() {
		land.reserve(1100000);
	}

	void construct(const string &ld) {
		n = ld.length();
		land = ld;
		st.assign(4 * n, 0);
		lazy.assign(4 * n, {NULL, NULL, 0});
		build(1, 0, n - 1);
	}

	void toBuccaneer(int a, int b) {
		update(1, 0, n - 1, a, b, 1);
	}

	void toBarbary(int a, int b) {
		update(1, 0, n - 1, a, b, 0);
	}

	void invert(int a, int b) {
		invert(1, 0, n - 1, a, b);
	}

	int query(int a, int b) {
		return query(1, 0, n - 1, a, b);
	}
};

int main() {
	int ntc, M, T, Q;
	char q;
	int a, b;
	string ld;
	string pirates;
	SegmentTree st;

	ld.reserve(1100000);
	pirates.reserve(100);
	cin >> ntc;

	for(int i = 1; i <= ntc; ++i) {
		cout << "Case " << i << ":" << endl;

		cin >> M;
		ld = "";
		for(int j = 1; j <= M; ++j) {
			cin >> T;
			cin >> pirates;
			for(int k = 1; k <= T; ++k) {
				ld.append(pirates);
			}
		}

		st.construct(ld);

		cin >> Q;
		int c = 0;
		for(int j = 1; j <= Q; ++j) {
			cin >> q >> a >> b;
			switch(q) {
				case 'F':
					st.toBuccaneer(a, b);
					break;
				case 'E':
					st.toBarbary(a, b);
					break;
				case 'I':
					st.invert(a, b);
					break;
				case 'S':
					cout << "Q" << (++c) << ": " << st.query(a, b) << endl;
					break;
				default:
					cout << "No puede ser!" << endl;
					break;
			}
		}
	}

	return 0;
}
/*/
int main() {
	SegmentTree st;
	st.construct("0101");

	st.invert(0, 1);
	st.invert(0, 3);
	cout << st.query(0, 1) << endl;
	cout << st.query(2, 3) << endl;
	cout << st.query(1, 2) << endl;

	return 0;
}
//*/