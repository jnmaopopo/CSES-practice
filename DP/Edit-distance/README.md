The edit distance between two strings is the minimum number of operations required to transform one string into the other.

The allowed operations are:
Add one character to the string.
Remove one character from the string.
Replace one character in the string.
For example, the edit distance between LOVE and MOVIE is 2, because you can first replace L with M, and then add I.

Your task is to calculate the edit distance between two strings.

Input

The first input line has a string that contains n characters between A–Z.

The second input line has a string that contains m characters between A–Z.

Output

Print one integer: the edit distance between the strings.

Constraints
1≤n,m≤5000
Example

Input:
LOVE
MOVIE

Output:
2



OneLine:
dp[i][j] is the min operations for making s[:i] t[:j] eauals

if(s[i-1] == s[j-1]) no opetation
we can do delete s[i-1] (dp[i-1][j]), delete t[j-1] (dp[i][j-1]), or replace one of them (dp[i-1][j-1]);