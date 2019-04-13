/*
O(log n)
*/

public static int minNumOper(int n) {
int count = 0;
while(n != 0) {
if(n % 2 == 0 || n == 1) {
count += 1;
} else {
count += 2;
}
n /= 2;
}
return count;
}