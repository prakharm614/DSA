  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n=arr.size();
    d %= n;
    reverse(arr.begin(), arr.begin() + d); // rev begin d

    reverse(arr.begin() + d, arr.end()); //rev remain
  
    reverse(arr.begin(), arr.end()); //rev all
}