int main () {

    int arr[] ={10,30,21,44,32,17,19,66};
    int n = 0;
    int maxi = INT_MIN;
    int i = 0;

    findmaxi(arr, n, i, maxi);

    cout << "maximum number is: " << maxi << endl;

    return 0;
}