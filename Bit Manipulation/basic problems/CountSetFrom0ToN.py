def count_set_bits(n):
    count = 0 
    while n > 0:
        count += n & 1
        n >>= 1
    return count

def total_set_bits(N):
    total_count = 0
    for i in range(1, N + 1):
        total_count += count_set_bits(i)
    return total_count
N = 5
print(total_set_bits(N))

# Optimization of the answer 
#  https://www.youtube.com/watch?v=PW2aK1QBBoc
def total_set_bits(N):
    if N == 0:
        return 0
    x = 0
    while (1 << (x + 1)) <= N:
        x += 1
    if x==0:
        return 1
    bits_up_to_2_x = x * (1 << (x - 1))
    msb_from_2_x_to_N = N - (1 << x) + 1
    remaining_bits = total_set_bits(N - (1 << x))
    return bits_up_to_2_x + msb_from_2_x_to_N + remaining_bits
N = 5
print(total_set_bits(N))
