int kthElement(vector<int>& a, vector<int>& b, int k) {
    int i = 0, j = 0, count = 0;
    
    // Iterate through both arrays
    while (i < a.size() && j < b.size()) {
        int current;
        
        // Select the smaller element from the two arrays
        if (a[i] < b[j]) {
            current = a[i];
            i++;
        } else {
            current = b[j];
            j++;
        }
        
        count++;
        if (count == k) {
            return current; // Return the k-th element
        }
    }
    
    // If one array is exhausted, continue with the other array
    while (i < a.size()) {
        count++;
        if (count == k) {
            return a[i];
        }
        i++;
    }
    
    while (j < b.size()) {
        count++;
        if (count == k) {
            return b[j];
        }
        j++;
    }
    
    return -1; // This case should not occur if k is valid
}
