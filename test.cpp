class Solution {
private:
	bool DFS(vector<vector<char>>& board, string &word, int i, int j, int p, int m, int n)
	{
        char tmp;
        bool res=false;
        if((tmp=board[i][j])!=word[p])
            return false;
		if (p == word.size()-1)
			return true;
		
		board[i][j] = '1';

		if (i > 0)
			if (DFS(board, word, i - 1, j, p + 1, m, n))
				return true;

		if (i + 1<m)
			if (DFS(board, word, i + 1, j, p + 1, m, n))
				return true;

		if (j>0)
			if (DFS(board, word, i, j-1, p + 1, m, n))
				return true;

		if (j + 1<n)
			if (DFS(board, word, i, j + 1, p + 1, m, n))
				return true;

		board[i][j] = tmp;
		return false;
	}
public:
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		if (m == 0)
			return false;
		if (word.size() == 0)
			return false;
		int n = board[0].size();

		if (m*n < word.size())
			return false;
		int p = 0;
		char tmp;
		bool res = false;

		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				if (word.size() == 1 && board[i][j] == word[0])
					return true;
				if (DFS(board, word, i, j, 0, m, n))
					return true;
			}
		}

		return false;

	}
};
