def rot(S):
	return list(zip(*S[::-1]))
def find_left_top(S):
	for i in range(N):
		for j in range(N):
			if S[i][j]=='#':
				return i,j
def is_same(S,T):
	Si,Sj = find_left_top(S)
	Ti,Tj = find_left_top(T)
	offset_i = Ti-Si
	offset_j = Tj-Sj
	for i in range(N):
		for j in range(N):
			ii = i+offset_i
			jj = j+offset_j
			if 0<=ii<N and 0<=jj<N:
				if S[i][j]!=T[ii][jj]: return False
			else:
				if S[i][j]=='#': return False
	return True
N = int(input())
S = [input() for _ in range(N)]
T = [input() for _ in range(N)]
cntS = sum(1 for i in range(N) for j in range(N) if S[i][j]=='#')
cntT = sum(1 for i in range(N) for j in range(N) if T[i][j]=='#')
if cntS != cntT:
	print("No")
	exit()
for _ in range(4):
	if is_same(S,T):
		print("Yes")
		exit()
	S = rot(S)
print("No")