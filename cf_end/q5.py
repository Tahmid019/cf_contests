MOD = 998244353

def mod_exp(base, exp, mod):
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

def solve_case(N, strings):
    trie = set()
    total_nodes = 1  # Start with the root node (empty string)
    
    for s in strings:
        current_prefixes = ['']  # Start with the root (empty string)
        
        for ch in s:
            next_prefixes = []
            if ch == '?':
                for prefix in current_prefixes:
                    for letter in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
                        new_prefix = prefix + letter
                        next_prefixes.append(new_prefix)
                        if new_prefix not in trie:
                            trie.add(new_prefix)
                            total_nodes = (total_nodes + 1) % MOD
            else:
                for prefix in current_prefixes:
                    new_prefix = prefix + ch
                    next_prefixes.append(new_prefix)
                    if new_prefix not in trie:
                        trie.add(new_prefix)
                        total_nodes = (total_nodes + 1) % MOD
            
            current_prefixes = next_prefixes
    
    return total_nodes

def main():
    # Read input from a file named 'input.txt'
    with open('inputold.txt', 'r') as infile:
        T = int(infile.readline().strip())  # Number of test cases
        results = []
        for case_num in range(1, T + 1):
            N = int(infile.readline().strip())
            strings = [infile.readline().strip() for _ in range(N)]
            result = solve_case(N, strings)
            results.append(f"Case #{case_num}: {result}")
    
    # Write output to a file named 'output.txt'
    with open('output.txt', 'w') as outfile:
        outfile.write("\n".join(results) + "\n")

if __name__ == "__main__":
    main()
