/*
음수 간선 허용, 음수 사이클 존재 여부 판별가능
O(VE)
*/

bool bellman_ford() {
	bool isChanged = false;
	for (auto i : edge) {
		if (dist[i.x] == INF)
			continue;
		if (dist[i.x] + i.val < dist[i.y]) {
			dist[i.y] = dist[i.x] + i.val;
			isChanged = true;
		}
	}
	return isChanged;
}

int main(){
  while(M--)
    bellman_ford();
  if(bellman_ford())
    isCycling = true;
}
