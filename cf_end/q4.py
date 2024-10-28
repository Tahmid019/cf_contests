MOD = 998244353

def count_decodings(s):
    n = len(s)
    if n == 0:
        return 0
    
    dp = [0] * (n + 1)
    dp[0] = 1  # There's one way to decode an empty string
    
    for i in range(1, n + 1):
        if s[i - 1] != '0':
            dp[i] = dp[i - 1]
        
        if i > 1:
            two_digit = int(s[i - 2:i])
            if 10 <= two_digit <= 26:
                dp[i] = (dp[i] + dp[i - 2]) % MOD
    
    return dp[n]

def generate_uncorrupted_strings(encoded, index=0):
    if index == len(encoded):
        return [encoded]
    
    if encoded[index] == '?':
        results = []
        for digit in range(0, 10):
            new_encoded = encoded[:index] + str(digit) + encoded[index + 1:]
            results.extend(generate_uncorrupted_strings(new_encoded, index + 1))
        return results
    else:
        return generate_uncorrupted_strings(encoded, index + 1)

def find_kth_largest_string(encoded, K):
    uncorrupted_strings = generate_uncorrupted_strings(encoded)
    
    max_decodings = 0
    valid_strings = []
    
    for string in uncorrupted_strings:
        # Skip if the string has leading zeros
        if string[0] == '0':
            continue
            
        decodings = count_decodings(string)
        
        if decodings > max_decodings:
            max_decodings = decodings
            valid_strings = [string]
        elif decodings == max_decodings:
            valid_strings.append(string)
    
    valid_strings.sort()
    
    if K <= len(valid_strings):
        kth_largest = valid_strings[-K]
        return kth_largest, max_decodings
    else:
        return None, None

def main():
    # Read input from a file named 'input.txt'
    with open('input.txt', 'r') as infile:
        T = int(infile.readline().strip())  # Number of test cases
        results = []
        
        for case_num in range(1, T + 1):
            line = infile.readline().strip().split()
            encoded = line[0]
            K = int(line[1])
            
            kth_largest_string, max_decodings = find_kth_largest_string(encoded, K)
            
            if kth_largest_string is not None:
                results.append(f"Case #{case_num}: {kth_largest_string} {max_decodings}")
    
    # Write output to a file named 'output.txt'
    with open('output.txt', 'w') as outfile:
        outfile.write("\n".join(results) + "\n")

if __name__ == "__main__":
    main()
