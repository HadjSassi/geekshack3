def evaluate_polynomial(coefficients, values_of_x):
    results = [sum(c * (x ** (len(coefficients) - 1 - i)) for i, c in enumerate(coefficients)) for x in values_of_x]
    return results


t = int(input())
for _ in range(t):
        input()  # Ignore the first line, as n is not needed in the solution
        coefficients = list(map(int, input().split()))
        values_of_x = list(map(int, input().split()))
        results = evaluate_polynomial(coefficients, values_of_x)
        print(" ".join(map(str, results)))


