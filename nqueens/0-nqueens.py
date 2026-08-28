#!/usr/bin/python3
"""
Program that solves
the N queens problem.
"""
import sys


def parse_args():
    """Check the arguments"""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    return n


def solve_nqueens(n, row, current_solution, solutions):
    """
    Recursively finds all possible solutions
    """
    if row == n:
        solutions.append(list(current_solution))
        return

    for col in range(n):
        is_safe = True
        for r, c in current_solution:
            if c == col or abs(c - col) == abs(r - row):
                is_safe = False
                break

        if is_safe:
            current_solution.append([row, col])
            solve_nqueens(n, row + 1, current_solution, solutions)
            current_solution.pop() 


def main():
    n = parse_args()
    solutions = []
    solve_nqueens(n, 0, [], solutions)

    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    main()