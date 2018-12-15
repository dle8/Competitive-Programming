# Competitive-Programming
Programs I've coded for Competitive Programming.

Notes for errors made during coding:
1. ALWAYS THINK OF DYNAMIC PROGRAMMING BEFORE USING COMBINATORICS.
2. Calculate eps value(Don't just guess):
  - Eps value can varies depending on round error while performing arithmetic calculation.
  - Avoiding divides (if can) & sqrt() in real number processing.
  - Can compare (a / b) & (c / d) by comparing (a * d - b * c) to 0.
3. Watch out for memset() function when test cases if large.
  - Should not use memset fucntion.
  - Instead of can reinitializing value in the loop that reads in the input together.
4. Implement adjacency list by vector instead of using struct pointer.
5. Sorting function requires strictly smaller(or larger) comparison, or else will lead to wrong answer.
