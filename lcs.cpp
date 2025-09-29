#include "lcs.h"
#include <vector>

std::pair<int, int> substringMasLargoComun(const std::string& s1, const std::string& s2) {
    int n = s1.size();
    int m = s2.size();
    int maxLen = 0;
    int endPos = 0;

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endPos = i;
                }
            }
        }
    }
    if (maxLen == 0) return {-1, -1};
    return {endPos - maxLen + 1, endPos};
}