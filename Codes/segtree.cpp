/*
* Segment Tree con update convencional
*/

#include <vector>
using namespace std;

class SegmentTree{
	private:
		vector<int> st, A;
		int n;
		int left(int p) { return p << 1; }
		int right(int p) { return (p << 1) + 1; }

		void build(int p, int L, int R){
			if (L == R) st[p] = A[L];
			else{
				build(left(p), L, (L+R)/2);
				build(right(p), (L+R)/2 + 1, R);
				int p1 = st[left(p)], p2 = st[right(p)];
				st[p] = p1 * p2;
			} 
		}

		void update(int p, int val, int L, int R, int i){
			if (L == R){
				A[L] = val;
				st[p] = val;
				return;
			}

			int mid = (L + R) / 2;
			if (i <= mid){
				update(left(p), val, L, (L + R) / 2, i);
				int p1 = st[left(p)], p2 = st[right(p)];
				st[p] = p1 * p2;
			}
			else{
				update(right(p), val, (L + R) / 2 + 1, R, i);
				int p1 = st[left(p)], p2 = st[right(p)];
				st[p] = p1 * p2;
			}

		}

		int rmq(int p, int L, int R, int i, int j){
			if (i > R || j < L) return -2;
			if (L >= i && R <= j) return st[p];


			int p1 = rmq(left(p), L, (L + R)/2, i, j);
			int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

			if (p1 == -2) return p2;
			if (p2 == -2) return p1;
			return p1 * p2;
		}

	public:
		SegmentTree(vector<int> &v){
			A = v; n = (int)A.size();
			st.assign(4*n, 0);
			build(1, 0, n - 1);
		}

		int rmq(int i, int j){
			return rmq(1, 0, n - 1, i, j);
		}

		void update(int val, int i){
			return update(1, val, 0, n - 1, i);
		}

		void print(){
			for (int i = 0; i < A.size(); i++) printf("%d ", A[i]);
			printf("\n");	
		}
};