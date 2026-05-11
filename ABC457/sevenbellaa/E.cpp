// {L, R} 배열 두군데에 넣고 각각 L, R 우선으로 정렬
// L이 바뀌는 지점들 전부 기록, R이 바뀌는 지점들 전부 기록
// S로 시작하는 구간중 끝점이 T 이하인 최대 구간 + T로 끝나는 구간중 끝점이 S 이하인 최대 구간
// 만약 둘중 하나라도 S, T == L, R 이면 나머지 하나는 그냥 S <= L <= T, S <= R <= T인 L, R 아무거나 잡기
// 저 범위에 들어가는 L, R 존재하는지 어떻게 빠르게 확인? 시작점 끝점 하나라도 고정이면 이분탐색 돌리면 될거같은데...

// 한 점이 L, R == S, T 일때 나머지 한 점 찾는게 문제임
// 구간마다 R 최솟값 빨리구할수있으면? 이거 하는게 쉽지않네 아닌가 세그로 되나 -> 레이지 세그같은데?
// 아니 각 노드를 L이라고 하면 저장되는값을 시작점이 L일때 R의 최솟값 이러면 되지않나????
// 그러면 2 ~ 10 사이에 들어오는 점 찾고싶다?
// 시작점이 2인점 ~ 시작점이 10인 점중에서 R 최솟값 찾아서 그게 10 이하이면 됨. -> 그냥 세그로 가능!!

// 정렬 + 세그로 하지말고 그냥 전부 세그로 하면 될거같은데 정렬로 하는게 구현이 너무 복잡해짐
// 노드 L에 대해서 R 최솟값 세그 하나
// 노드 R에 대해서 L 최댓값 세그 하나? 이걸론 1 3, 2 4 이런 겹치는거 못찾지않나 걍 정렬 + 이탐 + 세그 해야되나

// 위 조건 만족하는 페어가 없으면 No

#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 200002, M_MAX = 200002;

struct Point {
  int x, y;
  friend istream& operator>>(istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
  }
};

int tree[N_MAX * 2];

void update(int l, int r) {
  l += N_MAX;
  tree[l] = min(tree[l], r);
  while (l >>= 1) tree[l] = min(tree[l], r);
}

int get(int l, int r) {
  int res = 0x3f3f3f3f;
  for (l += N_MAX, r += N_MAX; l <= r; l >>= 1, r >>= 1) {
    if (l & 1) res = min(res, tree[l++]);
    if (~r & 1) res = min(res, tree[r--]);
  }
  return res;
}

int N, M, Q, Lpos[N_MAX], Rpos[N_MAX];
Point Lfirst[M_MAX], Rfirst[M_MAX];

void init() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> Lfirst[i];
    Rfirst[i] = Lfirst[i];
  }

  sort(Lfirst, Lfirst + M, [](const Point& p1, const Point& p2) {
    if (p1.x != p2.x) return p1.x < p2.x;
    return p1.y < p2.y;
  });
  sort(Rfirst, Rfirst + M, [](const Point& p1, const Point& p2) {
    if (p1.x != p2.x) return p1.x < p2.x;
    return p1.y < p2.y;
  });

  int Lprev = 0, Rprev = 0;
  for (int i = 0; i < M; i++) {
    update(Lfirst[i].x, Lfirst[i].y);
    if (Lfirst[i].x != Lprev) {
      Lpos[Lfirst[i].x] = i;
      Lprev = Lfirst[i].x;
    }
    if (Rfirst[i].y != Rprev) {
      Rpos[Rfirst[i].y] = i;
      Rprev = Rfirst[i].y;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();
  cin >> Q;
  while (Q--) {
    int S, T;
    cin >> S >> T;

    int Spos = Lpos[S], Tpos = Rpos[T];
    if (Spos == 0 && Tpos == 0) {
      cout << "No\n";
      continue;
    }

    if (Spos) }
}