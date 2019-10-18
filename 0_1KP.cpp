#include <iostream>
#include <cstring>
using namespace std;

int memo[10][100]; //items, jewellery.

int knapsackTD(int cost[], int weight[], int lt, int be, int en) {
	if (be > en) {
		return 0;
	}
	const int inf = 1e7;
	int ans1 = -inf;
	int ans2 = -inf;
	if (memo[be][lt] != -1) return memo[be][lt];

	//picking up the item.
	if (weight[be] <= lt) {
		ans1 = knapsackTD(cost, weight, lt - weight[be], be + 1, en ) + cost[be];
	}
	ans2 = knapsackTD(cost, weight, lt, be + 1, en);
	memo[be][lt] = max(ans2, ans1);

	return memo[be][lt];
}

int knapsackBU(int cost[], int weight[], int lt, int n) {
	int dp[10][100];

	//Base Cases
	for (int wt = 0; wt <= lt; ++wt) {
		if (wt >= weight[0]) dp[0][wt] = cost[0];
		else dp[0][wt] = 0;
	}

	for (int item = 0; item < n; ++item) {
		dp[item][0] = 0;
	}

	for (int item = 1; item < n; ++item) {
		for (int wt = 1; wt <= lt; ++wt) {

			int pick = -1e7;
			int notPick = -1e7;

			if (weight[item] <= wt) {
				pick = cost[item] + dp[item - 1][wt - weight[item]];

			}
			notPick = dp[item - 1][wt];
			dp[item][wt] = max(pick, notPick);
		}
	}
	return dp[n - 1][lt];
}

int main()
{

	int cost[100];
	int weight[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> cost[i];
	for (int i = 0; i < n; ++i) cin >> weight[i];

	int lt;
	cin >> lt;

	memset(memo, -1, sizeof memo);
	//Now we have two approaches available: either top-down DP or bottom-up DP.
	int ans = knapsackTD(cost, weight, lt, 0, n - 1);
	cout << ans;
	//int ans = knapsackBU(cost, weight, lt, n);
	/* code */
	return 0;
}

talented, high - standards, smart, intelligent, deep - thoughts, personality, takes lot of pressure, amazing personality, friend, cool and calm  

shayd yahi hogi sabse mushkil shayari,
vakif bhi nahi hui tumhari parchaai.

humesha rahogi  
humesha shuru hoti rahegi tumse woh qatar,
kshitij tak 
