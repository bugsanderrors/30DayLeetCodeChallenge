"""
    Write an algorithm to determine if a number n is "happy".

    A happy number is a number defined by the following process: 
    Starting with any positive integer, replace the number by the sum of the squares of its digits, 
    and repeat the process until the number equals 1 (where it will stay), 
    or it loops endlessly in a cycle which does not include 1. 
    Those numbers for which this process ends in 1 are happy numbers.

    Return True if n is a happy number, and False if not.

    Example:
    Input: 19
    Output: true
    Explanation: 
    1^2 + 9^2 = 82
    8^2 + 2^2 = 68
    6^2 + 8^2 = 100
    1^2 + 0^2 + 0^2 = 1

"""

def isHappy(self, n: int) -> bool:
        if n==1:
            return True
        cycle = [4, 16, 37, 58, 89, 145, 42, 20]
        
        while n!=1:
            n = sum(int(c)**2 for c in str(n))
            if n==1:
                return True
            elif n in cycle:
                return False