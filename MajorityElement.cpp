int majorityElement(const vector<int> &A) {
    int curr = A[0];
    int occ = 1;

    for(int i=1; i<A.size(); i++){
        if(occ == 0){
            curr = A[i];
            occ = 1;
        }
        else if( A[i] == curr){
            occ++;
        }
        else{
            occ--;
        }
    }
    return curr;
}

