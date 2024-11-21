//M1 sorted array
//M2 traverse and upheapify
maxheap(vector<int>v){
    //O(nlogn)
    hp=v;
    for(int i=0;i<hp.size();i++){
        upheapify(i);
    }
}


//M3 traverse and downheapify
void maxheap(vector<int>v){
    // O(n)
    hp=v;
    int n=hp.size();
    for(int i=n/2;i>=0;i--){
        downheapify(i);
    }
}

