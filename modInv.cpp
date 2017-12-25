typedef pair<int, int> pii;

// Finds constants {u, v} s.t. a*u+b*v = 1
// Requires gcd(a, b) == 1
// Call with egcd(a, b)
pii egcd(int a, int b, pii x = {1, 0}, pii y = {0, 1}) {
	return (b == 1) ? y : egcd(b, a%b, y, {x.first-a/b*y.first, x.second-a/b*y.second});
}

// Finds x s.t. (a*x) % n == 1
// Assumes a is not zero divisor (i.e. gcd(a, n) == 1)
int modInv(int a, int n) {
	return ((egcd(a, n).first % n) + n) % n;
}


/*       Same thing but with long long instead of ints         */

typedef long long ll;
typedef pair<ll, ll> pll;

// Finds constants {u, v} s.t. a*u+b*v = 1
// Requires gcd(a, b) == 1
// Call with egcd(a, b)
pll egcd(ll a, ll b, pll x = {1, 0}, pll y = {0, 1}) {
	return (b == 1) ? y : egcd(b, a%b, y, {x.first-a/b*y.first, x.second-a/b*y.second});
}

// Finds x s.t. (a*x) % n == 1
// Assumes a is not zero divisor (i.e. gcd(a, n) == 1)
ll modInv(ll a, ll n) {
	return ((egcd(a, n).first % n) + n) % n;
}