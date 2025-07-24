#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;

    long long total_sum = 0;
    std::vector<std::pair<int, int>> coins(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i].first >> coins[i].second;
        total_sum += (long long)coins[i].first * coins[i].second;
    }

    if (total_sum % 2 != 0) {
        std::cout << 0 << "\n";
        return;
    }

    long long target = total_sum / 2;
    std::vector<bool> dp(target + 1, false);
    dp[0] = true;

    // --- 로그 분할 최적화 적용 ---
    std::vector<int> items;
    for (const auto& coin : coins) {
        int value = coin.first;
        int count = coin.second;
        for (int k = 1; count > 0; k *= 2) {
            int num_to_take = std::min(k, count);
            items.push_back(value * num_to_take);
            count -= num_to_take;
        }
    }

    // 최적화된 아이템 목록으로 DP 실행
    for (int item_value : items) {
        // k의 시작점을 target(obj)으로 수정
        for (long long j = target; j >= item_value; --j) {
            dp[j] = dp[j] || dp[j - item_value];
        }
    }

    std::cout << (dp[target] ? 1 : 0) << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    for (int i = 0; i < 3; ++i) {
        solve();
    }

    return 0;
}