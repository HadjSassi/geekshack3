from collections import defaultdict, deque

import math

def can_establish_boundary(n, m, ali_points, iheb_points):
    def is_inside_circle(x, y, cx, cy, r):
        distance = math.sqrt((x - cx)**2 + (y - cy)**2)
        return distance <= r

    def calculate_circle_parameters(x1, y1, x2, y2):
        cx = (x1 + x2) / 2
        cy = (y1 + y2) / 2
        r = math.sqrt((x1 - cx)**2 + (y1 - cy)**2)
        return cx, cy, r

    # Check if a boundary can be established for both cases
    def check_boundary_for_case(ali_points, iheb_points):
        for ali_point in ali_points:
            for iheb_point in iheb_points:
                cx, cy, r = calculate_circle_parameters(ali_point[0], ali_point[1], iheb_point[0], iheb_point[1])
                
                # Check if all Iheb's points are outside the circle
                if all(not is_inside_circle(iheb[0], iheb[1], cx, cy, r) for iheb in iheb_points):
                    return True
        return False

    # Check if a boundary can be established in either case
    if check_boundary_for_case(ali_points, iheb_points) or check_boundary_for_case(iheb_points, ali_points):
        return "YES"
    else:
        return "NO"

# Input handling
try:
    n, m = map(int, input().split())
    ali_points = [tuple(map(int, input().split())) for _ in range(n)]
    iheb_points = [tuple(map(int, input().split())) for _ in range(m)]

    # Output the result
    result = can_establish_boundary(n, m, ali_points, iheb_points)
    print(result)

except ValueError:
    print("Invalid input. Please enter valid integers.")
except Exception as e:
    print(f"An error occurred: {e}")

