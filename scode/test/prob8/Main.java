import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = 1000010;
        int P = 1000000007;
        int n = scanner.nextInt();
        int[] po = new int[N];
        int[] a = new int[N];
        int[] f = new int[N];
        int ans = 0;

        po[0] = 1;
        for (int i = 1; i <= n; i++) {
            po[i] = (2 * po[i - 1]) % P;
        }

        for (int k = 0; k < n; k++) {
            int x = scanner.nextInt();
            a[x]++;
        }

        for (int i = N - 1; i > 1; i--) {
            int x = 0;
            for (int j = i; j < N; j += i) {
                x += a[j];
            }
            if (x > 0) {
                f[i] = (int) (1L * x * po[x - 1] % P);
                for (int j = i + i; j < N; j += i) {
                    f[i] = (f[i] - f[j] + P) % P;
                }
                ans = (int) (1L * f[i] * i + ans) % P;
            }
        }

        System.out.println(ans);
    }
}
