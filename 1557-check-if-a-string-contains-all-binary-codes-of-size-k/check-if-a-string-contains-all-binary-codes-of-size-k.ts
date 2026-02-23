function hasAllCodes(s: string, k: number): boolean {
    const need = 1 << k; 
    const seen = new Set<number>();
    
    let num = 0;
    let mask = (1 << k) - 1;

    for (let i = 0; i < s.length; i++) {
        num = ((num << 1) & mask) | (s.charCodeAt(i) - 48);

        if (i >= k - 1) {
            seen.add(num);
            if (seen.size === need) return true; 
        }
    }

    return false;
}