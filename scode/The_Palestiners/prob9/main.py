from math import sqrt

def can_establish_boundary(n, m, ali_points, iheb_points):
    def is_inside_circle(x, y, cx, cy, r):
        return (x - cx)**2 + (y - cy)**2 < r**2

    def check_boundary(points_inside, points_outside):
        x1, y1 = points_inside[0]
        x2, y2 = points_outside[0]
        d = sqrt((x1 - x2)**2 + (y1 - y2)**2)

        for x, y in points_inside:
            if not is_inside_circle(x, y, x2, y2, d):
                return "NO"

        for x, y in points_outside:
            if is_inside_circle(x, y, x1, y1, d):
                return "NO"

        return "YES"

    ali_inside = [tuple(map(int, input().split())) for _ in range(n)]
    iheb_outside = [tuple(map(int, input().split())) for _ in range(m)]

    return check_boundary(ali_inside, iheb_outside)

# Example usage
n, m = map(int, input().split())
result = can_establish_boundary(n, m)
print(result)

