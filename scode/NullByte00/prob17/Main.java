import java.util.HashSet;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.nextLine();

        HashSet<String> possibilities = new HashSet<>();
        Stack<String> stack = new Stack<>();
        stack.push(s);

        while (!stack.isEmpty()) {
            // System.out.println("before: " + stack.peek() + " " + possibilities.size());

            s = stack.pop();

            if (possibilities.contains(s)) {
                continue;
            } else {
                possibilities.add(s);
            }

            if (s.length() > 1) {
                for (int i = 0; i < s.length() - 1; ++i) {
                    if (s.charAt(i) == s.charAt(i + 1)) {
                        if (s.charAt(i) == 't') {
                            String s1 = s.substring(0, i) + "v" + s.substring(i + 2);
                            stack.push(s1);
                        } else {
                            stack.push(s.substring(0, i) + "t" + s.substring(i + 2));
                        }
                    }
                }
            }
            // System.out.println("after: " + stack.size() + " " + possibilities.size());
        }
    }
}