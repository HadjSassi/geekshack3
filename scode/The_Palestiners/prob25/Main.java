import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class HarmonizedSequence {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input
        int N = scanner.nextInt();
        int[] sequence = new int[2 * N];
        for (int i = 0; i < 2 * N; i++) {
            sequence[i] = scanner.nextInt();
        }

        // Solve the problem
        Result result = solve(sequence, N);

        // Print the lexicographically smallest harmonized sequence
        for (int num : result.sequence) {
            System.out.print(num + " ");
        }
    }

    static class Result {
        int swaps;
        int[] sequence;

        public Result(int swaps, int[] sequence) {
            this.swaps = swaps;
            this.sequence = sequence;
        }
    }

    private static Result solve(int[] sequence, int N) {
        int swaps = 0;

        // Create a map to store the indices of each element
        Map<Integer, Integer> indexMap = new HashMap<>();
        for (int i = 0; i < 2 * N; i++) {
            indexMap.put(sequence[i], i);
        }

        // Iterate through the sequence and perform swaps to achieve the harmonized sequence
        for (int i = 1; i <= N; i++) {
            int target = 2 * i - 1;

            // If the target is not in the correct position, perform swaps
            while (sequence[target] != i) {
                int current = sequence[target];
                int currentIndex = indexMap.get(i);
                int currentTargetIndex = indexMap.get(current);

                // Swap elements
                sequence[target] = i;
                sequence[currentTargetIndex] = current;

                // Update index map
                indexMap.put(i, target);
                indexMap.put(current, currentIndex);

                swaps++;
            }
        }

        // Sort the first N elements to get the lexicographically smallest sequence
        Arrays.sort(sequence, 0, N);

        return new Result(swaps, sequence);
    }
}
