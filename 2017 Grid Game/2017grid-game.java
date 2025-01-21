class Solution {
    public long gridGame(int[][] grid) {
        long firstRowSum = IntStream.of(grid[0]).mapToLong(i -> i).sum();
        long secondRowSum = 0;
        long result = Long.MAX_VALUE;

        for (int i = 0; i < grid[0].length; ++i) {
            firstRowSum -= grid[0][i];
            result = Math.min(result, Math.max(firstRowSum, secondRowSum));

            secondRowSum += grid[1][i];
        }

        return result;
    }
}