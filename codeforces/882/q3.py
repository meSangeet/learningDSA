t = int(input())  # Read the number of test cases

for _ in range(t):
    n = int(input())  # Read the number of initial Stand users
    a = list(map(int, input().split()))  # Read the strengths of initial Stand users

    max_strength = 0  # Initialize max_strength as minimum possible strength

    # Find the initial maximum strength among the Stand users
    for strength in a:
        max_strength = max(max_strength, strength)

    print(max_strength)  # Print the initial maximum strength

    # Calculate the maximum strength after each additional Stand user
    if n >= 2:
        for i in range(1, n):
            max_strength = max(max_strength, max_strength ^ a[i])
            print(max_strength)
