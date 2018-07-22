#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {

    vector<int> answers;
    for(int i=0; i<4; i++) {
        
        
        for(int k=0; k<4; k++) {
            int sum = 0;
            int j;
            for(j=k; j<k+3; j++) {
                sum += arr[i][j];        
            }
            j--;
            // cout << "Sum 1: " << sum <<" j: " << j << endl;
            sum += arr[i+1][j-1];
            // cout << "Sum 2: " << sum << endl;
            for(j=k; j<k+3; j++) {
                sum += arr[i+2][j];
            }
            // cout << "Sum 3: " << sum << endl;
            answers.push_back(sum);
           
        }
        
    }
    int max = -2147483647 - 1;
    for(int i=0; i<answers.size(); i++) {
        if (answers[i] > max) {
            max = answers[i];
        }
    }
    return max;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);
    cout << result << "\n";
    fout << result << "\n";

    fout.close();

    return 0;
}
