#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {

	int *arrA = new int[27];
	int *arrB = new int[27];
	memset(arrA, 0, sizeof(arrA));
	memset(arrB, 0, sizeof(arrB));

	int count = 0;

	for(int i=0; i<a.length(); i++) {
		int index = (int)(a[i]) - 96;
		arrA[index]++;
	}
	for(int i=0; i<b.length(); i++) {
		int index = (int)(b[i]) - 96;
		arrB[index]++;
	}
	
	for(int i=0; i<a.length(); i++) {
		int index = (int)(a[i]) - 96;
		if (arrB[index] == 0) {
			count++;
		} else {
			arrB[index]--;
		}
	}
	for(int i=0; i<b.length(); i++) {
		int index = (int)(b[i]) - 96;
		if (arrA[index] == 0) {
			count++;
		} else {
			arrA[index]--;
		}
	}

	return count;

}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    // fout << res << "\n";
	cout << res << "\n";
    // fout.close();

    return 0;
}
