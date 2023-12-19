Initialize dp 2D array with dimensions N x N filled with negative infinity values
Set dp[0][0] to grid[0][0]

for k in range(1, 2*N-1):
    Create a new_dp 2D array with dimensions N x N filled with negative infinity values
    
    for i in range(max(0, k-(N-1)), min(N-1, k) + 1):
        for j in range(max(0, k-(N-1)), min(N-1, k) + 1):
            if grid[i][k-i] == -1 or grid[j][k-j] == -1:
                continue
            
            cherries = grid[i][k-i]
            if i != j:
                cherries += grid[j][k-j]
            
            Update new_dp[i][j] by taking the maximum of its current value and cherries plus the maximum cherries collected from adjacent positions
            
    Set dp to new_dp

Return dp[N-1][N-1] if it's greater than or equal to 0, else return 0
