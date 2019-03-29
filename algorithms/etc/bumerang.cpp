#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(0));
	bool bumerang;
	int i = 100000, ammo, bumerang_num;
	double sum, dmg, sumsum = 0, bumerang_sum = 0;
	while (i--) {
		ammo = 20;
		sum = bumerang_num = 0;
		bumerang = false;
		while (ammo) {
			dmg = 100;
			if (bumerang)
				dmg *= 1.2;
			bumerang = false;
			ammo--;
			if (rand() % 2) {   // 크리티컬
				dmg *= 2;
				if (rand() % 2) {   // 부메랑
					bumerang = true;
					bumerang_num++;
					ammo++;
				}
			}
			sum += dmg;
		}
		printf("Total Damage : %f , Bumerang : %d\n", sum, bumerang_num);
		sumsum += sum;
		bumerang_sum += bumerang_num;
	}
	printf("\n\n Average Damage : %f , Average Bumerang : %f\n", sumsum / 100000, bumerang_sum / 100000);
	return 0;
}
