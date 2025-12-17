Key Logic Summary

Monotonic Stack: The stack stores indices such that the corresponding heights are always increasing.

Triggering Calculation: We only calculate the area when we encounter a bar smaller than the one at the top of the stack. This smaller bar acts as the right boundary limit.

Width Formula: (NSE - PSE - 1)

NSE (Next Smaller Element): The index i that caused the pop.

PSE (Previous Smaller Element): The index currently at the top of the stack (after popping the target element).