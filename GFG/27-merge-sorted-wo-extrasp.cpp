    int i = a.size() - 1, j = 0;

      // swap smaller elements from b[] 
      // with larger elements from a[]
    while (i >= 0 && j < b.size() && a[i] > b[j]) {
          swap(a[i--], b[j++]);
    }

    // Sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());